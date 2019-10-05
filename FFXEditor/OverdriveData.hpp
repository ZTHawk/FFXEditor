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

#ifndef OVERDRIVE_DATA_HPP
#define OVERDRIVE_DATA_HPP

class OverdriveData
{
public:
	unsigned int *overdrive_list;
	bool error;
	
	OverdriveData( );
	~OverdriveData( );
	
	bool cheackData( );
	bool readData( );
	bool writeData( );
};

#endif // OVERDRIVE_DATA_HPP
