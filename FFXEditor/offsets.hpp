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

#ifndef OFFSETS_HPP
#define OFFSETS_HPP

#define SEARCH_BYTE_OFFSET                 24282
#define MAP_ARRAY_SIZE                    USHRT_MAX

#define SEARCH_SPECIAL_BYTE               0x5C
#define SEARCH_SPECIAL_BYTE_AMOUNT        100
#define SEARCH_SPECIAL_BYTE_OFFSET        9894

#define SEARCH_BYTES_ARRAY_LEN 10
static const unsigned char seachBytesArray[SEARCH_BYTES_ARRAY_LEN] =
{
	'b',
	't',
	'l',
	'e',
	'n',
	'v',
	'.',
	't',
	'x',
	't'
};

#define SEARCH_BYTES_ARRAY_2_LEN 7
static const unsigned char seachBytesArray2[SEARCH_BYTES_ARRAY_2_LEN] =
{
	0x57,
	0xDB,
	0xF6,
	0xAF,
	0xFE,
	0x3F,
	0x00
};

#define LANGVERSION_ARRAY_LEN 21
#define LANGVERSION_SEARCH_OFFSET -50000
#define LANGVERSION_SUBSEARCH_OFFSET -30
static const unsigned char langVersionArray[LANGVERSION_ARRAY_LEN] =
{
	'a',
	't',
	'e',
	'l',
	's',
	'a',
	'v',
	'e',
	'r',
	'a',
	'm',
	'0',
	'0',
	'0',
	'5',
	'2',
	'0',
	'.',
	'd',
	'a',
	't'
};
//0x61, 0x74, 0x65, 0x6C, 0x73,
//0x61, 0x76, 0x65, 0x72, 0x61,
//0x6D, 0x30, 0x30, 0x30, 0x35,
//0x32, 0x30, 0x2E, 0x64, 0x61, 0x74

#define BATTLE_DATA_CONTAINER_LEN 4
#define BATTLE_DATA_CONTAINER_DISTANCE 32
#define BD_INDENT_LEN 6
#define BD_INDENT_OFFSET_FROM_CONT_A 22
#define BD_IDENT_ENDCHAR 0x41
#define BD_IDENT_CHAR_MASK 1
#define BD_IDENT_CHAR_MASK2 128
#define BD_CONTAINER_SKIP_LEN 2000
static const unsigned char battleDataContainerA[] =
{
	0xCD, 0xCC, 0xCC, 0x3E
};
static const unsigned char battleDataContainerB[] =
{
	0xCD, 0xCC, 0x4C, 0x3E
};

#define BD_COMMON_SEARCH_LEN 3
#define BD_COMMON_SEARCH_OFFSET 160
#define BD_COMMON_SEARCH_MAX_SEARCH_LEN 80
static const unsigned char battleData_commonSearch[] =
{
	0xFF, 0xFF, 0x10
};

enum BASIC_OFFSETS
{
	OFFSET_GAMETIME = -15500,   // seconds
	OFFSET_KEYITEM_BOUQUET = -14812, // 1 byte
	OFFSET_KEYITEM_FLINT = -14811, // 1 byte
	OFFSET_AL_BHED_PRIMER_COUNTER = -12540,
	OFFSET_AL_BHED_PRIMER_BITMASK = -56,
	
	OFFSET_GIL = 0,
	
	OFFSET_CHAR_FORMATION = 16,      // from 16 - 35
	OFFSET_OVERDRIVES_BITMASK = 36,  // from 36 - 51
	
	OFFSET_TIDUS_OVERDRIVE_COUNTER = 100,
	
	OFFSET_ITEMS_ID_LIST = 388,      // 2 bytes: first item ID, second bitmask 0x20 = available
	OFFSET_ITEMS_AMOUNT_LIST = 900,
	
	OFFSET_KEY_ITEM_BITMASK = 1860,
	
	OFFSET_WEAPON_DATA = 1876,
	OFFSET_TIDUS = 6280,
	OFFSET_YUNA = 6428,
	OFFSET_AURON = 6576,
	OFFSET_KIMAHRI = 6724,
	OFFSET_WAKKA = 6872,
	OFFSET_LULU = 7020,
	OFFSET_RIKKU = 7168,
	OFFSET_SEYMOUR = 7316,
	OFFSET_AEON_VALEFOR = 7464,
	OFFSET_AEON_IFRIT = 7612,
	OFFSET_AEON_IXION = 7760,
	OFFSET_AEON_SHIVA = 7908,
	OFFSET_AEON_BAHAMUT = 8056,
	OFFSET_AEON_ANIMA = 8204,
	OFFSET_AEON_YOJIMBO = 8352,
	OFFSET_AEON_MUG = 8500,
	OFFSET_AEON_DUG = 8648,
	OFFSET_AEON_RUG = 8796,
	
	OFFSET_CHAR_NAMES = 9732, // 20 bytes each
	
	OFFSET_CHOCOBO_RED_BALOON = 9127991,
};

enum
{
	TIDUS = 0,
	YUNA,
	AURON,
	KIMAHRI,
	WAKKA,
	LULU,
	RIKKU,
	
	SEYMOUR = 7,
	
	CHAR_COUNT,
	
	AEON_START = 8,
	VALEFOR = 8,
	IFRIT,
	IXION,
	SHIVA,
	BAHAMUT,
	ANIMA,
	YOJIMBO,
	MUG,
	DUG,
	RUG,
	AEON_END,
	
	CHAR_COUNT_ALL = AEON_END
};

