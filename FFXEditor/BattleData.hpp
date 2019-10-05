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

#ifndef BATTLE_DATA_HPP
#define BATTLE_DATA_HPP

typedef struct _BATTLEDATA
{
	unsigned char animSpeed;
	unsigned char standAtLocation;
	unsigned char runToLocation;
	char nameBytes[200];
	
	unsigned int hp_max;
	unsigned int mp_max;
	unsigned char overdrive;
	unsigned char deathCountDown;
	unsigned int hp;
	unsigned int mp;
	unsigned short conditionMask;
	unsigned char sleepCnt;
	unsigned char silenceCnt;
	unsigned char shellCnt;
	unsigned char protectCnt;
	unsigned char reflectCnt;
	unsigned char waterImmunityCnt;
	unsigned char fireImmunityCnt;
	unsigned char lightningImmunityCnt;
	unsigned char iceImmunityCnt;
	unsigned char regenCnt;
	unsigned char hasteCnt;
	unsigned char slowCnt;
	unsigned short conditionMask2;
	unsigned char turnsTillAction;
	unsigned char battleActivity;
}BATTLEDATA, *PBATTLEDATA;

class BattleData
{
public:
	PBATTLEDATA data;
	bool error;
	
	BattleData( int addressInit , int address );
	~BattleData( );
	
	bool cheackData( );
	bool readData( );
	bool writeData( );
	int getInitAdr( );
	
private:
	int address;
	int addressInit;
};

#endif // BATTLE_DATA_HPP
