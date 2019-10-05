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

#ifndef OVERDRIVE_CONSTANTS_HPP
#define OVERDRIVE_CONSTANTS_HPP

#include <string>

using std::wstring;

#define OD_TIDUS_NAMES_SIZE 4
extern vector<wstring> odTidusNames;
static const char *odTidusNames_en =
	"Spiral Cut\\"
	"Slice & Dice\\"
	"Energy Rain\\"
	"Blitz Ace\\"
	"\0";

#define OD_AURON_NAMES_SIZE 4
extern vector<wstring> odAuronNames;
static const char *odAuronNames_en =
	"Dragon Fang\\"
	"Shooting Star\\"
	"Banishing Blade\\"
	"Tornado\\"
	"\0";

#define OD_WAKKA_NAMES_SIZE 4
extern vector<wstring> odWakkaNames;
static const char *odWakkaNames_en =
	"Element Reels\\"
	"Attack Reels\\"
	"Status Reels\\"
	"Aurochs Reels\\"
	"\0";

#define OD_KIMAHRI_NAMES_SIZE 12
extern vector<wstring> odKimahriNames;
static const char *odKimahriNames_en =
	"Jump\\"
	"Fire Breath\\"
	"Seed Cannon\\"
	"Self-Destruct\\"
	"Thrust-Kick\\"
	"Stone Breath\\"
	"Aqua Breath\\"
	"Doom\\"
	"White Wind\\"
	"Bad Breath\\"
	"Mighty Guard\\"
	"Nova"
	"\0";

#define OD_LULU_NAMES_SIZE 19
extern vector<wstring> odLuluNames;
static const char *odLuluNames_en =
	"Blizzard Fury\\"
	"Fire Fury\\"
	"Thunder Fury\\"
	"Water Fury\\"
	"Fira Fury\\"
	"Blizzara Fury\\"
	"Thundera Fury\\"
	"Watera Fury\\"
	"Firaga Fury\\"
	"Blizzaga Fury\\"
	"Thundaga Fury\\"
	"Waterga Fury\\"
	"Bio Fury\\"
	"Demi Fury\\"
	"Death Fury\\"
	"Drain Fury\\"
	"Osmose Fury\\"
	"Flare Fury\\"
	"Ultima Fury"
	"\0";

#define OD_RIKKU_NAMES_SIZE 64
extern vector<wstring> odRikkuNames;
static const char *odRikkuNames_en =
	"Grenade\\"
	"Frag Grenade\\"
	"Pineapple\\"
	"Potato Masher\\"
	"Cluster Bomb\\"
	
	"Tallboy\\"
	"Blaster Mine\\"
	"Hazardous Shell\\"
	"Calamity Bomb\\"
	"Chaos Grenade\\"
	"Heat Blaster\\"
	"Firestorm\\"
	"Burning Soul\\"
	
	"Brimstone\\"
	"Abaddon Flame\\"
	"Snow Flurry\\"
	"Icefall\\"
	"Winter Storm\\"
	"Black Ice\\"
	"Krysta\\"
	"Thunderbolt\\"
	
	"Rolling Thunder\\"
	"Lightning Bolt\\"
	"Electro Shock\\"
	"Thunder Blast\\"
	"Waterfall\\"
	"Flash Flood\\"
	"Tidal Wave\\"
	"Aqua Toxin\\"
	
	"Dark Rain\\"
	"Nega Burst\\"
	"Black Hole\\"
	"Sunburst\\"
	"Ultra Potion\\"
	"Panacea\\"
	"Ultra Cure\\"
	"Mega Phoenix\\"
	
	"Final Pheonix\\"
	"Elixir\\"
	"Megalixir\\"
	"Super Elixir\\"
	"Final Elixir\\"
	"NulAll\\"
	"Mega NulAll\\"
	"Hyper NulAll\\"
	
	"Ultra NulAll\\"
	"Mighty Wall\\"
	"Mighty G\\"
	"Super Mighty G\\"
	"Hyper Mighty G\\"
	"Vitality\\"
	"Mega Vitality\\"
	"Hyper Vitality\\"
	
	"Mana\\"
	"Mega Mana\\"
	"Hyper Mana\\"
	"Freedom\\"
	"Freedom X\\"
	"Quartet of 9\\"
	"Trio of 9999\\"
	"Hero Drink\\"
	
	"Miracle Drink\\"
	"Hot Spurs\\"
	"Eccentrick"
	"\0";

#endif // OVERDRIVE_CONSTANTS_HPP
