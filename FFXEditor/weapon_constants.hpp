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

#ifndef WEAPON_CONSTANTS_HPP
#define WEAPON_CONSTANTS_HPP

#include "nameIdData.hpp"

enum WEAPON_DEFS
{
	W_CUSTOM = -2,
	W_UNKNOWN = -1,
};

extern std::vector<NameIdData> wModelNames;

#define DAMAGE_TYPE_NAMES_SIZE 23
extern vector<wstring> damageTypeNames;
static const char *damageTypeNames_en =
	"None\\"
	"Attack\\"
	"Attack (Ignore Defense)\\"
	"Magic\\"
	"Magic (Ignore Defense)\\"
	"Demi (Target Current HP)\\"
	"Multiple of 50\\"
	"Healing\\"
	"Demi (Target max HP)\\"
	"Multiple of 50 (random)\\"
	"Demi (Target max MP)\\"
	"Tickspeed * 3\\"
	"Demi (Target Current MP)\\"
	"Current Ticks\\"
	"Attack (Ignore Defense) (fixed)\\"
	"Magic Special (random)\\"
	"Celestial HP (T, K, W, R)\\"
	"Celestial MP (Y, L)\\"
	"Celestial HP (A)\\"
	"Magic Special (fixed)\\"
	"Gil\\"
	"Enemys killed\\"
	"Multiple of 9999"
	"\0";

