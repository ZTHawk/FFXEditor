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

#include "OverdriveData.hpp"
#include "globals.hpp"
#include "MemMng.hpp"
#include "offsets.hpp"
#include "weapon_constants.hpp"

OverdriveData::OverdriveData( )
{
	overdrive_list = new unsigned int[4];
	
	error = false;
}

OverdriveData::~OverdriveData( )
{
	delete overdrive_list;
}

bool OverdriveData::cheackData( )
{
	return (error == false);
}

bool OverdriveData::readData( )
{
	bool result = memMng->read(BASE_OFFSET + OFFSET_OVERDRIVES_BITMASK, overdrive_list, sizeof(unsigned int) * 4) != -1;
	
	return result;
}

bool OverdriveData::writeData( )
{
	bool result = memMng->write(BASE_OFFSET + OFFSET_OVERDRIVES_BITMASK, overdrive_list, sizeof(unsigned int) * 4);
	
	return result;
}
