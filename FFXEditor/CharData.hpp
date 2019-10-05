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

#ifndef CHAR_DATA_HPP
#define CHAR_DATA_HPP

#pragma pack(push, before_struct)
#pragma pack(1)
typedef struct _CHARDATA
{
	unsigned int hp_base_max;
	unsigned int mp_base_max;
	unsigned char attributes_basic[8];
	unsigned int ap;
	unsigned int ap_next;
	unsigned int hp;
	unsigned int mp;
	unsigned int hp_max;
	unsigned int mp_max;

	unsigned char available;

	unsigned char weaponID;
	unsigned char shieldID;
	unsigned char attributes[8];

	unsigned char dummy_51;
	unsigned char overdrive_mode;

	unsigned char overdrive_points;
	unsigned char overdrive_points_needed;
	unsigned char s_lv;
	unsigned char s_lv_used;

	unsigned char battles_till_revive; // aeon

	unsigned int abilities[3];

	unsigned char dummy_70;
	unsigned char dummy_71;
	unsigned char dummy_72;
	unsigned char dummy_73;
	unsigned char dummy_74;
	unsigned char dummy_75;

	unsigned int battles_won;
	unsigned int enemys_killed;
	unsigned int deaths;
	unsigned int dummy_88;

	unsigned short overdrive_modes[17];
	unsigned char Adummy_01;
	unsigned char Adummy_02;
	unsigned char Adummy_03;
	unsigned char Adummy_04;
	unsigned char Adummy_05;
	unsigned char Adummy_06;
	unsigned char Adummy_07;
	unsigned char Adummy_08;
	unsigned char Adummy_09;
	unsigned char Adummy_10;
	unsigned char Adummy_11;
	unsigned char Adummy_12;
	unsigned char Adummy_13;
	unsigned char Adummy_14;
	unsigned char Adummy_15;
	unsigned char Adummy_16;
	unsigned char Adummy_17;
	unsigned char Adummy_18;
	unsigned char Adummy_19;
	unsigned char Adummy_20;
	unsigned char Adummy_21;
	unsigned char Adummy_22;
}CHARDATA, *PCHARDATA;
#pragma pack(pop, before_struct)

class CharData
{
public:
	CharData( int charID );
	~CharData( );
	
	int getID( ) { return charID; };
	bool cheackData( );
	bool readData( );
	bool writeData( );
	bool writeWeaponIDs_Data( );
	
	PCHARDATA data;
	bool error;
	
private:
	int charID;
};

#endif // CHAR_DATA_HPP
