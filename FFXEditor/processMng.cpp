#include "processMng.hpp"
#include "constants.hpp"
#include "globals.hpp"
#include "utils.hpp"
#include "logManager.hpp"
#include "string_helper.hpp"

#include "windows.h"
#include "Psapi.h"

#define ACCESS_RIGHTS \
	(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_QUERY_INFORMATION)

bool EnablePriv( LPCWSTR lpszPriv );
BOOL CALLBACK EnumWindowsHandle( HWND hWnd , LPARAM lParam );

void FindProcess( )
{
	EnablePriv(SE_DEBUG_NAME);
	EnumWindows(EnumWindowsHandle, 0);
}

void ProcClose( int handle )
{
	CloseHandle(reinterpret_cast<HANDLE>(handle));
}

int ProcOpen( int procID )
{
	return reinterpret_cast<int>(OpenProcess(PROCESS_ALL_ACCESS, false, procID));
}

bool ProcReadMem( int handle , int address , void *buf , int len , int &bytesRead )
{
	return ReadProcessMemory(reinterpret_cast<HANDLE>(handle),
		reinterpret_cast<void*>(address),
		buf, len, reinterpret_cast<SIZE_T*>(&bytesRead));
}

bool ProcWriteMem( int handle , int address , void *buf , int len , int &bytesWritten )
{
	return WriteProcessMemory(reinterpret_cast<HANDLE>(handle),
		reinterpret_cast<void*>(address),
		buf, len, reinterpret_cast<SIZE_T*>(&bytesWritten));
}

bool EnablePriv( LPCWSTR lpszPriv ) // by Napalm
{
	HANDLE hToken;
	LUID luid;
	TOKEN_PRIVILEGES tkprivs;
	memset(&tkprivs, 0, sizeof(tkprivs));
	
	(*logManager)(LogManager::LOG_WARNING)
		<< L"Setting privileges for pid="
		<< reinterpret_cast<int>(GetCurrentProcess())
		<< LogManager::endl;
	
	if ( OpenProcessToken(GetCurrentProcess(), (TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY), &hToken) == false )
	{
		(*logManager)(LogManager::LOG_WARNING)
			<< L"  Could not open tokens.\n"
			<< L"  Error="
			<< static_cast<int>(GetLastError())
			<< LogManager::endl;
		return false;
	}
	
	if ( LookupPrivilegeValue(NULL, lpszPriv, &luid) == false )
	{
		CloseHandle(hToken);
		(*logManager)(LogManager::LOG_WARNING)
			<< L"  Could not lookup privileges.\n"
			<< L"  Error="
			<< static_cast<int>(GetLastError())
			<< LogManager::endl;
		return false;
	}
	
	tkprivs.PrivilegeCount = 1;
	tkprivs.Privileges[0].Luid = luid;
	tkprivs.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	
	bool bRet = AdjustTokenPrivileges(hToken, false, &tkprivs, sizeof(tkprivs), NULL, NULL);
	CloseHandle(hToken);
	
	(*logManager)(LogManager::LOG_WARNING)
		<< L"Adjusted privileges with Error="
		<< static_cast<int>(GetLastError())
		<< LogManager::endl;
	
	return bRet;
}