enum CHAR_DATA_OFFSETS  // aeons too
{
	// int
	OFFSET_HP_MAX_BASE = 0,
	OFFSET_MP_MAX_BASE = 4,
	
	// byte
	OFFSET_ATTACK_BASE = 8,
	OFFSET_DEFENSE_BASE,
	OFFSET_MAGIC_BASE,
	OFFSET_MAGIC_DEF_BASE,
	OFFSET_SPEED_BASE,
	OFFSET_LUCK_BASE,
	OFFSET_EVADE_BASE,
	OFFSET_HIT_BASE,
	
	// int
	OFFSET_AP = 16,
	OFFSET_AP_NEXT = 20,
	OFFSET_HP = 24,
	OFFSET_MP = 28,
	OFFSET_HP_MAX = 32,
	OFFSET_MP_MAX = 36,
	
	OFFSET_40 = 40,
	
	// byte
	OFFSET_WEAPON_ID = 41,  // index of entry in weapon_data list
	OFFSET_SHIELD_ID,       // index of entry in weapon_data list
	OFFSET_ATTACK,
	OFFSET_DEFENSE,
	OFFSET_MAGIC,
	OFFSET_MAGIC_DEF,
	OFFSET_SPEED,
	OFFSET_LUCK,
	OFFSET_EVADE,
	OFFSET_HIT,
	
	OFFSET_51,
	OFFSET_OVERDRIVE_MODE,
	
	OFFSET_OVERDRIVE_POINTS,
	OFFSET_OVERDRIVE_POINTS_NEEDED,
	OFFSET_S_LEVEL,
	OFFSET_S_LEVEL_USED,
	
	OFFSET_BATTLES_TILL_REVIVE,   // for aeons
	
	// int
	OFFSET_ABILITY_1 = 58,
	OFFSET_ABILITY_2 = 62,
	OFFSET_ABILITY_3 = 66,
	
	OFFSET_70 = 70,
	OFFSET_71,
	OFFSET_72,
	OFFSET_73,
	OFFSET_74,
	OFFSET_75,
	
	// int
	OFFSET_BATTLES_WON = 76,
	OFFSET_ENEMYS_KILLED = 80, 
	OFFSET_DEATHS = 84,
	OFFSET_88,
	
	// short
	OFFSET_OVERDRIVE_WARRIOR = 92,    // dealing damage
	OFFSET_OVERDRIVE_COMRADE = 94,    // alies taking damage
	OFFSET_OVERDRIVE_STOIC = 96,	  // taking damage
	OFFSET_OVERDRIVE_HEALER = 98,     // heal members
	OFFSET_OVERDRIVE_TACTICIAN = 100, // apply condition to enemy
	OFFSET_OVERDRIVE_VICTIM = 102,    // taking hits with condition
	OFFSET_OVERDRIVE_DANCER = 104,    // evade attacks
	OFFSET_OVERDRIVE_AVENGER = 106,   // member dies
	OFFSET_OVERDRIVE_SLAYER = 108,    // defeat enemys
	OFFSET_OVERDRIVE_HERO = 110,      // dedeat strong enemys
	OFFSET_OVERDRIVE_ROOK = 112,      // block with magic
	OFFSET_OVERDRIVE_VICTOR = 114,    // party wins battle
	OFFSET_OVERDRIVE_COWARD = 116,    // run from battle
	OFFSET_OVERDRIVE_ALLY = 118,      // your turn
	OFFSET_OVERDRIVE_SUFFERER = 120,  // member gets conditions
	OFFSET_OVERDRIVE_DAREDEVIL = 122, // low hp
	OFFSET_OVERDRIVE_SOLO = 124,      // fight solo
	
	// additional
	OFFSET_OVERDRIVE_START = OFFSET_OVERDRIVE_WARRIOR,
	OFFSET_OVERDRIVE_END = OFFSET_OVERDRIVE_SOLO,
	
	OFFSET_OVERDRIVE_AGONIE = OFFSET_OVERDRIVE_DAREDEVIL,
	OFFSET_OVERDRIVE_ASKESE = OFFSET_OVERDRIVE_STOIC,
	OFFSET_OVERDRIVE_BARMHERZIGKEIT = OFFSET_OVERDRIVE_HEALER,
	OFFSET_OVERDRIVE_DILEMA = OFFSET_OVERDRIVE_VICTIM,
	OFFSET_OVERDRIVE_ERHABENHEIT = OFFSET_OVERDRIVE_SOLO,
	OFFSET_OVERDRIVE_GRAZIE = OFFSET_OVERDRIVE_DANCER,
	OFFSET_OVERDRIVE_HELDENTUM = OFFSET_OVERDRIVE_HERO,
	OFFSET_OVERDRIVE_KAMPFGEIST = OFFSET_OVERDRIVE_WARRIOR,
	OFFSET_OVERDRIVE_KONFRONTATION = OFFSET_OVERDRIVE_ALLY,
	OFFSET_OVERDRIVE_LEID = OFFSET_OVERDRIVE_SUFFERER,
	OFFSET_OVERDRIVE_SCHMACH = OFFSET_OVERDRIVE_COWARD,
	OFFSET_OVERDRIVE_SIEGESHYMNE = OFFSET_OVERDRIVE_SLAYER,
	OFFSET_OVERDRIVE_STANDHAFTIGKEIT = OFFSET_OVERDRIVE_ROOK,
	OFFSET_OVERDRIVE_TAKTIK = OFFSET_OVERDRIVE_TACTICIAN,
	OFFSET_OVERDRIVE_TRAUER = OFFSET_OVERDRIVE_AVENGER,
	OFFSET_OVERDRIVE_TRIUMPH = OFFSET_OVERDRIVE_VICTOR,
	OFFSET_OVERDRIVE_ZORN = OFFSET_OVERDRIVE_COMRADE,
};

