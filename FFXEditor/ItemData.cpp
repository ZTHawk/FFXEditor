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

#include "ItemData.hpp"
#include "globals.hpp"
#include "MemMng.hpp"
#include "offsets.hpp"
#include "utils.hpp"
#include "item_constants.hpp"

ItemData::ItemData( )
{
	itemIDList = new ITEM_ID_LIST[256];
	memset(itemIDList, 0, sizeof(ITEM_ID_LIST) * 256);
	
	itemAmountList = new unsigned char[256];
	memset(itemAmountList, 0, sizeof(unsigned char) * 256);
	
	keyItems = new unsigned char[7];
	memset(keyItems, 0, sizeof(unsigned char) * 7);
	
	al_bhed_primer_counter = 0;
	al_bhed_primer_bitmask = 0;
	
	error = false;
}

ItemData::~ItemData( )
{
	delete itemIDList;
	delete itemAmountList;
	delete keyItems;
}

void ItemData::selectKeyItem( unsigned char index , bool selected )
{
	char slot = index / 8;
	unsigned char mask = 1 << (index % 8);
	if ( selected == true )
	{
		if ( index >= 4
			&& index <= 29 )
		{
			++al_bhed_primer_counter;
			
			unsigned int newmask = 1 << (index - 4);
			al_bhed_primer_bitmask |= newmask;
		}
	}
	
	setBitmask(keyItems[slot], mask, selected);
}

bool ItemData::isKeyItemSelect( int index )
{
	unsigned char slotMask = keyItems[index / 8];
	unsigned char checkMask = 1 << (index % 8);
	return ((slotMask & checkMask) > 0);
}

bool ItemData::cheackData( )
{
	al_bhed_primer_counter = 0;
	al_bhed_primer_bitmask = 0;
	return (error == false);
}

bool ItemData::readData( )
{
	bool result = true;
	
	memset(itemIDList, 0, sizeof(ITEM_ID_LIST) * 256);
	memset(itemAmountList, 0, sizeof(unsigned char) * 256);
	memset(keyItems, 0, sizeof(unsigned char) * 7);
	
	result &= memMng->read(BASE_OFFSET + OFFSET_ITEMS_ID_LIST, itemIDList, sizeof(ITEM_ID_LIST) * 256) != -1;
	result &= memMng->read(BASE_OFFSET + OFFSET_ITEMS_AMOUNT_LIST, itemAmountList, sizeof(unsigned char) * 256) != -1;
	result &= memMng->read(BASE_OFFSET + OFFSET_KEY_ITEM_BITMASK, keyItems, sizeof(unsigned char) * 7) != -1;
	
	return result;
}

bool ItemData::writeData( )
{
	bool result = true;
	
	result &= memMng->write(BASE_OFFSET + OFFSET_ITEMS_AMOUNT_LIST,
		itemAmountList,
		sizeof(unsigned char) * 256);
	
	result &= memMng->write(BASE_OFFSET + OFFSET_ITEMS_ID_LIST,
		itemIDList,
		sizeof(ITEM_ID_LIST) * 256);
	
	result &= memMng->write(BASE_OFFSET + OFFSET_KEY_ITEM_BITMASK,
		keyItems,
		sizeof(unsigned char) * 7);
	
	result &= memMng->writeByte(BASE_OFFSET + OFFSET_KEYITEM_BOUQUET,
		((keyItems[0] & KEY_ITEM_WITHERED_BOUQUET) == 0) ? 0 : 1);
	result &= memMng->writeByte(BASE_OFFSET + OFFSET_KEYITEM_FLINT,
		((keyItems[0] & KEY_ITEM_FLINT) == 0) ? 0 : 1);
	
	result &= memMng->writeByte(BASE_OFFSET + OFFSET_AL_BHED_PRIMER_COUNTER,
		al_bhed_primer_counter);
	
	result &= memMng->writeInt(BASE_OFFSET + OFFSET_AL_BHED_PRIMER_BITMASK,
		al_bhed_primer_bitmask);
	
	return result;
}