BOOL CALLBACK EnumWindowsHandle( HWND hWnd , LPARAM lParam )
{
	const int bufferSize = 100;
    TCHAR fileName[bufferSize];
	TCHAR windowText[bufferSize];
	TCHAR wm_Text[bufferSize];
	memset(fileName, 0, sizeof(TCHAR) * bufferSize);
	memset(windowText, 0, sizeof(TCHAR) * bufferSize);
	memset(wm_Text, 0, sizeof(TCHAR) * bufferSize);
	
	if ( hWnd == 0 )
		return true;
	
	(*logManager)(LogManager::LOG_WARNING)
		<< L"New item: "
		<< reinterpret_cast<int>(hWnd);
	
	if ( IsWindowVisible(hWnd) == false )
		return true;
	
	(*logManager)(LogManager::LOG_WARNING)
		<< L"  Visible";
	
	if ( SendMessage(hWnd, WM_GETTEXT, bufferSize, (LPARAM)wm_Text) == false )
		return true;
	
	DWORD dwProcessId = 0;
	DWORD dwThreadId = GetWindowThreadProcessId(hWnd, &dwProcessId);
	HANDLE hProcess = OpenProcess(ACCESS_RIGHTS, false, dwProcessId);
	
	(*logManager)(LogManager::LOG_WARNING)
		<< L"  WM=\""
		<< wm_Text
		<< L"\" with pid="
		<< static_cast<int>(dwProcessId)
		<< L" and with handle="
		<< reinterpret_cast<int>(hProcess)
		<< L"\n    Error="
		<< static_cast<int>(GetLastError())
		<< LogManager::endl;
	
	if ( hProcess == 0 )
		return true;
	
	GetModuleBaseName(hProcess, NULL, (LPWSTR)fileName, bufferSize);
	CloseHandle(hProcess);
	
	(*logManager)(LogManager::LOG_WARNING)
		<< L"  Filename=\""
		<< fileName
		<< L"\""
		<< L"\n    Error="
		<< static_cast<int>(GetLastError())
		<< LogManager::endl;
	
	if ( GetWindowText(hWnd, (LPWSTR)windowText, bufferSize) == 0 )
		return true;
    
	bool isUnicode = false;
#if defined UNICODE
	isUnicode = true;
#endif
	(*logManager)(LogManager::LOG_WARNING)
		<< L"  WT=\""
		<< windowText
		<< L"\""
		<< LogManager::endl;
	
	char *c = strstrCaseIn(reinterpret_cast<char*>(fileName), emulatorName, isUnicode);
	if ( c == NULL )
		return true;
	
	emulatorProcessID = static_cast<int>(dwProcessId);
	(*logManager)(LogManager::LOG_WARNING)
		<< L"  found: "
		<< emulatorProcessID
		<< LogManager::endl;
	
    return true;
}

bool readFromProcess( int address , void *buf , int len )
{
	if ( buf == NULL )
		return false;
	
	if ( len < 1 )
		return false;
	
	if ( emulatorProcessID == -1 )
		return false;
	
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, emulatorProcessID);
	if ( hProcess == 0 )
		return false;
	
	SIZE_T bytesRead = 0;
	bool result = ReadProcessMemory(hProcess, (void*)address, buf, len, &bytesRead);
	CloseHandle(hProcess);
	if ( result == false )
		return false;
	
	if ( buf == NULL )
		return false;
	
	if ( bytesRead < static_cast<SIZE_T>(len) )
		return false;
	
	return true;
}

int readIntFromProcess( int address , bool &result )
{
	int value = 0;
	result &= readFromProcess(address, &value, 4);
	return value;
}
short readShortFromProcess( int address , bool &result )
{
	short value = 0;
	result &= readFromProcess(address, &value, 2);
	return value;
}

unsigned char readByteFromProcess( int address , bool &result )
{
	unsigned char value = 0;
	result &= readFromProcess(address, &value, 1);
	return value;
}

bool writeToProcess( int address , void *buf , int len )
{
	if ( buf == NULL )
		return false;
	
	if ( len < 1 )
		return false;
	
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, emulatorProcessID);
	if ( hProcess == 0 )
		return false;
	
	SIZE_T bytesWritten = 0;
	bool result = WriteProcessMemory(hProcess, (void*)address, buf, len, &bytesWritten);
	CloseHandle(hProcess);
	if ( result == false )
		return false;
	
	if ( bytesWritten < static_cast<SIZE_T>(len) )
		return false;
	
	return true;
}

bool writeIntToProcess( int address , int value )
{
	return writeToProcess(address, &value, 4);
}

bool writeShortToProcess( int address , short value )
{
	return writeToProcess(address, &value, 2);
}

bool writeByteToProcess( int address , unsigned char value )
{
	return writeToProcess(address, &value, 1);
}