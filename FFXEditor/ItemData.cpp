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
	
	result &= memMng->read(BASE_OFFSET + OFFSET_ITEMS_ID_LIST, itemIDList, sizeof(ITEM_ID_LIST) * 256);
	result &= memMng->read(BASE_OFFSET + OFFSET_ITEMS_AMOUNT_LIST, itemAmountList, sizeof(unsigned char) * 256);
	result &= memMng->read(BASE_OFFSET + OFFSET_KEY_ITEM_BITMASK, keyItems, sizeof(unsigned char) * 7);
	
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