#define WEAPONS_NAMES_WEAPON_SIZE 70
#define WEAPONS_NAMES_ARMOR 74
#define WEAPONS_NAMES_ARMOR_SIZE 85
#define WEAPONS_NAMES_SIZE 159
#define WEAPONS_NAMES_SIZE_TOTAL WEAPONS_NAMES_SIZE * 7
extern vector<wstring> weaponNames;
static const char *weaponNames_en =
	"Caladbolg\\"
	"Brotherhood\\"
	"Taming Sword\\"
	"Crystal Sword\\"
	"Excalibur\\"
	"Ragnarok\\"
	"Balmung\\"
	"Save the Queen\\"
	"Heartbreaker\\"
	"Lionheart\\"
	"Durandal\\"
	"Ascalon\\"
	"Ambitious\\"
	"Hrunting\\"
	"Longsword\\"
	"Astral Sword\\"
	"Apocalypse\\"
	"Longsword\\"
	"Longsword\\"
	"Master Sword\\"
	"Runemaster\\"
	"Warlock\\"
	"Arc Sword\\"
	"Gilventure\\"
	"Tri-Steel\\"
	"Heiter-Skelter\\"
	"Vendetta\\"
	"Avenger\\"
	"P-Steel\\"
	"M-Steel\\"
	"S-Steel\\"
	"A-Steel\\"
	"Prism Steel\\"
	"Mirage Sword\\"
	"Lifesaver\\"
	"Sonic Steel\\"
	"Vigilante\\"
	"Dance Macabre\\"
	"Largamente\\"
	"Gravestone\\"
	"Sidewinder\\"
	"Nightmare\\"
	"Mage Masher\\"
	"Nightbringer\\"
	"Knight Sword\\"
	"Wizard Sword\\"
	"Double Edge\\"
	"Razzmatazz\\"
	"Deathbringer\\"
	"Stunning Steel\\"
	"Basilisk Steel\\"
	"Poison Steel\\"
	"Lullaby Steel\\"
	"Muted Steel\\"
	"Twilight Steel\\"
	"Hunter's Sword\\"
	"Flametongue\\"
	"Ice Brand\\"
	"Lightning Steel\\"
	"Liquid Steel\\"
	"Variable Steel\\"
	"Force Sabre\\"
	"Baroque Sword\\"
	"Sorcery Sword\\"
	"Soldier's Sabre\\"
	"Rune Steel\\"
	"Enchanted Sword\\"
	"Fencing Sabre\\"
	"Warrior's Sword\\"
	"Slasher\\"
	"Longsword\\"
	"Longsword\\"
	"Longsword\\"
	"Longsword\\"
	"Endless Road\\"
	"Genji Shield\\"
	"Emblem\\"
	"Crystal Shield\\"
	"Aegis Shield\\"
	"Golem Shield\\"
	"Revive Shield\\"
	"Rescue Shield\\"
	"Paladin Shield\\"
	"Diamond Shield\\"
	"Ruby Shield\\"
	"Dynasty Shield\\"
	"Magister Shield\\"
	"Collector's Shield\\"
	"Treasure Shield\\"
	"Shield of Hope\\"
	"Assault Shield\\"
	"Phantom Shield\\"
	"Recovery Shield\\"
	"Spiritual Shield\\"
	"Pheonix Shield\\"
	"Curative Shield\\"
	"Rainbow Shield\\"
	"Shining Shield\\"
	"Fearie Shield\\"
	"Peaceful Shield\\"
	"Shaman Shield\\"
	"Barrier Shield\\"
	"Star Shield\\"
	"Marching Shield\\"
	"Moon Shield\\"
	"Regen Shield\\"
	"Haste Shield\\"
	"Reflect Shield\\"
	"Shell Shield\\"
	"Protect Shield\\"
	"Buckler\\"
	"Platinum Shield\\"
	"Sapphire Shield\\"
	"Knight's Shield\\"
	"Wizard Shield\\"
	"Elemental Shield\\"
	"Defending Shield\\"
	"Crimson Shield\\"
	"Snow Shield\\"
	"Ochre Shield\\"
	"Cerulean Shield\\"
	"Medical Shield\\"
	"Lucid Shield\\"
	"Serene Shield\\"
	"Light Shield\\"
	"Soul Shield\\"
	"Blessed Shield\\"
	"Soft Shield\\"
	"Serum Shield\\"
	"Alert Shield\\"
	"Echo Shield\\"
	"Bright Shield\\"
	"Red Shield\\"
	"White Shield\\"
	"Yellow Shield\\"
	"Blue Shield\\"
	"NulTide Shield\\"
	"NulBlaze Shield\\"
	"NulShock Shield\\"
	"NulFrost Shield\\"
	"Adept's Shield\\"
	"Tetra Shield\\"
	"Mythril Shield\\"
	"Gold Shield\\"
	"Emerald Shield\\"
	"Soldier's Shield\\"
	"Mage's Shield\\"
	"Silver Shield\\"
	"Onyx Shield\\"
	"Sorcery Shield\\"
	"Warrior's Shield\\"
	"Glorious Shield\\"
	"Metal Shield\\"
	"Pearl Shield\\"
	"Magic Shield\\"
	"Seeker's Shield\\"
	"Shield\\"
	"Buckler\\"
	"Sanctuary\\"
	"Nirvana\\"
	"Staff\\"
	"Herding Staff\\"
	"Arc Arcana\\"
	"Abraxas\\"
	"Heavenly Axis\\"
	"Judgement\\"
	"Seraphim Rod\\"
	"Rod of Roses\\"
	"Nimbus Rod\\"
	"Wonder Wing\\"
	"Wing Wand\\"
	"Wonder Wand\\"
	"Leavatein\\"
	"Staff\\"
	"Astral Rod\\"
	"Chaos Rod\\"
	"Staff\\"
	"Staff\\"
	"Power Staff\\"
	"Shining Staff\\"
	"Faerie Staff\\"
	"Magistral Rod\\"
	"El Dorado\\"
	"Tri-Rod\\"
	"Wicked Wand\\"
	"Nemesis Rod\\"
	"Defender\\"
	"P-Staff\\"
	"M-Staff\\"
	"S-Staff\\"
	"A-Staff\\"
	"Prism Rod\\"
	"Mirage Rod\\"
	"Wind Rod\\"
	"Healing Rod\\"
	"Wind Rod\\"
	"Conductor\\"
	"Punisher\\"
	"Impasse\\"
	"Calcite Staff\\"
	"Bizarre Staff\\"
	"Staff of Thorns\\"
	"Reticent Staff\\"
	"Darkness Staff\\"
	"Monk Staff\\"
	"Mage's Staff\\"
	"Dual Rod\\"
	"Ominous Rod\\"
	"Death Wand\\"
	"Entangling Rod\\"
	"Break Rod\\"
	"Beladonna Wand\\"
	"Lullaby Rod\\"
	"Rod of Silence\\"
	"Rod of Darkness\\"
	"Rod of Wisdom\\"
	"Rod of Fire\\"
	"Rod of Ice\\"
	"Rod of Lightning\\"
	"Rod of Water\\"
	"Malleable Staff\\"
	"Force Rod\\"
	"Ductile Rod\\"
	"Sorcery Rod\\"
	"Full Metal Rod\\"
	"Rune Rod\\"
	"Rod of Striking\\"
	"Rod of Beating\\"
	"Spiked Rod\\"
	"Staff\\"
	"Staff\\"
	"Staff\\"
	"Staff\\"
	"Salomon Ring\\"
	"Arcane Ring\\"
	"Mythical Ring\\"
	"Sophia Ring\\"
	"Aegis Ring\\"
	"Sheltering Ring\\"
	"Saviour Ring\\"
	"Healing Ring\\"
	"Forbidding Ring\\"
	"Diamond Ring\\"
	"Ruby Ring\\"
	"Fortitude Ring\\"
	"Magical Ring\\"
	"Collector Ring\\"
	"Treasure Ring\\"
	"Ring of Hope\\"
	"Assault Ring\\"
	"Phantom Ring\\"
	"Recovery Ring\\"
	"Spiritual Ring\\"
	"Phoenix Ring\\"
	"Curative Ring\\"
	"Rainbow Ring\\"
	"Shining Ring\\"
	"Faerie Ring\\"
	"Peaceful Ring\\"
	"Shaman Ring\\"
	"Barrier Ring\\"
	"Star Ring\\"
	"Marching Ring\\"
	"Moon Ring\\"
	"Regen Ring\\"
	"Haste Ring\\"
	"Reflect Ring\\"
	"Shell Ring\\"
	"Protect Ring\\"
	"Ring\\"
	"Platinum Ring\\"
	"Sapphire Ring\\"
	"Power Ring\\"
	"Wizard Ring\\"
	"Elemental Ring\\"
	"Defending Ring\\"
	"Crimson Ring\\"
	"Snow Ring\\"
	"Ochre Ring\\"
	"Cerulean Ring\\"
	"Medical Ring\\"
	"Lucid Ring\\"
	"Serene Ring\\"
	"Light Ring\\"
	"Soul Ring\\"
	"Blessed Ring\\"
	"Soft Ring\\"
	"Serum Ring\\"
	"Alert Ring\\"
	"Echo Ring\\"
	"Bright Ring\\"
	"Red Ring\\"
	"White Ring\\"
	"Yellow Ring\\"
	"Blue Ring\\"
	"NulTide Ring\\"
	"NulBlaze Ring\\"
	"NulShock Ring\\"
	"NulFrost Ring\\"
	"Adept's Ring\\"
	"Tetra Ring\\"
	"Mythril Ring\\"
	"Gold Ring\\"
	"Emerald Ring\\"
	"Soldier's Ring\\"
	"Mage's Ring\\"
	"Silver Ring\\"
	"Onyx Ring\\"
	"Sorcery Ring\\"
	"Tough Ring\\"
	"Glorious Ring\\"
	"Metal Ring\\"
	"Pearl Ring\\"
	"Magic Ring\\"
	"Seeker's Ring\\"
	"Wide Ring\\"
	"Ring\\"
	"Holy Ring\\"
	"Masamune\\"
	"Dull Blade\\"
	"Beastmaster\\"
	"Conqueror\\"
	"Heaven's Cloud\\"
	"Muramasa\\"
	"Alkaid\\"
	"Peacemaker\\"
	"Genji Blade\\"
	"Dragonkiller\\"
	"Painkiller\\"
	"Divider\\"
	"The Nameless\\"
	"Ogrekiller\\"
	"Dull Blade\\"
	"Murasame\\"
	"Riot Blade\\"
	"Dull Blade\\"
	"Dull Blade\\"
	"Master Ogre\\"
	"Master Djinn\\"
	"Matoya's Blade\\"
	"Inducer\\"
	"Gilmonger\\"
	"Ichimonji\\"
	"Corruptor\\"
	"Ashura\\"
	"Kotetsu\\"
	"P-Blade\\"
	"M-Blade\\"
	"S-Blade\\"
	"A-Blade\\"
	"Prism Blade\\"
	"Mirage Blade\\"
	"Lifegiver\\"
	"Sonic Blade\\"
	"Sentry\\"
	"Assasin Blade\\"
	"Blockade\\"
	"Stillblade\\"
	"Venemous Blade\\"
	"Dozing Blade\\"
	"Tacit Blade\\"
	"Dark Blade\\"
	"Ogre Blade\\"
	"Djinn Blade\\"
	"Dual Blade\\"
	"Chaos Blade\\"
	"Critical Blade\\"
	"Stunner\\"
	"Gorgon Gaze\\"
	"Spider's Kiss\\"
	"Peaceful Slumber\\"
	"Soundless Scream\\"
	"Blurry Moon\\"
	"Hunter's Blade\\"
	"Fire Blade\\"
	"Frost Blade\\"
	"Thunder Blade\\"
	"Water Blade\\"
	"Shiranui\\"
	"Basara Blade\\"
	"Shimmering Blade\\"
	"Spiritual Blade\\"
	"Knight Blade\\"
	"Rune Blade\\"
	"Magic Blade\\"
	"Warblade\\"
	"Nodachi\\"
	"Katana\\"
	"Dull Blade\\"
	"Dull Blade\\"
	"Dull Blade\\"
	"Dull Blade\\"
	"Overlord\\"
	"Genji Bracer\\"
	"Dragon Lord\\"
	"Glutton\\"
	"Resistant\\"
	"Warder\\"
	"Immortal\\"
	"Healer\\"
	"Undefeated\\"
	"Diamond Bracer\\"
	"Ruby Bracer\\"
	"Battle Bracer\\"
	"Magical Bracer\\"
	"Collector Bracer\\"
	"Treasure Bracer\\"
	"Bracer of Hope\\"
	"Assault Bracer\\"
	"Phantom Bracer\\"
	"Recovery Bracer\\"
	"Spiritual Bracer\\"
	"Phoenix Bracer\\"
	"Curative Bracer\\"
	"Rainbow Bracer\\"
	"Shining Bracer\\"
	"Faerie Bracer\\"
	"Peaceful Bracer\\"
	"Shaman Bracer\\"
	"Barrier Bracer\\"
	"Star Bracer\\"
	"Marching Bracer\\"
	"Moon Bracer\\"
	"Regen Bracer\\"
	"Haste Bracer\\"
	"Reflect Bracer\\"
	"Shell Bracer\\"
	"Protect Bracer\\"
	"Bracer\\"
	"Platinum Bracer\\"
	"Sapphire Bracer\\"
	"Knight's Bracer\\"
	"Wizard Bracer\\"
	"Elemental Bracer\\"
	"Defending Bracer\\"
	"Crimson Bracer\\"
	"Snow Bracer\\"
	"Ochre Bracer\\"
	"Cerulean Bracer\\"
	"Medical Bracer\\"
	"Lucid Bracer\\"
	"Serene Bracer\\"
	"Light Bracer\\"
	"Soul Bracer\\"
	"Blessed Bracer\\"
	"Soft Bracer\\"
	"Serum Bracer\\"
	"Alert Bracer\\"
	"Echo Bracer\\"
	"Bright Bracer\\"
	"Red Bracer\\"
	"White Bracer\\"
	"Yellow Bracer\\"
	"Blue Bracer\\"
	"NulTide Bracer\\"
	"NulBlaze Bracer\\"
	"NulShock Bracer\\"
	"NulFrost Bracer\\"
	"Adept's Bracer\\"
	"Tetra Bracer\\"
	"Mythril Bracer\\"
	"Gold Bracer\\"
	"Emerald Bracer\\"
	"Soldier's Bracer\\"
	"Mage's Bracer\\"
	"Silver Bracer\\"
	"Onyx Bracer\\"
	"Sorcery Bracer\\"
	"Warrior's Bracer\\"
	"Glorious Bracer\\"
	"Metal Bracer\\"
	"Pearl Bracer\\"
	"Magic Bracer\\"
	"Seeker's Bracer\\"
	"Guardian Bracer\\"
	"Bracer\\"
	"Silidity\\"
	"Spirit Lance\\"
	"Spear\\"
	"Taming Spear\\"
	"Quadforce\\"
	"Gungnir\\"
	"Luin\\"
	"Gae Bolg\\"
	"Venus Gospel\\"
	"Highwind\\"
	"Berserker\\"
	"Horn of the Ronso\\"
	"Chariot\\"
	"Transmuter\\"
	"Kain's Lance\\"
	"Spear\\"
	"Astral Spear\\"
	"Chaos Lance\\"
	"Spear\\"
	"Spear\\"
	"Giant Spear\\"
	"Titan Lance\\"
	"Eldritch Lance\\"
	"Shamanic Spear\\"
	"Prospector\\"
	"Trident\\"
	"Vicious Lance\\"
	"Dragon Lance\\"
	"Rebel Lance\\"
	"P-Lance\\"
	"M-Lance\\"
	"S-Lance\\"
	"A-Lance\\"
	"Prism Spear\\"
	"Mirage Lance\\"
	"Healer Spear\\"
	"Sonic Lance\\"
	"Detector\\"
	"Thanatos Lance\\"
	"Net Spear\\"
	"Rock Buster\\"
	"Venom Spike\\"
	"Hypnos Spear\\"
	"Mage Hunter\\"
	"Kardbringer\\"
	"Knight Lance\\"
	"Wizard Lance\\"
	"Twin Lance\\"
	"Calamity Spear\\"
	"Matador Spear\\"
	"Web Lance\\"
	"Break Lance\\"
	"Snakehead\\"
	"Dream Lance\\"
	"Silent Spear\\"
	"Dusk Lance\\"
	"Hunter's Spear\\"
	"Heat Lance\\"
	"Ice Lance\\"
	"Thunder Spear\\"
	"Tidal Spear\\"
	"Shapeshifter\\"
	"Force Lance\\"
	"Halberd\\"
	"Magic Lance\\"
	"Full Metal Spear\\"
	"Rune Lance\\"
	"Enchanted Lance\\"
	"Striking Spear\\"
	"Heavy Spear\\"
	"Harpoon\\"
	"Spear\\"
	"Spear\\"
	"Spear\\"
	"Spear\\"
	"Pride of the Ronso\\"
	"Genji Armlet\\"
	"Sage's Armlet\\"
	"Crystal Armlet\\"
	"Aegis Armlet\\"
	"Adamantite\\"
	"Orichalcum\\"
	"Safe Passage\\"
	"Ronso Armlet\\"
	"Diamond Armlet\\"
	"Ruby Armlet\\"
	"Enchanted Armlet\\"
	"Magical Armlet\\"
	"Collector Armlet\\"
	"Treasure Armlet\\"
	"Armlet of Hope\\"
	"Assault Armlet\\"
	"Phantom Armlet\\"
	"Recovery Armlet\\"
	"Spiritual Armlet\\"
	"Phoenix Armlet\\"
	"Curative Armlet\\"
	"Rainbow Armlet\\"
	"Shining Armlet\\"
	"Faerie Armlet\\"
	"Peaceful Armlet\\"
	"Shaman Armlet\\"
	"Barrier Armlet\\"
	"Star Armlet\\"
	"Marching Armlet\\"
	"Moon Armlet\\"
	"Regen Armlet\\"
	"Haste Armlet\\"
	"Reflect Armlet\\"
	"Shell Armlet\\"
	"Protect Armlet\\"
	"Armlet\\"
	"Platinum Armlet\\"
	"Sapphire Armlet\\"
	"Knight's Armlet\\"
	"Wizard Armlet\\"
	"Elemental Armlet\\"
	"Defending Armlet\\"
	"Crimson Armlet\\"
	"Snow Armlet\\"
	"Ochre Armlet\\"
	"Cerulean Armlet\\"
	"Medical Armlet\\"
	"Lucid Armlet\\"
	"Serene Armlet\\"
	"Light Armlet\\"
	"Soul Armlet\\"
	"Blessed Armlet\\"
	"Soft Armlet\\"
	"Serum Armlet\\"
	"Alert Armlet\\"
	"Echo Armlet\\"
	"Bright Armlet\\"
	"Red Armlet\\"
	"White Armlet\\"
	"Yellow Armlet\\"
	"Blue Armlet\\"
	"NulTide Armlet\\"
	"NulBlaze Armlet\\"
	"NulShock Armlet\\"
	"NulFrost Armlet\\"
	"Adept's Armlet\\"
	"Tetra Armlet\\"
	"Mythril Armlet\\"
	"Gold Armlet\\"
	"Emerald Armlet\\"
	"Soldier's Armlet\\"
	"Mage's Armlet\\"
	"Silver Armlet\\"
	"Onyx Armlet\\"
	"Sorcery Armlet\\"
	"Warrior's Armlet\\"
	"Glorious Armlet\\"
	"Metal Armlet\\"
	"Pearl Armlet\\"
	"Magic Armlet\\"
	"Seeker's Armlet\\"
	"Guardian Armlet\\"
	"Armlet\\"
	"Acropolis\\"
	"World Champion\\"
	"Official Ball\\"
	"Catcher\\"
	"Four-on-One\\"
	"Grand Slam\\"
	"Blowout\\"
	"Rout\\"
	"Tie Breaker\\"
	"Winning Streak\\"
	"Scoring Spree\\"
	"Triple Score\\"
	"Double Score\\"
	"Rookie Star\\"
	"Buzzerbeater\\"
	"Official Ball\\"
	"Overtime\\"
	"Penalty Master\\"
	"Official Ball\\"
	"Official Ball\\"
	"Ace Striker\\"
	"Ace Wizard\\"
	"Over the Top\\"
	"Halftime\\"
	"Free Agent\\"
	"Tricolor\\"
	"Triple Penalty\\"
	"Turnover\\"
	"Rematch\\"
	"P-Ball\\"
	"M-Ball\\"
	"S-Ball\\"
	"A-Ball\\"
	"Prism Ball\\"
	"Mirage Ball\\"
	"Comeback\\"
	"Breakaway\\"
	"First Goal\\"
	"Sudden Death\\"
	"Timeout\\"
	"Stone Cold\\"
	"Violation\\"
	"Sleeper\\"
	"Muffler\\"
	"Blackout\\"
	"Power Play\\"
	"Virtuoso\\"
	"Double Header\\"
	"Double Penalty\\"
	"Rough Play\\"
	"Delay of Game\\"
	"T.K.O.\\"
	"Rulebreaker\\"
	"Dream Team\\"
	"Noisebreaker\\"
	"Blind Pass\\"
	"Scout\\"
	"Fire Ball\\"
	"Ice Ball\\"
	"Thunder Ball\\"
	"Water Ball\\"
	"All-Rounder\\"
	"Ovation\\"
	"Switch Hitter\\"
	"Trickster\\"
	"Striker\\"
	"Rune Ball\\"
	"Magic Ball\\"
	"Hyper Ball\\"
	"Power Ball\\"
	"Centre Forward\\"
	"Official Ball\\"
	"Official Ball\\"
	"Official Ball\\"
	"Official Ball\\"
	"Indomitable\\"
	"Super Goalie\\"
	"High Spirits\\"
	"Final Four\\"
	"Great Four\\"
	"The Guardian\\"
	"Automatic\\"
	"First Aid\\"
	"Keeper\\"
	"Diamond Armguard\\"
	"Ruby Armguard\\"
	"Power Ace\\"
	"Magic Ace\\"
	"Best Play\\"
	"Great Play\\"
	"Benchwarmer\\"
	"Triple Save\\"
	"Element Save\\"
	"Armsling\\"
	"Spiritual Armguard\\"
	"Miracle Comeback\\"
	"Top Shape\\"
	"Miracle Save\\"
	"Last-Ditch\\"
	"Triple Guard\\"
	"Off-Season\\"
	"Shaman Armguard\\"
	"Hat Trick\\"
	"Pep Talk\\"
	"Auto  Armguard\\"
	"Danger  Armguard\\"
	"Second Wind\\"
	"Fast Break\\"
	"Reflect Armguard\\"
	"Shell Armguard\\"
	"Protect Armguard\\"
	"Armguard\\"
	"Platinum Armguard\\"
	"Sapphire Armguard\\"
	"Power Armguard\\"
	"Energy Armguard\\"
	"Elemental Armguard\\"
	"Low Risk\\"
	"Crimson Armguard\\"
	"Snow Armguard\\"
	"Ochre Armguard\\"
	"Cerulean Armguard\\"
	"Medical Armguard\\"
	"Lucid Armguard\\"
	"Serene Armguard\\"
	"Light Armguard\\"
	"Soul Armguard\\"
	"Blessed Armguard\\"
	"Soft Armguard\\"
	"Serum Armguard\\"
	"Alert Armguard\\"
	"Echo Armguard\\"
	"Bright Armguard\\"
	"Red Armguard\\"
	"White Armguard\\"
	"Yellow Armguard\\"
	"Blue Armguard\\"
	"NulTide Armguard\\"
	"NulBlaze Armguard\\"
	"NulShock Armguard\\"
	"NulFrost Armguard\\"
	"Adept's Armguard\\"
	"Tetra Armguard\\"
	"Mythril Armguard\\"
	"Gold Armguard\\"
	"Emerald Armguard\\"
	"Soldier's Armguard\\"
	"Mage's Armguard\\"
	"Silver Armguard\\"
	"Onyx Armguard\\"
	"Sorcery Armguard\\"
	"Warrior's Armguard\\"
	"Glorious Armguard\\"
	"Metal Armguard\\"
	"Pearl Armguard\\"
	"Magic Armguard\\"
	"Seeker's Armguard\\"
	"Guardian Armguard\\"
	"Armguard\\"
	"Shutout\\"
	"Onion Knight\\"
	"Moogle\\"
	"Trapper Mog\\"
	"Moomba Quartet\\"
	"Soul of Mog\\"
	"Space Soul\\"
	"Space Master\\"
	"Space King\\"
	"Space Force\\"
	"Space Energy\\"
	"Comet Cactuar\\"
	"Star Cactuar\\"
	"Lord Cactuar\\"
	"Space Power\\"
	"Moogle\\"
	"Magical Cactuar\\"
	"Chaotic Cait Sith\\"
	"Moogle\\"
	"Moogle\\"
	"Space Warrior\\"
	"Space Mage\\"
	"Mana Mog\\"
	"Cactuar Wizard\\"
	"Space Bandit\\"
	"Moomba Trio\\"
	"Abaddon Cait Sith\\"
	"Vengeful Cactuar\\"
	"Raging Cactuar\\"
	"P-Mog\\"
	"M-Mog\\"
	"S-Mog\\"
	"A-Mog\\"
	"Prism Cactuar\\"
	"Booster Cactuar\\"
	"Medical Mog\\"
	"Swift Cactuar\\"
	"Cactuar Spy\\"
	"Wicked Cait Sith\\"
	"Chronos Cait Sith\\"
	"Stone Cait Sith\\"
	"Toxic Cait Sith\\"
	"Dreamy Cait Sith\\"
	"Mute Cait Sith\\"
	"Dark Cait Sith\\"
	"Power Mog\\"
	"Magician Mog\\"
	"Moomba Duo\\"
	"Ominous Cait Sith\\"
	"Fatal Cait Sith\\"
	"Late Cait Sith\\"
	"Fossil Cait Sith\\"
	"Noxious Cait Sith\\"
	"Sleepy Cait Sith\\"
	"Quiet Cait Sith\\"
	"Blinding Cait Sith\\"
	"Cactuar Scope\\"
	"Fire Moomba\\"
	"Ice Moomba\\"
	"Thunder Moomba\\"
	"Water Moomba\\"
	"Morphing Mog\\"
	"Moomba Force\\"
	"Variable Mog\\"
	"Moomba Mage\\"
	"Moomba Warrior\\"
	"Rune Mog\\"
	"Magical Mog\\"
	"Buster Mog\\"
	"Attack Mog\\"
	"Stinger Mog\\"
	"Moggle\\"
	"Moggle\\"
	"Moggle\\"
	"Moggle\\"
	"Samantha Soul\\"
	"Minerva Bangle\\"
	"Mythical Bangle\\"
	"Drauphir\\"
	"Aegis Bangle\\"
	"Precious Bangle\\"
	"Imperial Bangle\\"
	"Auto Bangle\\"
	"Black Bangle\\"
	"Diamond Bangle\\"
	"Ruby Bangle\\"
	"Queen's Bangle\\"
	"Magister Bangle\\"
	"Collector Bangle\\"
	"Treasure Bangle\\"
	"Bangle of Hope\\"
	"Assault Bangle\\"
	"Phantom Bangle\\"
	"Recovery Bangle\\"
	"Spiritual Bangle\\"
	"Phoenix Bangle\\"
	"Curative Bangle\\"
	"Rainbow Bangle\\"
	"Shining Bangle\\"
	"Faerie Bangle\\"
	"Peaceful Bangle\\"
	"Shaman Bangle\\"
	"Barrier Bangle\\"
	"Star Bangle\\"
	"Marching Bangle\\"
	"Moon Bangle\\"
	"Regen Bangle\\"
	"Haste Bangle\\"
	"Reflect Bangle\\"
	"Shell Bangle\\"
	"Protect Bangle\\"
	"Bangle\\"
	"Platinum Bangle\\"
	"Sapphire Bangle\\"
	"Power Bangle\\"
	"Wizard Bangle\\"
	"Elemental Bangle\\"
	"Saviour Bangle\\"
	"Crimson Bangle\\"
	"Snow Bangle\\"
	"Ochre Bangle\\"
	"Cerulean Bangle\\"
	"Medical Bangle\\"
	"Lucid Bangle\\"
	"Serene Bangle\\"
	"Light Bangle\\"
	"Soul Bangle\\"
	"Blessed Bangle\\"
	"Soft Bangle\\"
	"Serum Bangle\\"
	"Alert Bangle\\"
	"Echo Bangle\\"
	"Bright Bangle\\"
	"Red Bangle\\"
	"White Bangle\\"
	"Yellow Bangle\\"
	"Blue Bangle\\"
	"NulTide Bangle\\"
	"NulBlaze Bangle\\"
	"NulShock Bangle\\"
	"NulFrost Bangle\\"
	"Adept's Bangle\\"
	"Tetra Bangle\\"
	"Mythril Bangle\\"
	"Gold Bangle\\"
	"Emerald Bangle\\"
	"Soldier'Vita Bangle\\"
	"Mage's Bangle\\"
	"Silver Bangle\\"
	"Onyx Bangle\\"
	"Sorcery Bangle\\"
	"Tough Bangle\\"
	"Glorious Bangle\\"
	"Metal Bangle\\"
	"Pearl Bangle\\"
	"Magic Bangle\\"
	"Seeker's Bangle\\"
	"Guardian Bangle\\"
	"Bangle\\"
	"Eternity\\"
	"Godhand\\"
	"Claw\\"
	"Iron Grip\\"
	"Deus Ex Machina\\"
	"Kaiser Knuckles\\"
	"Victorix\\"
	"Unlimited\\"
	"Warmonger\\"
	"Overload\\"
	"Override\\"
	"Golden Arm\\"
	"Golden Hand\\"
	"Ironside\\"
	"Battle Freak\\"
	"Claw\\"
	"Infinity\\"
	"Tempest Claw\\"
	"Claw\\"
	"Claw\\"
	"Spartan\\"
	"Brunhilde\\"
	"Valkyrie\\"
	"Magical Rave\\"
	"Stickyfingers\\"
	"Rising Sun\\"
	"Typhoon Claw\\"
	"Untouchable\\"
	"Tit-for-Tat\\"
	"P-Claw\\"
	"M-Claw\\"
	"S-Claw\\"
	"A-Claw\\"
	"Prism Claw\\"
	"Mirage Claw\\"
	"Survivor\\"
	"Vanguard\\"
	"Sonar\\"
	"Executioner\\"
	"Clockwork\\"
	"Colossus\\"
	"Manticore Claw\\"
	"Lights Out\\"
	"Mage Husher\\"
	"Jammer\\"
	"Iron Claw\\"
	"The Ogre\\"
	"Dual Claw\\"
	"Hurricane Claw\\"
	"Ninja Claw\\"
	"Clock Hand\\"
	"Break Knuckles\\"
	"Poison Claw\\"
	"Daydreamer\\"
	"Tongue Holder\\"
	"Eye Poker\\"
	"Hawkeye\\"
	"Hot Knuckles\\"
	"Ice Claw\\"
	"Shocking Fist\\"
	"Tidal Knuckles\\"
	"Flexible Arm\\"
	"Force Knuckles\\"
	"Devastator\\"
	"Magic Knuckles\\"
	"Buster Knuckles\\"
	"Magic Claw\\"
	"Magic Glove\\"
	"Buster Claw\\"
	"Buster Glove\\"
	"Barbed Knuckles\\"
	"Claw\\"
	"Claw\\"
	"Claw\\"
	"Claw\\"
	"Dreadnought\\"
	"Atlas\\"
	"Celestial\\"
	"Invincible\\"
	"Armada\\"
	"Triumph\\"
	"Intrepid\\"
	"Goliath\\"
	"Argonaut\\"
	"Diamond Targe\\"
	"Ruby Targe\\"
	"Warlord\\"
	"Dominator\\"
	"Buccaneer\\"
	"Corsair\\"
	"Targe of Hope\\"
	"Assault Targe\\"
	"Phantom Targe\\"
	"Recovery Targe\\"
	"Spiritual Targe\\"
	"Phoenix Targe\\"
	"Curative Targe\\"
	"Phalanx\\"
	"Tercio\\"
	"Talisman\\"
	"Peaceful Targe\\"
	"Shaman Targe\\"
	"Victorious\\"
	"Star Targe\\"
	"Marching Targe\\"
	"Moon Targe\\"
	"Regen Targe\\"
	"Haste Targe\\"
	"Reflect Targe\\"
	"Shell Targe\\"
	"Protect Targe\\"
	"Targe\\"
	"Centurion\\"
	"Echelon\\"
	"Knight's Targe\\"
	"Wizard Targe\\"
	"Elemental Targe\\"
	"Reliant\\"
	"Crimson Targe\\"
	"Snow Targe\\"
	"Ochre Targe\\"
	"Cerulean Targe\\"
	"Medical Targe\\"
	"Lucid Targe\\"
	"Dauntless\\"
	"Light Targe\\"
	"Soul Targe\\"
	"Blessed Targe\\"
	"Soft Targe\\"
	"Serum Targe\\"
	"Alert Targe\\"
	"Echo Targe\\"
	"Bright Targe\\"
	"Red Targe\\"
	"White Targe\\"
	"Yellow Targe\\"
	"Blue Targe\\"
	"NulTide Targe\\"
	"NulBlaze Targe\\"
	"NulShock Targe\\"
	"NulFrost Targe\\"
	"Adept's Targe\\"
	"Tetra Targe\\"
	"Mythril Targe\\"
	"Gold Targe\\"
	"Emerald Targe\\"
	"Soldier's Targe\\"
	"Mage's Targe\\"
	"Silver Targe\\"
	"Onyx Targe\\"
	"Sorcery Targe\\"
	"Warrior's Targe\\"
	"Glorious Targe\\"
	"Metal Targe\\"
	"Pearl Targe\\"
	"Magic Targe\\"
	"Seeker's Targe\\"
	"Guardian Targe\\"
	"Targe\\"
	"Impervious\\"
	"\0";