enum WEAPON_DATA_OFFSETS
{
	WEAPON_ID = 0,            // unique for each characters weapon
	WEAPON_ID_CONT,           // seems to be always 0x50
	WEAPON_AVAILABLE,         // seems to be always 0x01
	WEAPON_SPECIAL_PROPERTIES,
	WEAPON_CHARID,            // destination character: see character enum
	WEAPON_ARMOR,             // 0x00 = weapon / 0x01 = armor
	WEAPON_EQUIPPED_CHARID,   // who has this eqquiped: see character enum / 0xFF = noone
	WEAPON_7,
	WEAPON_DAMAGE_FORMULA,    // see enums WEAPON_DAMAGES
	WEAPON_ATTACK_POWER,      // seems to be always 0x10
	WEAPON_CRIT_HIT,          // seems to be always 0x03
	WEAPON_SLOTS,             // do not set this higher than 4
	WEAPON_SKIN,
	WEAPON_SKIN_CONT,         // seems to be always 0x40
	WEAPON_SLOT1_ABILITY,
	WEAPON_SLOT1_FREE,        // 0x00 = free / 0x80 = used
	WEAPON_SLOT2_ABILITY,
	WEAPON_SLOT2_FREE,        // 0x00 = free / 0x80 = used
	WEAPON_SLOT3_ABILITY,
	WEAPON_SLOT3_FREE,        // 0x00 = free / 0x80 = used
	WEAPON_SLOT4_ABILITY,
	WEAPON_SLOT4_FREE,        // 0x00 = free / 0x80 = used
};

enum WEAPON_DAMAGES
{
	WEAPON_DAMAGE_NONE = 0,
	WEAPON_DAMAGE_ATTACK,
	WEAPON_DAMAGE_ATTACK_IGNORE_DEF,
	WEAPON_DAMAGE_MAGIC,
	WEAPON_DAMAGE_MAGIC_IGNORE_DEF,
	WEAPON_DAMAGE_DEMI_TARGET_CUR_HP,
	WEAPON_DAMAGE_MULTIPLE_50,
	WEAPON_DAMAGE_HEALING,            // no heal
	WEAPON_DAMAGE_DEMI_TARGET_MAX_HP,
	WEAPON_DAMAGE_MULTIPLE_50_RANDOM,
	WEAPON_DAMAGE_DEMI_TARGET_MAX_MP,
	WEAPON_DAMAGE_TICKSPEED_3,
	WEAPON_DAMAGE_DEMI_TARGET_CUR_MP,
	WEAPON_DAMAGE_CUR_TICKS,
	WEAPON_DAMAGE_ATTACK_IGNORE_DEF_NO_RANDOM,
	WEAPON_DAMAGE_SPECIAL_MAGIC_RANDOM,
	WEAPON_DAMAGE_CELESTIAL_HIGH_HP,  // Tidus Kimahri Wakka Rikku
	WEAPON_DAMAGE_CELESTIAL_HIGH_MP,  // Yuna Lulu
	WEAPON_DAMAGE_CELESTIAL_LOW_HP,    // Auron
	WEAPON_DAMAGE_SPECIAL_MAGIC_NO_RANDOM,
	WEAPON_DAMAGE_GIL,
	WEAPON_DAMAGE_ENEMYS_KILLED,
	WEAPON_DAMAGE_MULTIPLE_9999,
};

// ability bit mask
enum ABILITY_BIT_MASK
{
	ABILITY_SLOT0_NORMAL_ATTACK = 1,           // 
	ABILITY_SLOT0_ITEM_MENU = 2,               // 
	ABILITY_SLOT0_PLAYER_CHANGE = 4,           // 
	ABILITY_SLOT0_ESCAPE = 8,                  // 
	ABILITY_SLOT0_WEAPON_CHANGE = 16,          // 
	ABILITY_SLOT0_ARMOR_CHANGE = 32,           // 
	ABILITY_SLOT0_DELAY_ATTACK = 64,           // retard-hieb
	ABILITY_SLOT0_DELAY_BUSTER = 128,          // retard-shock
	ABILITY_SLOT0_SLEEP_ATTACK = 256,          // schlaf hieb
	ABILITY_SLOT0_SILENCE_ATTACK = 512,        // stumm hieb
	ABILITY_SLOT0_DARK_ATTACK = 1024,          // blind hieb
	ABILITY_SLOT0_ZOMBIE_ATTACK = 2048,        // zombie hieb
	ABILITY_SLOT0_SLEEP_BUSTER = 4096,         // schlaf schock
	ABILITY_SLOT0_SILENCE_BUSTER = 8192,       // stumm schock
	ABILITY_SLOT0_DARK_BUSTER = 16384,         // blind schock
	ABILITY_SLOT0_TRIPLE_FOUL = 32768,         // trisaster
	ABILITY_SLOT0_POWER_BREAK = 65536,         // kraftbrecher
	ABILITY_SLOT0_MAGIC_BREAK = 131072,        // magiebrecher
	ABILITY_SLOT0_ARMOR_BREAK = 262144,        // panzerbrecher
	ABILITY_SLOT0_MENTAL_BREAK = 524288,       // geistbrecher
	ABILITY_SLOT0_MUG = 1048576,               // rauben
	ABILITY_SLOT0_QUICK_HIT = 2097152,         // rapidschlag
	ABILITY_SLOT0_STEAL = 4194304,             // klauen
	ABILITY_SLOT0_USE = 8388608,               // benutzen
	ABILITY_SLOT0_FLEE = 16777216,             // und tsch�ss...
	ABILITY_SLOT0_PRAY = 33554432,             // beten
	ABILITY_SLOT0_CHEER = 67108864,            // anfeuern
	ABILITY_SLOT0_AIM = 134217728,             // anpeilen
	ABILITY_SLOT0_FOCUS = 268435456,           // sammeln
	ABILITY_SLOT0_REFLEX = 536870912,          // ahnen
	ABILITY_SLOT0_LUCK = 1073741824,           // fortuna
	ABILITY_SLOT0_JINX = 2147483648,           // unheil
	
