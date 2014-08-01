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

#ifndef ITEM_CONSTANTS_HPP
#define ITEM_CONSTANTS_HPP

#include <string>

using std::wstring;

#define ITEM_NAMES_SIZE 113
extern vector<wstring> itemNames;
static const char *itemNames_en =
	"Potion\\"
	"Hi-Potion\\"
	"X-Potion\\"
	"Mega-Potion\\"
	"Ether\\"				// �ther
	"Turbo Ether\\"			// Turbo-�ther
	"Pheonix Down\\"		// Ph�nix-Feder
	"Mega Pheonix\\"		// Mega-Ph�nix
	"Elixir\\"				// 
	"Megalixir\\"			// Final-Elixir
	"Antidote\\"			// Antidot
	"Soft\\"				// Goldnadel
	"Eye Drops\\"			// Augentropfen
	"Echo Screen\\"			// Echokraut
	"Holy Water\\"			// Weihwasser
	"Remedy\\"				// Allheilmittel
	
	"Power Distiller\\"		// Kraftzettel
	"Mana Distiller\\"		// Wunderzettel
	"Speed Distiller\\"		// Zeitzettel
	"Ability Distiller\\"	// Ability-Zettel
	"Al Bhed Potion\\"		// Al-Bhed Mdizin
	"Healing Water\\"		// Heilwasser
	"Tetra Elemental\\"		// Tetra-Element
	"Antarctiv Wind\\"		// Antarktis-Wind
	"Arctic Wind\\"			// Polar-Wind
	"Ice Gem\\"				// K�ltestein
	"Bomb Fragment\\"		// Bomber-Splitter
	"Bomb Core\\"			// Bomber-Seele
	"Fire Gem\\"			// Hitzestein
	"Electro Marble\\"		// Elektrokugel
	"Lightning Marble\\"	// Blitzkugel
	"Lightning Gem\\"		// Donnerstein
	
	"Fish Scale\\"			// Fischschuppe
	"Dragon Scale\\"		// Drachenschuppe
	"Water Gem\\"			// N�ssestein
	"Grenade\\"				// Handgranate
	"Frag Grenade\\"		// Panzergranate
	"Sleeping Powder\\"		// Schlafpuder
	"Dream Powder\\"		// Traumpuder
	"Silence Grenade\\"		// Silentium-Mine
	"Smoke Bomb\\"			// Rauchbombe
	"Shadow Gem\\"			// Schwarzer Stein
	"Shining Gem\\"			// Lichtstein
	"Blessed Gem\\"			// Heiliger Stein
	"Supreme Gem\\"			// Himmelsstein
	"Poison Fang\\"			// Giftkralle
	"Silver Hourglass\\"	// Silberne Sanduhr
	"Gold Hourglass\\"		// Goldene Sanduhr
	
	"Candle of Life\\"		// Todeskerze
	"Petrify Grenade\\"		// Perseus-Granate
	"Farplane Shadow\\"		// Todesschatten
	"Farplane Wind\\"		// Wind des Jenseits
	"Designer Wallet\\"		// Bonzenmesser
	"Dark Matter\\"			// Dunkelkristall
	"Chocobo Feather\\"		// Chocobo-Feder
	"Chocobo Wing\\"		// Chocobo-Daune
	"Lunar Curtain\\"		// Mondschleier
	"Light Curtain\\"		// Lichtschleier
	"Star Curtain\\"			// Sternenschleier
	"Healing Curtain\\"		// Heilquelle
	"Mana Spring\\"			// Magiequelle
	"Stamina Spring\\"		// Kraftquelle
	"Soul Spring\\"			// Lebensquelle
	"Purifying Salt\\"		// Ablutionssalz
	
	"Stamina Tablet\\"		// HP-Pille
	"Mana Tablet\\"			// MP-Pille
	"Twin Stars\\"			// Zweigestirn
	"Stamina Tonic\\"		// HP-Wundermittel
	"Mana Tonic\\"			// MP-Wundermittel
	"Three Stars\\"			// Dreigestirn
	"Power Sphere\\"		// Kraft-Sph�roid
	"Mana Sphere\\"			// Wunder-Sph�roid
	"Speed Sphere\\"		// Zeit-Sph�roid
	"Ability Sphere\\"		// Ability-Sph�roid
	"Fortune Sphere\\"		// Gl�cks-Sph�roid
	"Attribute Sphere\\"	// Para-Sph�roid
	"Special Sphere\\"		// Spezial-Sph�roid
	"Skill Sphere\\"		// Tech-Sph�roid
	"Wht Magic Sphere\\"	// Wei�-Sph�roid
	"Blk Magic Sphere\\"	// Schwarz-Sph�roid
	
	"Master Sphere\\"		// Super-Sph�roid
	"Lv.1 Key Sphere\\"		// Lv,1 Sph�ropass
	"Lv.2 Key Sphere\\"		// Lv.2 Sph�ropass
	"Lv.3 Key Sphere\\"		// Lv.3 Sph�ropass
	"Lv.4 Key Sphere\\"		// Lv.4 Sph�ropass
	"HP Sphere\\"			// HP-Sph�roid
	"MP Sphere\\"			// MP-Sph�roid
	"Strength Sphere\\"		// Angriffs-Sph�roid
	"Defense Sphere\\"		// Abwehr-Sph�roid
	"Magic Sphere\\"		// Magie-Sph�roid
	"Magic Def Sphere\\"	// Z-Abwehr-Sph�roid
	"Agility Sphere\\"		// Geschick-Sph�roid
	"Evasion Sphere\\"		// Reflex-Sph�roid
	"Accuracy Sphere\\"		// Treffer-Sph�roid
	"Luck Sphere\\"			// Fortuna-Sph�roid
	"Clear Sphere\\"		// Spreng-Sph�roid
	
	"Return Sphere\\"		// R�ck-Sph�roid
	"Friend Sphere\\"		// Freund-Sph�roid
	"Teleport Sphere\\"		// Teleport-Sph�roid
	"Warp Sphere\\"			// Warp-Sph�roid
	"Map\\"					// Weltkarte
	"Rename Card\\"			// Tintenkiller
	"Musk\\"				// Aufputschmittel
	"Hypello Potion\\"		// Hypello-Medizin
	"Shining Thorn\\"		// Exorzistendrone
	"Pendulum\\"			// Pendel
	"Amulet\\"				// Amulett
	"Door to Tomorrow\\"	// Tor der Zukunft
	"Wings of Discovery\\"	// Gigantenfl�gel
	"Gamblers Spirit\\"		// Zockerseele
	"Underdog's Secret\\"	// Wendeblatt
	"Winning Formula\\"		// Siegesrausch
	
	"\\"
	
	"\0";

