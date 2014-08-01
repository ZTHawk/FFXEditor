/*
    FFX-Editor is a cheat tool for PCSX2 and Final Fantasy X.

    Copyright (C) 2014  Karl Zmuda Trzebiatowski <karl.zmuda.trzebiatowski at gmail.com>

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

#ifndef MEM_MNG_HPP
#define MEM_MNG_HPP

class MemMng
{
public:
	MemMng( );
	~MemMng( );
	
	bool init( int procID );
	
	int read( int address , void *buf , int len );
	int readInt( int address , bool &result );
	short readShort( int address , bool &result );
	unsigned char readByte( int address , bool &result );
	bool write( int address , void *buf , int len );
	bool writeInt( int address , int value );
	bool writeShort( int address , short value );
	bool writeByte( int address , unsigned char value );
	
private:
	int hProcess;
};

extern MemMng *memMng;

#endif // MEM_MNG_HPP