#define WEAPON_ABILITY_NAMES_SIZE 135
extern vector<wstring> weaponAbilityNames;
static const char *weaponAbilityNames_en =
	"Sensor\\"
	"First Strike\\"
	"Initiative\\"
	"Counter-Attack\\"
	"Evade & Counter\\"
	"Magic Counter\\"
	"Magic Booster\\"
	"Alchemy\\"
	"Auto-Potion\\"
	"Auto-Med\\"
	"Auto-Pheonix\\"
	"Piercing\\"
	"Half MP Cost\\"
	"One MP Cost\\"
	"Double Overdrive\\"
	"Triple Overdrive\\"
	"SOS Overdrive\\"
	"Overdrive -> AP\\"
	"Double AP\\"
	"Triple AP\\"
	"No AP\\"
	"Pickpocket\\"
	"Master Thief\\"
	"Break HP Limit\\"
	"Break MP Limit\\"
	"Break Damage Limit\\"
	"Gillionaire\\"
	"HP Stroll\\"
	"MP Stroll\\"
	"No Encounters\\"
	"Firestrike\\"
	"Fire Ward\\"
	"Fire Proof\\"
	"Fire Eater\\"
	"Icestrike\\"
	"Ice Ward\\"
	"Ice Proof\\"
	"Ice Eater\\"
	"Lightningstrike\\"
	"Lightning Ward\\"
	"Lightning Proof\\"
	"Lightning Eater\\"
	"Waterstrike\\"
	"Water Ward\\"
	"Water Proof\\"
	"Water Eater\\"
	"Deathstrike\\"
	"Deathtouch\\"
	"Deathproof\\"
	"Death Ward\\"
	"Zombiestrike\\"
	"Zombietouch\\"
	"Zombieproof\\"
	"Zombie Ward\\"
	"Stonestrike\\"
	"Stonetouch\\"
	"Stoneproof\\"
	"Stone Ward\\"
	"Poisonstrike\\"
	"Poisontouch\\"
	"Poisonproof\\"
	"Poison Ward\\"
	"Sleepstrike\\"
	"Sleeptouch\\"
	"Sleepproof\\"
	"Sleep Ward\\"
	"Silencestrike\\"
	"Silencetouch\\"
	"Silenceproof\\"
	"Silence Ward\\"
	"Darkstrike\\"
	"Darktouch\\"
	"Darkproof\\"
	"Dark Ward\\"
	"Slowstrike\\"
	"Slowtouch\\"
	"Slowproof\\"
	"Slow Ward\\"
	"Confuseproof\\"
	"Confuse Ward\\"
	"Berserkproof\\"
	"Berserk Ward\\"
	"Curseproof\\"
	"Curse Ward\\"
	"Auto-Shell\\"
	"Auto-Protect\\"
	"Auto-Haste\\"
	"Auto-Regen\\"
	"Auto-Reflect\\"
	"SOS Shell\\"
	"SOS Protect\\"
	"SOS Haste\\"
	"SOS Regen\\"
	"SOS Reflect\\"
	"SOS NulTide\\"
	"SOS NulFrost\\"
	"SOS NulShock\\"
	"SOS NulBlaze\\"
	"Strength +3%\\"
	"Strength +5%\\"
	"Strength +10%\\"
	"Strength +20%\\"
	"Magic +3%\\"
	"Magic +5%\\"
	"Magic +10%\\"
	"Magic +20%\\"
	"Defence +3%\\"
	"Defence +5%\\"
	"Defence +10%\\"
	"Defence +20%\\"
	"Magic Def +3%\\"
	"Magic Def +5%\\"
	"Magic Def +10%\\"
	"Magic Def +20%\\"
	"HP +5%\\"
	"HP +10%\\"
	"HP +20%\\"
	"HP +30%\\"
	"MP +5%\\"
	"MP +10%\\"
	"MP +20%\\"
	"MP +30%\\"
	"Capture\\"
	"-\\"
	"Distil Power\\"
	"Distil Mana\\"
	"Distil Speed\\"
	"Distil Ability\\"
	"Ribbon\\"
	"Extra 1\\"
	"Extra 2\\"
	"Extra 3\\"
	"Extra 4\\"
	"Extra 5\\"
	"Empty"
	"\0";

