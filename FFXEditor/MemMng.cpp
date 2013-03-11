#include "MemMng.hpp"
#include "processMng.hpp"
#include "utils.hpp"

MemMng *memMng = NULL;

MemMng::MemMng( )
{
	hProcess = 0;
}

MemMng::~MemMng( )
{
	if ( hProcess != 0 )
		ProcClose(hProcess);
}

bool MemMng::init( int procID )
{
	if ( procID <= 0 )
		return false;
	
	hProcess = ProcOpen(procID);
	return (hProcess != 0);
}

bool MemMng::read( int address , void *buf , int len )
{
	static int bytesRead = 0;
	static bool result;
	if ( buf == NULL )
		return false;
	if ( len < 1 )
		return false;
	if ( hProcess == 0 )
		return false;
	result = ProcReadMem(hProcess, address, buf, len, bytesRead);
	if ( result == false )
		return false;
	if ( buf == NULL )
		return false;
	if ( bytesRead < len )
		return false;
	return true;
}

int MemMng::readInt( int address , bool &result )
{
	static int value;
	value = 0;
	result &= read(address, &value, 4);
	return value;
}

short MemMng::readShort( int address , bool &result )
{
	static short value;
	value = 0;
	result &= read(address, &value, 2);
	return value;
}

unsigned char MemMng::readByte( int address , bool &result )
{
	static unsigned char value;
	value = 0;
	result &= read(address, &value, 1);
	return value;
}

bool MemMng::write( int address , void *buf , int len )
{
	static int bytesWritten = 0;
	static bool result;
	if ( buf == NULL )
		return false;
	if ( len < 1 )
		return false;
	if ( hProcess == 0 )
		return false;
	result = ProcWriteMem(hProcess, address, buf, len, bytesWritten);
	if ( result == false )
		return false;
	if ( bytesWritten < len )
		return false;
	return true;
}

bool MemMng::writeInt( int address , int value )
{
	return write(address, &value, 4);
}

bool MemMng::writeShort( int address , short value )
{
	return write(address, &value, 2);
}

bool MemMng::writeByte( int address , unsigned char value )
{
	return write(address, &value, 1);
}
