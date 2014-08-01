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

#ifndef ITEM_DATA_HPP
#define ITEM_DATA_HPP

#pragma pack(push, before_item_struct)
#pragma pack(1)
typedef struct _ITEM_ID_LIST
{
	unsigned char itemID;
	unsigned char bitmask;
}ITEM_ID_LIST, *PITEM_ID_LIST;
#pragma pack(pop, before_item_struct)

class ItemData
{
public:
	PITEM_ID_LIST itemIDList;
	unsigned char *itemAmountList;
	unsigned char *keyItems;
	unsigned char al_bhed_primer_counter;
	unsigned int al_bhed_primer_bitmask;
	
	bool error;
	
	ItemData( );
	~ItemData( );
	
	void selectKeyItem( unsigned char index , bool selected );
	bool isKeyItemSelect( int index );
	
	bool cheackData( );
	bool readData( );
	bool writeData( );
};

#endif // ITEM_DATA_HPP