#define KEY_ITEM_NAMES_SIZE 52
extern vector<wstring> keyItemNames;
static const char *keyItemNames_en =
	"Withered Bouquet\\"     // Verwelkte Blumen
	"Flint\\"                // Feuerstein
	"??: Cloudy Mirror\\"        // Nebelspiegel
	"??: Celestial Mirror\\"     // Solaris-Spiegel
	"Al Bhad Primer 01\\"        // Al-Bhed Lexikon
	"Al Bhad Primer 02\\"        // 
	"Al Bhad Primer 03\\"        // 
	"Al Bhad Primer 04\\"        // 
	
	"Al Bhad Primer 05\\"        // 
	"Al Bhad Primer 06\\"        // 
	"Al Bhad Primer 07\\"        // 
	"Al Bhad Primer 08\\"        // 
	"Al Bhad Primer 09\\"        // 
	"Al Bhad Primer 10\\"        // 
	"Al Bhad Primer 11\\"        // 
	"Al Bhad Primer 12\\"        // 
	
	"Al Bhad Primer 13\\"        // 
	"Al Bhad Primer 14\\"        // 
	"Al Bhad Primer 15\\"        // 
	"Al Bhad Primer 16\\"        // 
	"Al Bhad Primer 17\\"        // 
	"Al Bhad Primer 18\\"        // 
	"Al Bhad Primer 19\\"        // 
	"Al Bhad Primer 20\\"        // 
	
	"Al Bhad Primer 21\\"        // 
	"Al Bhad Primer 22\\"        // 
	"Al Bhad Primer 23\\"        // 
	"Al Bhad Primer 24\\"        // 
	"Al Bhad Primer 25\\"        // 
	"Al Bhad Primer 26\\"        // 
	"??: Summoner\'s Soul\\"     // Medium-Seele
	"??: Aeons\'s Soul\\"        // Bestia-Seele
	
	"??: Jecht\'s Sphere\\"      // Jekkts Sph�roid
	"??: Rusty Sword\\"          // Altes Schwert
	"---\\"                      // 
	"Sun Crest\\"                // Solar Marke
	"Sun Sigil\\"                // Solar Siegel
	"Moon Crest\\"               // Lunar Marke
	"Moon Sigil\\"               // Lunar Siegel
	"Mars Crest\\"               // Saturn Marke
	
	"Mars Sigil\\"               // Saturn Siegel
	"??: Mark of Conquest\\"     // Heldenzertifikat
	"Saturn Crest\\"             // Jupiter Marke
	"Saturn Sigil\\"             // Jupiter Siegel
	"Jupiter Crest\\"            // Merkur Marke
	"Jupiter Sigil\\"            // Merkur Siegel
	"Venus Crest\\"              // Mars Marke
	"Venus Sigil\\"              // Mars Siegel
	
	"Mercury Crest\\"            // Venus Marke
	"Mercury Sigil\\"            // Venus Siegel
	"??: Blossom Crown\\"        // Knospelkrone
	"??: Flower Sceptre"         // Blumenkrone
	
	"\0";

#endif // ITEM_CONSTANTS_HPP