	ABILITY_SLOT2_LANCET = 1,                  // dragonik
	ABILITY_SLOT2_ = 2,                        // 
	ABILITY_SLOT2_GUARD = 4,                   // bodyguard
	ABILITY_SLOT2_SENTINEL = 8,                // schutzwall
	ABILITY_SLOT2_SPARE_CHANGE = 16,           // almosen
	ABILITY_SLOT2_THREATEN = 32,               // drohen
	ABILITY_SLOT2_PROVOKE = 64,                // reizen
	ABILITY_SLOT2_ENTRUST = 128,               // abgeben
	ABILITY_SLOT2_COPYCAT = 256,               // imitieren
	ABILITY_SLOT2_DOUBLECAST = 512,            // hades-magie
	ABILITY_SLOT2_BRIBE = 1024,                // bestechen
	ABILITY_SLOT2_CURE = 2048,                 // vita
	ABILITY_SLOT2_CURA = 4096,                 // vitra
	ABILITY_SLOT2_CURAGA = 8192,               // vigra
	ABILITY_SLOT2_NULFROST = 16384,            // exeis
	ABILITY_SLOT2_NULBLAZE = 32768,            // exfeu
	ABILITY_SLOT2_NULSHOCK = 65536,            // exblitz
	ABILITY_SLOT2_NULTIDE = 131072,            // exwass
	ABILITY_SLOT2_SCAN = 262144,               // analyse
	ABILITY_SLOT2_ESUNA = 524288,              // medica
	ABILITY_SLOT2_LIFE = 1048576,              // engel
	ABILITY_SLOT2_FULLLIFE = 2097152,          // erzengel
	ABILITY_SLOT2_HASTE = 4194304,             // hast
	ABILITY_SLOT2_HASTEGA = 8388608,           // hastga
	ABILITY_SLOT2_SLOW = 16777216,             // gemach
	ABILITY_SLOT2_SLOWGA = 33554432,           // gemachga
	ABILITY_SLOT2_SHELL = 67108864,            // 
	ABILITY_SLOT2_PROTECT = 134217728,         // protes
	ABILITY_SLOT2_REFLECT = 268435456,         // reflek
	ABILITY_SLOT2_DISPEL = 536870912,          // anti-z
	ABILITY_SLOT2_REGEN = 1073741824,          // regena
	ABILITY_SLOT2_HOLY = 2147483648,           // sanctus
	
	ABILITY_SLOT3_AUTO_LIFE = 1,               // schutzengel
	ABILITY_SLOT3_BLIZZARD = 2,                // eis
	ABILITY_SLOT3_FIRE = 4,                    // feuer
	ABILITY_SLOT3_THUNDER = 8,                 // blitz
	ABILITY_SLOT3_WATER = 16,                  // wasser
	ABILITY_SLOT3_FIRA = 32,                   // feura
	ABILITY_SLOT3_BLIZZARA = 64,               // eisra
	ABILITY_SLOT3_THUNDARA = 128,              // blitzra
	ABILITY_SLOT3_WATERA = 256,                // wassra
	ABILITY_SLOT3_FIRAGA = 512,                // feuga
	ABILITY_SLOT3_BLIZZAGA = 1024,             // eisga
	ABILITY_SLOT3_THUNDAGA = 2048,             // blitzga
	ABILITY_SLOT3_WATERGA = 4096,              // wassga
	ABILITY_SLOT3_BIO = 8192,                  // 
	ABILITY_SLOT3_DEMI = 16384,                // gravitas
	ABILITY_SLOT3_DEATH = 32768,               // tod
	ABILITY_SLOT3_DRAIN = 65536,               // subvita
	ABILITY_SLOT3_OSMOSE = 131072,             // subspirit
	ABILITY_SLOT3_FLARE = 262144,              // 
	ABILITY_SLOT3_ULTIMA = 524288,             // 
	ABILITY_SLOT3_1 = 1048576,                 // sanfte tour
	ABILITY_SLOT3_2 = 2097152,                 // harte tour
	ABILITY_SLOT3_3 = 4194304,                 // zur�ckrufen
	ABILITY_SLOT3_4 = 8388608,                 // 
	ABILITY_SLOT3_PILFER_GIL = 16777216,       // gil-klau
	ABILITY_SLOT3_ALL_BREAK = 33554432,        // allesbreacher
	ABILITY_SLOT3_EXTRACT_POWER = 67108864,    // kraft-hieb
	ABILITY_SLOT3_EXTRACT_MANA = 134217728,    // wunder-hieb
	ABILITY_SLOT3_EXTRACT_SPEED = 268435456,   // zeit-hieb
	ABILITY_SLOT3_EXTRACT_ABILITY = 536870912, // ability-hieb
	ABILITY_SLOT3_NAB_GIL = 1073741824,        // gil-raub
	ABILITY_SLOT3_QUICK_POCKETS = 2147483648,  // jonglieren
};

