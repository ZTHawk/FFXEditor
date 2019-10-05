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

#ifndef PROCESS_MNG_HPP
#define PROCESS_MNG_HPP

void FindProcess( );
void ProcClose( int handle );
int ProcOpen( int procID );
bool ProcReadMem( int handle , int address , void *buf , int len , int &bytesRead );
bool ProcWriteMem( int handle , int address , void *buf , int len , int &bytesWritten );

bool readFromProcess( int address , void *buf , int len );
int readIntFromProcess( int address , bool &result );
short readShortFromProcess( int address , bool &result );
unsigned char readByteFromProcess( int address , bool &result );
bool writeToProcess( int address , void *buf , int len );
bool writeIntToProcess( int address , int value );
bool writeShortToProcess( int address , short value );
bool writeByteToProcess( int address , unsigned char value );

#endif // PROCESS_MNG_HPP