#define WEAPON_MODEL_NAMES_SIZE 74
extern vector<wstring> weaponModelNames;
static const char *weaponModelNames_en =
	"None\\"
	"Brotherhood\\"
	"Longsword Red\\"
	"Longsword Runed\\"
	"Longsword Black\\"
	"Longsword Blue\\"
	"Longsword Yellow\\"
	"Caladbolg\\"
	"Staff Standard\\"
	"Staff Ball\\"
	"Staff Orange\\"
	"Staff Pink\\"
	"Staff Green\\"
	"Nirvana\\"
	"Katana Standard\\"
	"Katana Curved\\"
	"Katana Hooked\\"
	"Katana Symmetric\\"
	"Masamune\\"
	"Spear Standard\\"
	"Spear Dual Crescent\\"
	"Spear Halberd\\"
	"Spear Green\\"
	"Spear Red\\"
	"Spirit Lance\\"
	"Ball Standard\\"
	"Ball Wrapped\\"
	"Ball Twin Spike\\"
	"Ball Banded\\"
	"Ball Spiked\\"
	"World Champion\\"
	"Doll Moogle\\"
	"Doll Cait Sith\\"
	"Doll Moomba\\"
	"Doll Cactuar\\"
	"Doll Alien\\"
	"Onion Knight\\"
	"Claw Standard\\"
	"Claw Spicked\\"
	"Claw Blocky\\"
	"Claw Blue\\"
	"Godhand\\"
	"Shield 1\\"
	"Shield 2\\"
	"Shield 3\\"
	"Shield 4\\"
	"Shield 5\\"
	"Ring 1\\"
	"Ring 2\\"
	"Ring 3\\"
	"Ring 4\\"
	"Ring 5\\"
	"Bracer 1\\"
	"Bracer 2\\"
	"Bracer 3\\"
	"Bracer 4\\"
	"Armlet 1\\"
	"Armlet 2\\"
	"Armlet 3\\"
	"Armlet 4\\"
	"Armlet 5\\"
	"Armguard 1\\"
	"Armguard 2\\"
	"Armguard 3\\"
	"Armguard 4\\"
	"Armguard 5\\"
	"Bangle 1\\"
	"Bangle 2\\"
	"Bangle 3\\"
	"Bangle 4\\"
	"Bangle 5\\"
	"Targe 1\\"
	"Targe 2\\"
	"Targe 3\\"
	"Targe 4"
	"\0";

#endif // WEAPON_CONSTANTS_HPP