enum AEON_DATA_OFFSETS
{
	// int
	AEON_HP_ADD = 0,
	AEON_MP_ADD = 4,
	
	// byte
	AEON_ATTACK_ADD = 8,
	AEON_DEFENSE_ADD,
	AEON_MAGIC_ADD,
	AEON_MAGIC_DEF_ADD,
	AEON_SPEED_ADD,
	AEON_LUCK_ADD,
	AEON_EVADE_ADD,
	AEON_HIT_ADD,
	
	AEON_HP = 24,
	AEON_MP = 28,
	AEON_HP_MAX = 32,
	AEON_MP_MAX = 36,
	
	// byte
	AEON_AVAILABLE = 40,    // set this to 0x11
	AEON_OFFSET_41,
	AEON_OFFSET_42,
	
	AEON_ATTACK,
	AEON_DEFENSE,
	AEON_MAGIC,
	AEON_MAGIC_DEF,
	AEON_SPEED,
	AEON_LUCK,
	AEON_EVADE,
	AEON_HIT,
	
	AEON_OFFSET_51,
	AEON_OFFSET_52,
	
	AEON_OVERDRIVE_POINTS,
	AEON_OVERDRIVE_POINTS_NEEDED,
	
	AEON_OFFSET_55,
	AEON_OFFSET_56,
	AEON_BATTLES_TILL_REVIVE,
	
	// int
	AEON_ABILITY_1 = 58,
	AEON_ABILITY_2 = 62,
	AEON_ABILITY_3 = 66,
	
	// byte
	AEON_OFFSET_70,
	AEON_OFFSET_71,
	AEON_OFFSET_72,
	AEON_OFFSET_73,
	AEON_OFFSET_74,
	AEON_OFFSET_75,
	AEON_OFFSET_76,
	AEON_OFFSET_77,
	AEON_OFFSET_78,
	AEON_OFFSET_79,
	
	// int
	AEON_ENEMYS_KILLED = 80,
	AEON_DEATHS = 84,
};

enum OVERDRIVES_BITMASK
{
	// tidus
	OVERDRIVES_BITMASK_TIDUS = 1,
	OVERDRIVE_1_SPIRAL_CUT = 1,
	OVERDRIVE_1_SLICE_AND_DICE = 2,
	OVERDRIVE_1_ENERGY_RAIN = 4,
	OVERDRIVE_1_BLITZ_ACE = 8,
	// auron
	OVERDRIVES_BITMASK_AURON = 16,
	OVERDRIVE_1_DRAGON_FANG = 16,       // seisma
	OVERDRIVE_1_SHOOTING_STAR = 32,     // holosiderit
	OVERDRIVE_1_BANISHING_BLADE = 64,   // suppression
	OVERDRIVE_1_TORNADO = 128,          // zephyr
	
	// kimahari
	OVERDRIVES_BITMASK_KIMAHRI = 256,
	OVERDRIVE_1_JUMP = 256,             // sprung
	OVERDRIVE_1_FLAME = 512,            // flammen
	OVERDRIVE_1_SEED_CANNON = 1024,     // kernspucken
	OVERDRIVE_1_SELF_DESTRUCT = 2048,   // explodieren
	OVERDRIVE_1_ROTATE_KICK = 4096,     // wirbelkick
	OVERDRIVE_1_STONE_BREATH = 8192,    // perseus-atem
	OVERDRIVE_1_AQUA_BREATH = 16384,    // nasshauch
	OVERDRIVE_1_DEATH_SENTENCE = 32768, // todesurteil
	
	OVERDRIVE_1_WHITE_WIND = 65536,     // himmelswind
	OVERDRIVE_1_BAD_BREATH = 131072,    // mundgeruch
	OVERDRIVE_1_MIGHTY_GUARD = 262144,  // totalabwehr
	OVERDRIVE_1_NOVA = 524288,          // supernova
	// wakka
	OVERDRIVES_BITMASK_WAKKA = 1048576,
	OVERDRIVE_1_ELEMENT_REELS = 1048576,// element-T
	OVERDRIVE_1_ATTACK_REELS = 2097152, // angriffs-T
	OVERDRIVE_1_STATUS_REELS = 4194304, // zustands-T
	OVERDRIVE_1_AUROCH_REELS = 8388608, // aurochs-T
	
	// lulu
	OVERDRIVES_BITMASK_LULU = 16777216,
	OVERDRIVE_1_BLIZZARD = 16777216,    // eis
	OVERDRIVE_1_FIRE = 33554432,        // feuer
	OVERDRIVE_1_THUNDER = 67108864,     // blitz
	OVERDRIVE_1_WATER = 134217728,      // wasser
	OVERDRIVE_1_FIRA = 268435456,       // feura
	OVERDRIVE_1_BLIZZARA = 536870912,   // eisra
	OVERDRIVE_1_THUNDERA = 1073741824,  // blitzra
	OVERDRIVE_1_WATERA = 2147483648,    // wassra
	
	OVERDRIVE_2_FIRAGA = 1,             // feuga
	OVERDRIVE_2_BLIZZAGA = 2,           // eisga
	OVERDRIVE_2_THUNDAGA = 4,           // bliltzga
	OVERDRIVE_2_WATERGA = 8,            // wassga
	OVERDRIVE_2_BIO = 16,               // bio
	OVERDRIVE_2_DEMI = 32,              // gravitas
	OVERDRIVE_2_DEATH = 64,             // tod
	OVERDRIVE_2_DRAIN = 128,            // subvita
	
