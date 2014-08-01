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

#ifndef INFO_HPP
#define INFO_HPP

#include <vector>
#include <string.h>

using std::wstring;
using std::vector;

enum INFO
{
	INFO_ERR_NO_FFX_DATA,
	INFO_ERR_CHK_CHAR_DATA,
	INFO_ERR_CHK_AEON_DATA,
	INFO_GLOBAL,
	INFO_ATTACK,
	INFO_DEFENSE = INFO_ATTACK,
	INFO_MAGIC = INFO_ATTACK,
	INFO_MAGIC_DEF = INFO_ATTACK,
	INFO_SPEED = INFO_ATTACK,
	INFO_LUCK = INFO_ATTACK,
	INFO_EVADE = INFO_ATTACK,
	INFO_HIT = INFO_ATTACK,
	INFO_HP,
	INFO_MP,
	INFO_AP,
	INFO_AP_NEXT,
	INFO_OVERDRIVE,
	INFO_S_LV,
	INFO_WEAPON,
	INFO_ARMOR,
	INFO_BATTLES,
	INFO_ENEMYS,
	INFO_DEATHS,
	INFO_OVERDRIVE_MODES,
	INFO_OVERDRIVE_WARRIOR,
	INFO_OVERDRIVE_COMRADE,
	INFO_OVERDRIVE_HEALER,
	INFO_OVERDRIVE_TACTICIAN,
	INFO_OVERDRIVE_VICTIM,
	INFO_OVERDRIVE_DANCER,
	INFO_OVERDRIVE_AVENGER,
	INFO_OVERDRIVE_SLAYER,
	INFO_OVERDRIVE_HERO,
	INFO_OVERDRIVE_ROOK,
	INFO_OVERDRIVE_VICTOR,
	INFO_OVERDRIVE_COWARD,
	INFO_OVERDRIVE_ALLY,
	INFO_OVERDRIVE_SUFFERER,
	INFO_OVERDRIVE_DAREDEVIL,
	INFO_OVERDRIVE_SOLO,
	INFO_ABILITY,
	INFO_ITEMS,
	INFO_KEY_ITEMS,
	INFO_AEON_ATTACK,
	INFO_AEON_DEFENSE = INFO_AEON_ATTACK,
	INFO_AEON_MAGIC = INFO_AEON_ATTACK,
	INFO_AEON_MAGIC_DEF = INFO_AEON_ATTACK,
	INFO_AEON_SPEED = INFO_AEON_ATTACK,
	INFO_AEON_LUCK = INFO_AEON_ATTACK,
	INFO_AEON_EVADE = INFO_AEON_ATTACK,
	INFO_AEON_HIT = INFO_AEON_ATTACK,
	INFO_AEON_HP,
	INFO_AEON_MP,
	INFO_AEON_ENEMYS,
	INFO_AEON_DEATHS,
	INFO_AEON_BATTLES_REVIVE,
	INFO_WEAP_MODELS,
	INFO_BATTLE,
	INFO_BATTLE_HP,
	INFO_BATTLE_MP,
	INFO_BATTLE_OD,
	INFO_BATTLE_STATUS,
	INFO_BATTLE_COND,
	INFO_BATTLE_TURN_ACTION,
	INFO_BATTLE_DEATH_CD,
	INFO_BATTLE_ANIM,
	INFO_BATTLE_STAND_AT,
	INFO_BATTLE_RUN_TO,
};

