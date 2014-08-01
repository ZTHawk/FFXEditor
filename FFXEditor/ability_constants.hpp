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

#ifndef ABILITY_CONSTANTS_HPP
#define ABILITY_CONSTANTS_HPP

#include <string>

using std::wstring;

#define ABILITY_NAMES_SIZE 96
extern vector<wstring> abilityNames;
static const char *abilityNames_en =
	"Normal Attack\\"
	"Item Menu\\"
	"Switch Player\\"
	"Escape\\"
	"Switch Weapon\\"
	"Switch Armor\\"
	"Delay Attack\\"
	"Delay Buster\\"
	"Sleep Attack\\"
	"Silence Attack\\"
	"Dark Attack\\"
	"Zombie Attack\\"
	"Sleep Buster\\"
	"Silence Buster\\"
	"Dark Buster\\"
	"Triple Foul\\"
	"Power Break\\"
	"Magic Break\\"
	"Armor Break\\"
	"Mental Break\\"
	"Mug\\"
	"Quick Hit\\"
	"Steal\\"
	"Use\\"
	"Flee\\"
	"Pray\\"
	"Cheer\\"
	"Aim\\"
	"Focus\\"
	"Reflex\\"
	"Luck\\"
	"Jinx\\"
	
	"Lancet\\"
	"???\\" //"?? slot2 2\\"
	"Guard\\"
	"Sentinel\\"
	"Spare Change\\"
	"Threaten\\"
	"Provoke\\"
	"Entrust\\"
	"Copycat\\"
	"Doublecast\\"
	"Bribe\\"
	"Cure (White Magic)\\"
	"Cura (White Magic)\\"
	"Curaga (White Magic)\\"
	"Nul-Frost (White Magic)\\"
	"Nul-Blaze (White Magic)\\"
	"Nul-Shock (White Magic)\\"
	"Nul-Tide (White Magic)\\"
	"Scan (White Magic)\\"
	"Esuna (White Magic)\\"
	"Life (White Magic)\\"
	"Full-Life (White Magic)\\"
	"Haste (White Magic)\\"
	"Hastega (White Magic)\\"
	"Slow (White Magic)\\"
	"Slowga (White Magic)\\"
	"Shell (White Magic)\\"
	"Protect (White Magic)\\"
	"Reflect (White Magic)\\"
	"Dispel (White Magic)\\"
	"Regen (White Magic)\\"
	"Holy (White Magic)\\"
	
	"Auto-Life (White Magic)\\"
	"Blizzard (Black Magic)\\"
	"Fire (Black Magic)\\"
	"Thunder (Black Magic)\\"
	"Water (Black Magic)\\"
	"Fira (Black Magic)\\"
	"Blizzara (Black Magic)\\"
	"Thundara (Black Magic)\\"
	"Watera (Black Magic)\\"
	"Firaga (Black Magic)\\"
	"Blizzaga (Black Magic)\\"
	"Thundaga (Black Magic)\\"
	"Waterga (Black Magic)\\"
	"Bio (Black Magic)\\"
	"Demi (Black Magic)\\"
	"Death (Black Magic)\\"
	"Drain (Black Magic)\\"
	"Osmose (Black Magic)\\"
	"Flare (Black Magic)\\"
	"Ultima (Black Magic)\\"
	"Aeon: Shield\\"
	"Aeon: Boost\\"
	"Aeon: Dismiss\\"
	"Aeon: Dismiss Yojimbo\\"
	"Pilfer Gil\\"
	"All Break\\"
	"Extract Power\\"
	"Extract Mana\\"
	"Extract Speed\\"
	"Extract Ability\\"
	"Nab Gil\\"
	"Quick Pockets"
	"\0";

#endif // ABILITY_CONSTANTS_HPP