	OVERDRIVE_2_OSMOSE = 256,           // subspirit
	OVERDRIVE_2_FLARE = 512,            // flare
	OVERDRIVE_2_ULTIMA = 1024,          // 
	// rikku
	OVERDRIVES_BITMASK_RIKKU = 2048,
	OVERDRIVE_2_GRENADE = 2048,         // handgranate
	OVERDRIVE_2_FRAG_GRENADE = 4096,    // panzergranate
	OVERDRIVE_2_PINEAPPLE = 8192,       // hypergranate
	OVERDRIVE_2_POTATO_MASHER = 16384,  // granatwerfer
	OVERDRIVE_2_CLUSTER_BOMB = 32768,   // m�rser
	
	OVERDRIVE_2_TALLBOY = 65536,         // sprengladung
	OVERDRIVE_2_BLASTER_MINE = 131072,   // dicke berta
	OVERDRIVE_2_HAZARDOUS_SHELL = 262144,// risikohaubitze
	OVERDRIVE_2_CALAMITY_BOMB = 524288,  // panikbombe
	OVERDRIVE_2_CHAOS_GRENADE = 1048576, // chaosgranate
	OVERDRIVE_2_HEAT_BLASTER = 2097152,  // hei�es eisen
	OVERDRIVE_2_FIRESTORM = 4194304,     // feuersturm
	OVERDRIVE_2_BURNING_SOUL = 8388608,  // flammenseele
	
	OVERDRIVE_2_BRIMSTONE = 16777216,    // h�llenfeuer
	OVERDRIVE_2_ABADDON_FLAME = 33554432,// utgardlodern
	OVERDRIVE_2_SNOW_FLURRY = 67108864,  // kalter schnee
	OVERDRIVE_2_ICE_FALL = 134217728,    // eisiger wind
	OVERDRIVE_2_WINTER_STORM = 268435456,// wintersturm
	OVERDRIVE_2_BLACK_ICE = 536870912,   // eis kontamina
	OVERDRIVE_2_KRYSTA = 1073741824,     // kokytos
	OVERDRIVE_2_THUNDERBOLT = 2147483648,         // gewitterfront
	
	OVERDRIVE_3_ROLLING_THUNDER = 1,             // donnerschlag
	OVERDRIVE_3_LIGHTNING_BOLT = 2,           // blitzeinschlag
	OVERDRIVE_3_ELECTRO_SHOCK = 4,           // elektro schock
	OVERDRIVE_3_THUNDER_BLAST = 8,            // taifun
	OVERDRIVE_3_WATER_FALL = 16,               // str�mung
	OVERDRIVE_3_FLASH_FLOOD = 32,              // wasserfall
	OVERDRIVE_3_TIDAL_WAVE = 64,             // flutwelle
	OVERDRIVE_3_AQUA_TOXIN = 128,            // aqua toxin
	
	OVERDRIVE_3_DARK_RAIN = 256,           // dunkler regen
	OVERDRIVE_3_NEGA_BURST = 512,            // lebensloch
	OVERDRIVE_3_BLACK_HOLE = 1024,          // wurmloch
	OVERDRIVE_3_SUPERNOVA = 2048,         // supernova
	OVERDRIVE_3_ULTRA_POTION = 4096,    // 
	OVERDRIVE_3_PANACEA = 8192,         // allesheiler
	OVERDRIVE_3_ULTRA_CURE = 16384,         // ultraheiler
	OVERDRIVE_3_MEGAPHEONIX = 32768,         // mega ph�nix
	
	OVERDRIVE_3_FINAL_PHOENIX = 65536,         // final ph�nix
	OVERDRIVE_3_ELIXIR = 131072,         // elixier
	OVERDRIVE_3_MEGA_ELIXIR = 262144,         // endelixier
	OVERDRIVE_3_SUPER_ELIXIR = 524288,         // superelixier
	OVERDRIVE_3_FINAL_ELIXIR = 1048576,         // final-elixier
	OVERDRIVE_3_NULALL = 2097152,         // exall
	OVERDRIVE_3_MEGA_NULALL = 4194304,         // super exall
	OVERDRIVE_3_SUPER_NULALL = 8388608,         // mega exall
	
	OVERDRIVE_3_ULTRA_NULALL = 16777216,         // ultra exall
	OVERDRIVE_3_MIGHTY_NULALL = 33554432,         // gesamtabwehr
	OVERDRIVE_3_MIGHTY_G = 67108864,         // impetus
	OVERDRIVE_3_SUPER_MIGHTY_G = 134217728,         // infusion
	OVERDRIVE_3_HYPER_MIGHTY_G = 268435456,         // unfallschutz
	OVERDRIVE_3_VITALITY = 536870912,         // vital
	OVERDRIVE_3_MEGA_VITALITY = 1073741824,         // super vital
	OVERDRIVE_3_HYPER_VITALITY = 2147483648,         // mega vital
	
	OVERDRIVE_4_MANA = 1,             // mental
	OVERDRIVE_4_MEGA_MANA = 2,           // super mental
	OVERDRIVE_4_HYPER_MANA = 4,           // mega mana
	OVERDRIVE_4_FREEDOM = 8,            // mp freiheit
	OVERDRIVE_4_FREEDOM_X = 16,               // mp freiheit ex
	OVERDRIVE_4_QUARTET_9 = 32,              // quartett 9
	OVERDRIVE_4_TRIO_9999 = 64,             // quartett 99
	OVERDRIVE_4_HERO_DRINK = 128,            // heldentrank
	