extern vector<wstring> infoList;
static const char *infoList_en =
	"Error finding FFX data.\\"
	"Some variables in Characters tab are incorrect and marked Red. Please fix them.\\"
	"Some variables in Aeons tab are incorrect and marked Red. Please fix them.\\"
	"This box shows additional info. Just click a text to get more information about it.\n"
		"Do not use this while in a battle. Wait untill the fight is over, then hit \"Reload\" and modify as you wish.\n"
		"\"Section\" and normal button are equal except for characters/aeons/enemys. In that case only the specific data is reloaded/saved with normal button.\\"
	"MaxValue: " STR(DATA_ATTRIBUTE) "\nThe \"Basic\" value is the initial character value.\n"
		"\"Current\" shows your current attack including Sphere settings.\n"
		"Modifying \"Current\" does not do anything. It is updated once you enter Status menu.\\"
	"MaxValue: " STR(DATA_HP) "\n\"Cur\" are your actual HP.\n"
		"\"Max\" defines how many HP you can have.\n"
		"\"Base\" defines the default max HP you have without upgrades.\n"
		"Note: If \"Base\" is lower than \"Max\" then \"Max\" will be reseted to \"Base\"\\"
	"MaxValue: " STR(DATA_MP) "\n\"Cur\" are your actual MP.\n"
		"\"Max\" defines how many MP you can have.\n"
		"\"Base\" defines the default max MP you have without upgrades.\n"
		"Note: If \"Base\" is lower than \"Max\" then \"Max\" will be reseted to \"Base\"\\"
	"This value represents the AP you earned till now.\n"
		"Modifying this value does not increase S Lv\\"
	"This is NOT the amount of AP you need till next S.Lv but the amount you got on your way till next S.Lv.\n"
		"This is like a bank acount: Once this value is bigger than the amount needed till next S.Lv.\n"
		"It will be substracted from this value and you get one S.Lv.\n"
		"So if this value is pretty high you can get many S.Lv.\\"
	"MaxValue: " STR(DATA_ATTRIBUTE) "\n\"Current\" show the current Overdrive Points.\n"
		"\"Max\" defines how many points are needed till Overdrive is available.\n"
		"Modifying the value \"Max\" is not recommended as is can result not being able use Overdrives untill you switch it back.\n"
		"But you can set \"Current\" to 200 so you can execute two Overdrives. (This only works once. Use FFX Editor again)\\"
	"MaxValue: " STR(DATA_ATTRIBUTE) "\n\"Current\" defines how many S Lv points you have left.\n"
		"\"Used\" defines how many points you have spent.\\"
	"Determines which weapon is equiped.\nCurrently not available.\\"
	"Determines which armor is equiped.\nCurrently not available.\\"
	"Determines how many battles you encountered.\n"
		"Winning and escaping increases this value.\\"
	"Determines how many enemys this character has killed.\n"
		"Only the final hit counts.\\"
	"Determines how often you died.\\"
	
	"Determine how often you have to perform the required action to gain this Overdrive Mode.\n"
		"Once it reaches 0 (zero) you will learn this mode.\n"
		"Learning this mode directly by setting this to 0 (zero) does not work. So set the value to at least 1 (one).\\"
	"Deal damage to enemys.\\"
	"Other party members have to get damaged.\\"
	"Heal other party members. (Speels or items)\\"
	"Inflict a condition on enemys.\\"
	"Enemy hits you with a condition.\\"
	"Evade enemy attacks.\\"
	"One of your party members gets killed.\\"
	"Killing enemys.\\"
	"Killing enemys with high HP.\\"
	"Reduce or nullify damage you get from enemys.\n(Shell, Protect, ...)\\"
	"Win battles.\\"
	"Escape from battles.\\"
	"Your turn.\\"
	"Your turn while suffering from a condition.\\"
	"Your turn while low on HP. (yellow HP)\\"
	"Your turn while you are the only person able to fight.\n"
		"Your other party members either have to die or escape from battle.\\"
	
	"Determine which abilitys shall be available.\n"
		"Abilitys with ??? are unknown.\n"
		"Abilitys named \"Aeon:\" are not recommended for normal Characters (Reason: possible crash).\n"
		"Attention with giving player abilitys to Aeons. This can lead to wierd results and making the game unplayable. (fun only)\\"
	
	"MaxValue: 99\nItems are ordered the same way they are ingame.\n"
		"If you want more item slots, reorder one item to the very bottom of the list and hit \"Reload\"\\"
	"This is the list of the Key Items.\n"
		"Options starting with \"XX\" will be ignored. They would be visible in the list, but not recognized by the game.\n"
		"Options starting with \"??\" are currently not tested if game accepts them.\\"
	
	"MaxValue: " STR(DATA_ATTRIBUTE) "\n\"Current\" shows your current attack.\n"
		"\"Add\" defines how many points have been added to this attribute.\n"
		"It is updated once you enter Status menu.\\"
	"MaxValue: " STR(DATA_HP) "\n\"Cur\" are your actual HP.\n"
		"\"Max\" defines how many HP that aeon can have.\n"
		"\"Add\" defines how many HP have been added.\n"
		"Info: Reviving a dead aeon by increasing the HP will also need to reset \"Battles befor Revive\" value\\"
	"MaxValue: " STR(DATA_MP) "\n\"Cur\" are your actual MP.\n"
		"\"Max\" defines how many MP you can have.\n"
		"\"Add\" defines how many MP have been added.\\"
	"Determines how many enemys this aeon has killed.\n"
		"Only the final hit counts.\\"
	"Determines how often this aeon died.\\"
	"Determines how many battles you need to fight before this aeon can be sumoned again.\\"
	"Using \"Custom\" model index is dangerous. Save your game before editing.\n"
		"Some models will crash when entering a battle and others do when doing an attack.\\"
	
	"Be carful when using this.\n"
		"If using incorrectly your game may freeze, crash or become unplayable until you reset it.\n"
		"It is possible that characters are displayed twice. Make sure you modifying the correct one.\n"
		"Always reload data before changeing something.\n"
		"Some changes take effect once an actor gets in turn.\\"
	"Current and maximum HP.\\"
	"Current and maximum MP.\\"
	"Overdrive bar status.\n"
		"You can update it after each use to give immediate access to overdrives again.\\"
	"Specific the amount of turns this effect shall last.\n"
		"Character + enemy turn are decreasing this value.\n"
		"254 = Infinite turns. Effect can be removed with counterspells and items.\n"
		"255 = Infinite turns. Cannot be removed.\\"
	"Conditions have to be used carefully.\n"
		"Some only last until the actor is in turn again.\n"
		"Removing KO will not revive the actor and make resurrection impossible.\\"
	"Position in action bar.\n"
		"0 = Next turn is of this actor.\\"
	"In case of having the death countdown.\n"
		"This value defines value above the head.\n"
		"Amount of turns before death. Only own turns are counting.\\"
	"Animation speed: 0-14\n"
		"0 = No animation.\n"
		"14 = Very fast animation (including attacks).\n"
		"15 and above may freeze/crash the game.\\"
	"Teleport actor to specified position.\n"
		"255 is the initial value.\n"
		"You need to teleport to the original location (search: 1-15) and then set it to 255 to make \"Run to location\" to work.\\"
	"Makes the actor run to this position on battle field.\n"
		"Positions are predefined.\n"
		"\"Stand at location\" has to be 255 to make this work.\\"
	"\0";

#endif // INFO_HPP
