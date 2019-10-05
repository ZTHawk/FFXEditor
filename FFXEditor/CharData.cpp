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

#include "CharData.hpp"
#include "constants.hpp"
#include "globals.hpp"
#include "MemMng.hpp"
#include "offsets.hpp"

CharData::CharData( int charID )
{
	this->charID = charID;
	
	data = new CHARDATA;
	memset(data, 0, sizeof(CHARDATA));
	
	error = false;
}

CharData::~CharData( )
{
	delete data;
}

bool CharData::cheackData( )
{
	return (error == false);
}

bool CharData::readData( )
{
	bool result = memMng->read(BASE_OFFSET + char_offsets[charID], data, sizeof(CHARDATA)) != -1;
	
	return result;
}

bool CharData::writeData( )
{
	bool result = memMng->write(BASE_OFFSET + char_offsets[charID], data, sizeof(CHARDATA));
	
	return result;
}

bool CharData::writeWeaponIDs_Data( )
{
	bool result = memMng->write(BASE_OFFSET + char_offsets[charID] + 41, &data->weaponID, 2);
	
	return result;
}
