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

#ifndef UTILS_HPP
#define UTILS_HPP

#include "iostream"
#include <string.h>
#include <vector>

#include <QPoint>
#include <QString>

using std::wstring;
using std::vector;

void SendNotification( QString msg );
void SendNotification( char *msg );
void SendNotificationID( int msgID );

char* strstrCaseIn( char *str1 , const char *str2 , bool isUnicode = false );
bool containsNoneDigits( const char *text );

bool stringToValue_Check( const char *text , void *buf , unsigned int numByType );

void setBitmask( unsigned int &target , unsigned int mask , bool set );
void setBitmask( unsigned char &target , unsigned char mask , bool set );

unsigned int findOffsetOfByteArray( const unsigned char byteArray[] , const int byteArrayLen , unsigned int searchOffset = 0x02000000 , unsigned int searchOffsetEnd = 0x3FFFFFFF );

void parseCharArrayToStringVector( const char *charArray , vector<wstring> &stringVec );

wstring asciiFFX_ascii( char *str );
unsigned char* ascii_asciiFFX( wstring str );

#endif // UTILS_HPP