	OVERDRIVE_4_MIRACLE_DRINK = 256,           // heerestrank
	OVERDRIVE_4_HOT_SPURS = 512,            // anspornmittel
	OVERDRIVE_4_ECCENTRIC = 1024,          // exzentrequilla
	/*
	OVERDRIVE_4_ = 2048,         // 
	OVERDRIVE_4_ = 4096,    // 
	OVERDRIVE_4_ = 8192,         // 
	OVERDRIVE_4_ = 16384,         // 
	OVERDRIVE_4_ = 32768,         // 
	
	OVERDRIVE_4_ = 65536,         // 
	OVERDRIVE_4_ = 131072,         // 
	OVERDRIVE_4_ = 262144,         // 
	OVERDRIVE_4_ = 524288,         // 
	OVERDRIVE_4_ = 1048576,         // 
	OVERDRIVE_4_ = 2097152,         // 
	OVERDRIVE_4_ = 4194304,         // 
	OVERDRIVE_4_ = 8388608,         // 
	
	OVERDRIVE_4_ = 16777216,         // 
	OVERDRIVE_4_ = 33554432,         // 
	OVERDRIVE_4_ = 67108864,         // 
	OVERDRIVE_4_ = 134217728,         // 
	OVERDRIVE_4_ = 268435456,         // 
	OVERDRIVE_4_ = 536870912,         // 
	OVERDRIVE_4_ = 1073741824,         // 
	OVERDRIVE_4_ = 2147483648,         // 
	*/
};

enum KEY_ITEM_BITMASK
{
	KEY_ITEM_WITHERED_BOUQUET = 1,         // 
	KEY_ITEM_FLINT = 2,         // 
	KEY_ITEM_CLOUDY_MIRROR = 4,         // 
	KEY_ITEM_CELESTIAL_MIRROR = 8,         // 
	KEY_ITEM_AL_BHED_PRIMER_01 = 16,         // 
	KEY_ITEM_AL_BHED_PRIMER_02 = 32,         // 
	KEY_ITEM_AL_BHED_PRIMER_03 = 64,         // 
	KEY_ITEM_AL_BHED_PRIMER_04 = 128,         // 
	
	KEY_ITEM_AL_BHED_PRIMER_05 = 1,         // 
	KEY_ITEM_AL_BHED_PRIMER_06 = 2,         // 
	KEY_ITEM_AL_BHED_PRIMER_07 = 4,         // 
	KEY_ITEM_AL_BHED_PRIMER_08 = 8,         // 
	KEY_ITEM_AL_BHED_PRIMER_09 = 16,    // 
	KEY_ITEM_AL_BHED_PRIMER_10 = 32,         // 
	KEY_ITEM_AL_BHED_PRIMER_11 = 64,         // 
	KEY_ITEM_AL_BHED_PRIMER_12 = 128,         // 
	
	KEY_ITEM_AL_BHED_PRIMER_13 = 1,         // 
	KEY_ITEM_AL_BHED_PRIMER_14 = 2,         // 
	KEY_ITEM_AL_BHED_PRIMER_15 = 4,         // 
	KEY_ITEM_AL_BHED_PRIMER_16 = 8,         // 
	KEY_ITEM_AL_BHED_PRIMER_17 = 16,    // 
	KEY_ITEM_AL_BHED_PRIMER_18 = 32,         // 
	KEY_ITEM_AL_BHED_PRIMER_19 = 64,         // 
	KEY_ITEM_AL_BHED_PRIMER_20 = 128,         // 
	
	KEY_ITEM_AL_BHED_PRIMER_21 = 1,         // 
	KEY_ITEM_AL_BHED_PRIMER_22 = 2,         // 
	KEY_ITEM_AL_BHED_PRIMER_23 = 4,         // 
	KEY_ITEM_AL_BHED_PRIMER_24 = 8,         // 
	KEY_ITEM_AL_BHED_PRIMER_25 = 16,    // 
	KEY_ITEM_AL_BHED_PRIMER_26 = 32,         // 
	KEY_ITEM_SUMMONERS_SOUL = 64,         // 
	KEY_ITEM_AEONS_SOUL = 128,         // 
	
	KEY_ITEM_JECHTS_SPHERE = 1,         // 
	KEY_ITEM_RUSTY_SWORD = 2,         // 
	KEY_ITEM_NOTHING = 4,         // 
	KEY_ITEM_SUN_CREST = 8,         // 
	KEY_ITEM_SUN_SIGIL = 16,    // 
	KEY_ITEM_MOON_CREST = 32,         // 
	KEY_ITEM_MOON_SIGIL = 64,         // 
	KEY_ITEM_MARS_CREST = 128,         // 
	
	KEY_ITEM_MARS_SIGIL = 1,         // 
	KEY_ITEM_MARK_OF_CONQUEST = 2,         // 
	KEY_ITEM_SATURN_CREST = 4,         // 
	KEY_ITEM_SATURN_SIGIL = 8,         // 
	KEY_ITEM_JUPITER_CREST = 16,    // 
	KEY_ITEM_JUPITER_SIGIL = 32,         // 
	KEY_ITEM_VENUS_CREST = 64,         // 
	KEY_ITEM_VENUS_SIGIL = 128,         // 
	
	KEY_ITEM_MERCURY_CREST = 1,         // 
	KEY_ITEM_MERCURY_SIGIL = 2,         // 
	KEY_ITEM_BLOSSOM_CROWN = 4,         // 
	KEY_ITEM_FLOWER_SCEPTRE = 8,         // 
	KEY_ITEM_1 = 16,    // 
	KEY_ITEM_2 = 32,         // 
	KEY_ITEM_3 = 64,         // 
	KEY_ITEM_4 = 128,         // 
};

