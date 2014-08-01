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

#ifndef WEAPON_DATA_HPP
#define WEAPON_DATA_HPP

#include <string>
#include <vector>

using std::wstring;
using std::vector;

#define WEAPON_MAX_SIZE 200
#pragma pack(push, before_weapon_struct)
#pragma pack(1)
typedef struct _WEAPONDATA
{
	unsigned char id;
	unsigned char id2;
	unsigned char available;
	unsigned char special_properties;
	unsigned char destinationCharID;
	unsigned char isArmor;
	unsigned char equippedCharID;
	unsigned char dummy_07;
	unsigned char damageFormula;
	unsigned char attackPower;
	unsigned char critHit;
	unsigned char slotCnt;
	unsigned short skin;
	unsigned char slot1_ability;
	unsigned char slot1_used;
	unsigned char slot2_ability;
	unsigned char slot2_used;
	unsigned char slot3_ability;
	unsigned char slot3_used;
	unsigned char slot4_ability;
	unsigned char slot4_used;
}WEAPONDATA, *PWEAPONDATA;
#pragma pack(pop, before_weapon_struct)

class WeaponData
{
public:
	PWEAPONDATA data;
	
	bool error;
	int curSize; /* amount of currently available weapons*/
	
	WeaponData( );
	~WeaponData( );
	
	bool cheackData( );
	bool readData( );
	bool writeData( );
	bool validWeaponSlot( int index );
	wstring getWeaponName( int index );
};

#endif // WEAPON_DATA_HPP
