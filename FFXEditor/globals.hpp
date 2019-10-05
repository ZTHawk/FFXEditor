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

#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include "nameIdData.hpp"
#include <string>
#include <vector>

using std::wstring;
using std::vector;

extern int emulatorProcessID;

extern unsigned int BASE_OFFSET;
extern unsigned int BASE_OFFSET_BASE;
extern unsigned int BASE_OFFSET_SPECIAL;

extern unsigned int langVersion;

class FFXEditor;
extern FFXEditor *mainWindow;

class LogManager;
extern LogManager *logManager;

extern vector<wstring> abilityNames;

extern vector<wstring> odRikkuNames;
extern vector<wstring> odLuluNames;
extern vector<wstring> odKimahriNames;
extern vector<wstring> odWakkaNames;
extern vector<wstring> odAuronNames;
extern vector<wstring> odTidusNames;

extern vector<wstring> damageTypeNames;
extern vector<wstring> weaponNames;
extern vector<wstring> weaponAbilityNames;
extern vector<NameIdData> wModelNames;

extern vector<wstring> infoList;

extern vector<wstring> itemNames;
extern vector<wstring> keyItemNames;

union WeapOwnerData
{
	int iVal;
	struct
	{
		unsigned char charID;
		unsigned char weaponSlotIndex;
		unsigned char isArmor;
		unsigned char dummy;
	};
};

#endif // GLOBALS_HPP