enum SPECIAL_WEAPON_FLAGS
{
	SWF_AEON_ = 1,
	SWF_HIDDEN = 2,
	SWF_CELESTIAL_OR_AEON = 4,
	SWF_BROTHERHOOD = 8,
};

enum BATTLEDATA_OFFSETS
{
	BD_OFFSET_ANIM_SPEED = -211,
	BD_OFFSET_STAND_AT_LOCATION = -145,
	BD_OFFSET_RUN_TO_LOCATION = 45,
	BD_OFFSET_NAME = 112, // null terminated string
	// enemys have 2 strings
	// player has min 20 chars. rest filled with random names
	
	BD_OFFSET_HP_MAX = -49,
	BD_OFFSET_MP_MAX = -45,
	BD_OFFSET_ATTRIBUTES = -29, // 8 byte
	BD_OFFSET_OVERDRIVE = -9,
	BD_OFFSET_DEATH_COUNTDOWN = 3,
	BD_OFFSET_HP = 11,
	BD_OFFSET_MP = 15,
	BD_OFFSET_CONDITIONS_BITMASK = 65, // short
	BD_OFFSET_SLEEP_CNT = 67,
	BD_OFFSET_SILENCE_CNT = 68,
	BD_OFFSET_69,
	BD_OFFSET_SHELL_CNT = 70,
	BD_OFFSET_PROTECT_CNT = 71,
	BD_OFFSET_REFLECT_CNT = 72,
	BD_OFFSET_WATER_IMMUNITY_CNT = 73,
	BD_OFFSET_FIRE_IMMUNITY_CNT = 74,
	BD_OFFSET_LIGHTNING_IMMUNITY_CNT = 75,
	BD_OFFSET_ICE_IMMUNITY_CNT = 76,
	BD_OFFSET_REGEN_CNT = 77,
	BD_OFFSET_HASTE_CNT = 78,
	BD_OFFSET_SLOW_CNT = 79,
	BD_OFFSET_CONDITION2_BITMASK = 81, // short
	BD_OFFSET_WEAPON_BITMASK_1 = 115, // short (int?)
	BD_OFFSET_TURN_TILL_ACTION = 151,
	BD_OFFSET_WEAPON_BITMASK1 = 247, // uint
	BD_OFFSET_WEAPON_BITMASK2 = 251, // uint
	BD_OFFSET_WEAPON_BITMASK3 = 255, // uint
	BD_OFFSET_WEAPON_BITMASK4 = 259, // uint
	BD_OFFSET_WEAPON_BITMASK5 = 263, // uint (maybe byte)
	
	BD_OFFSET_SPECIAL = 12,
	BD_OFFSET_BATTLE_ACTIVITY = 2051,
};

#define BATTLEDATA_BITMASK1_SIZE 12
#define BATTLEDATA_BITMASK2_SIZE 15
#define BATTLEDATA_BITMASK_SIZE 27
enum BATTLEDATA_BITMASK
{
	BD_KO = 1,
	BD_ZOMBIE = 2,
	BD_PETRIFICATION = 4,
	BD_POISEN = 8,
	BD_POWER_BREAK = 16,
	BD_MAGIC_BREAK = 32,
	BD_ARMOR_BREAK = 64,
	BD_MENTAL_BREAK = 128,
	BD_CONFUSED = 256,
	BD_BERSERK = 512,
	BD_PROVOKE = 1024,
	BD_THREATEN = 2048,
	
	BD2_SCAN = 1,
	BD2_POWER_DESTIL = 2,
	BD2_MANA_DESTIL = 4,
	BD2_SPEED_DESTIL = 8,
	BD2_dummyBM2_16 = 16,
	BD2_ABILITY_DESTIL = 32,
	BD2_SHIELD = 64,
	BD2_BOOST = 128,
	BD2_DIE = 256,
	BD2_AUTOLIFE = 512,
	BD2_CURSE = 1024,
	BD2_DEFEND = 2048,
	BD2_GUARD = 4096,
	BD2_GUARD2 = 8192,
	BD2_DEATH = 16384,
	
	BDW_SENSOR = 1,
	BDW_FIRST_STRIKE = 2,
	//BDW_ = 4,
	//BDW_ = 8,
	//BDW_ = 16,
	//BDW_ = 32,
	BDW_MBOOST = 64,
	//BDW_ = 128,
	BDW_256 = 256,
	BDW_ALCHEMY = 512,
	BDW_AUTO_POTION = 1024,
	BDW_AUTO_MED = 2048,
	BDW_AUTO_PHOENIX = 4096,
	BDW_PIERCING = 8182,
	BDW_HALF_MP_COST = 16384,
	BDW_x = 32768,
	BDW_xx = 65536,
	//BDW_ = 131072,
	BDW_SOS_OVERDRIVE = 262144,
	//BDW_ = 524288,
	//BDW_ = 1048576,
	//BDW_ = 2097152,
	//BDW_ = 4194304,
	//BDW_ = 8388608,
	//BDW_ = 16777216,
	//BDW_ = 33554432,
	//BDW_ = 67108864,
	//BDW_ = 134217728,
	//BDW_ = 268435456,
	//BDW_ = 536870912,
	//BDW_ = 1073741824,
	//BDW_ = 2147483648,
	
	BDW5_FIRESTRIKE = 2,
};

#endif // OFFSETS_HPP
