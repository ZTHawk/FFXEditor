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

int MemMng::read( int address , void *buf , int len )
{
	static int bytesRead = 0;
	static bool result;
	if ( buf == NULL )
		return -1;
	if ( len < 1 )
		return -1;
	if ( hProcess == 0 )
		return -1;
	result = ProcReadMem(hProcess, address, buf, len, bytesRead);
	if ( result == false )
		return -1;
	return bytesRead;
}

int MemMng::readInt( int address , bool &result )
{
	static int value;
	value = 0;
	result &= read(address, &value, 4) != -1;
	return value;
}

short MemMng::readShort( int address , bool &result )
{
	static short value;
	value = 0;
	result &= read(address, &value, 2) != -1;
	return value;
}

unsigned char MemMng::readByte( int address , bool &result )
{
	static unsigned char value;
	value = 0;
	result &= read(address, &value, 1) != -1;
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
