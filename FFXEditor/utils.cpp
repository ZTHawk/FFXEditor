/*
    FFX-Editor is a cheat tool for PCSX2 and Final Fantasy X.

    Copyright (C) 2014  Karol von Zmuda Trzebiatowski <karol.von.zmuda.trzebiatowski at gmail.com>

	This file is part of FFX-Editor.

    FFX-Editor is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FFX-Editor is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with FFX-Editor; if not, see <http://www.gnu.org/licenses/>.
*/

#include "constants.hpp"
#include "globals.hpp"
#include "MemMng.hpp"
#include "utils.hpp"
#include "ffxeditor.hpp"

#include <QPoint>
#include <QToolTip>

void SendNotification( QString msg )
{
	mainWindow->setInfo(msg);
}

void SendNotification( char *msg )
{
	SendNotification(QString(msg));
}

void SendNotificationID( int msgID )
{
	SendNotification(QString::fromStdWString(infoList[msgID]));
}

char* strstrCaseIn( char *str1 , const char *str2 , bool isUnicode )
{
	if ( str1 == NULL
		|| str2 == NULL )
		return NULL;
	
	if ( *str2 == 0 )
		return str1;
	
	char *s = str1,
		*s1 = str1;
	const char *s2 = str2;
	for ( ; *s != 0; ++s )
	{
		if ( tolower(*s) != tolower(*str2) )
		{
			if ( isUnicode == true
				&& (s - str1) % 2 == 0 )
			{
				// skip 0
				++s;
			}
			
			continue;
		}
		
		s1 = s;
		s2 = str2;
		for ( ; *s1 != 0 && *s2 != 0; ++s1, ++s2 )
		{
			if ( tolower(*s1) != tolower(*s2) )
				break;
			if ( isUnicode == true
				&& (s - s1) % 2 == 0 )
				++s1;
		}
		
		if ( *s2 == 0 )
			return s;
		if ( isUnicode == true
			&& (s - str1) % 2 == 0 )
		{
			// skip 0
			++s;
		}
	}
	
	return NULL;
}

bool containsNoneDigits( const char *text )
{
	const char *c = text;
	while ( *c != 0 )
	{
		if ( isdigit(*c) == false )
			return true;
		++c;
	}
	
	return false;
}

bool stringToValue_Check( const char *text , void *buf , unsigned int numByType )
{
	if ( containsNoneDigits(text) == true )
		return false;
	
	unsigned int val = atoi(text);
	if ( val > numByType )
		return false;
	
	if ( numByType <= DATA_UCHAR )
		*(char*)buf = (char)val;
	else if ( numByType <= DATA_USHORT )
		*(short*)buf = (short)val;
	else if ( numByType <= DATA_UINT )
		*(int*)buf = (int)val;
	
	return true;
}

void setBitmask( unsigned int &target , unsigned int mask , bool set )
{
	if ( set == true )
	{
		if ( (target & mask) == mask )
			return;
		
		target |= mask;
	}else
	{
		if ( (target & mask) == 0 )
			return;
		
		target &= ~mask;
	}
}

void setBitmask( unsigned char &target , unsigned char mask , bool set )
{
	if ( set == true )
	{
		if ( (target & mask) == mask )
			return;
		
		target |= mask;
	}else
	{
		if ( (target & mask) == 0 )
			return;
		
		target &= ~mask;
	}
}

unsigned int findOffsetOfByteArray( const unsigned char searchByteArray[] , int byteArrayLen , unsigned int searchOffset , unsigned int searchOffsetEnd )
{
	unsigned char byteArray[MAP_ARRAY_SIZE];
	bool skipping = false;
	int pos = 0,
		pos1 = 0,
		pos2 = 0,
		bytesRead;
	while ( searchOffset < searchOffsetEnd )
	{
		bytesRead = memMng->read(searchOffset, byteArray, MAP_ARRAY_SIZE);
		if ( bytesRead == -1 )
			break;
		
		for ( pos = 0; pos < bytesRead; ++pos )
		{
			if ( byteArray[pos] != searchByteArray[pos2] )
				continue;
			
			// +1 becaus we already checked the first one
			pos1 = pos + 1;
			for ( pos2 = 1; pos2 < byteArrayLen && pos1 < MAP_ARRAY_SIZE; ++pos2, ++pos1 )
			{
				if ( byteArray[pos1] != searchByteArray[pos2] )
					break;
			}
			
			if ( pos2 == byteArrayLen )
				return searchOffset + pos;
			else if ( pos1 == MAP_ARRAY_SIZE )
			{
				searchOffset += MAP_ARRAY_SIZE - pos2 - 1;
				pos2 = 0;
				skipping = true;
				break;
			}
			pos2 = 0;
		}
		
		if ( skipping == false )
			searchOffset += MAP_ARRAY_SIZE;
		skipping = false;
	}
	
	return 0;
}

void parseCharArrayToStringVector( const char *charArray , vector<wstring> &stringVec )
{
	int len = (__int32)strlen(charArray);
	wstring tmpStr = L"";
	for ( int i = 0; i < len; ++i )
	{
		if ( charArray[i] != '\\' )
		{
			tmpStr += charArray[i];
			continue;
		}else
		{
			stringVec.push_back(tmpStr);
			tmpStr.clear();
		}
	}
	if ( tmpStr.empty() == false )
		stringVec.push_back(tmpStr);
}

wstring asciiFFX_ascii( char *str )
{
	wstring newString = L"";
	int len = (__int32)strlen(str);
	unsigned char tmpC = 0;
	unsigned char *c = (unsigned char*)str;
	for ( int i = 0; i < len; ++i )
	{
		tmpC = 0;
		if ( *c >= 0x30
			&& *c <= 0x39 )
			tmpC = '0' + (*c - 0x30);
		else if ( *c >= 0x3A
			&& *c <= 0x49 )
			tmpC = ' ' + (*c - 0x3A);
		else if ( *c >= 0x4A
			&& *c <= 0x4F )
			tmpC = ':' + (*c - 0x4A);
		else if ( *c >= 0x50
			&& *c <= 0x8D )
			tmpC = 'A' + (*c - 0x50);
		
		++c;
		if ( tmpC != 0 )
			newString.push_back(*(char*)(&tmpC));
	}
	return newString;
}

unsigned char* ascii_asciiFFX( wstring str )
{
	int len = (__int32)str.length();
	unsigned char *newString = new unsigned char[len + 1];
	memset(newString, 0, len + 1);
	
	char c = 0;
	int pos = 0;
	for ( int i = 0; i < len; ++i )
	{
		c = str.at(i);
		if ( c >= ' '
			&& c <= '/' )
		{
			newString[pos] = 0x3A + (c - ' ');
			++pos;
		}else if ( c >= '0'
			&& c <= '9' )
		{
			newString[pos] = 0x30 + (c - '0');
			++pos;
		}else if ( c >= ':'
			&& c <= '?' )
		{
			newString[pos] = 0x4A + (c - ':');
			++pos;
		}else if ( c >= 'A'
			&& c <= '~' )
		{
			newString[pos] = 0x50 + (c - 'A');
			++pos;
		}
	}
	return newString;
}
