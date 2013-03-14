#ifndef GUI_NAMES_HPP
#define GUI_NAMES_HPP

#include <vector>
#include <string.h>

using std::wstring;
using std::vector;

enum GUI_NAMES
{
	GN_TIDUS,
	GN_YUNA,
	GN_AURON,
	GN_KIMAHRI,
	GN_WAKKA,
	GN_LULU,
	GN_RIKKU,
	GN_SEYMOUR,
	GN_VALEFOR,
	GN_IFRIT,
	GN_IXION,
	GN_SHIVA,
	GN_BAHAMUT,
	GN_ANIMA,
	GN_YOKIMBO,
	GN_MUG,
	GN_DUG,
	GN_RUG,
	GN_UNKNOWN,
	GN_REL,
		GN_REL_SEC,
		GN_REL_ALL,
	GN_SAVE,
		GN_SAVE_SEC,
		GN_SAVE_ALL,
	GN_CP,
		GN_CP_DATA,
			GN_CP_D_ATT,
			GN_CP_D_DEF,
			GN_CP_D_MAG,
			GN_CP_D_MDEF,
			GN_CP_D_SPD,
			GN_CP_D_LUCK,
			GN_CP_D_EVA,
			GN_CP_D_HIT,
			GN_CP_D_HP,
			GN_CP_D_MP,
			GN_CP_D_AP,
			GN_CP_D_AP_N,
			GN_CP_D_OD,
			GN_CP_D_SLV,
			GN_CP_D_BAT,
			GN_CP_D_KILL,
			GN_CP_D_DEATH,
			GN_CP_D_OD_M,
			GN_CP_D_WAR,
			GN_CP_D_COM,
			GN_CP_D_HEAL,
			GN_CP_D_TAC,
			GN_CP_D_VICM,
			GN_CP_D_DANC,
			GN_CP_D_AVEN,
			GN_CP_D_SLAY,
			GN_CP_D_HERO,
			GN_CP_D_ROOK,
			GN_CP_D_VIC,
			GN_CP_D_COW,
			GN_CP_D_ALLY,
			GN_CP_D_SUF,
			GN_CP_D_DARE,
			GN_CP_D_SOLO,
		GN_CP_ABILITY,
			GN_CP_A_INFO,
	GN_IP,
		GN_IP_ITEM,
		GN_IP_KEYS,
	GN_AP,
		GN_AP_ATT,
		GN_AP_DEF,
		GN_AP_MAG,
		GN_AP_MDEF,
		GN_AP_SPD,
		GN_AP_LUCK,
		GN_AP_EVA,
		GN_AP_HIT,
		GN_AP_AVAIL,
		GN_AP_HP,
		GN_AP_MP,
		GN_AP_KILL,
		GN_AP_DEATH,
		GN_AP_OD,
		GN_AP_BTL,
		GN_AP_ABIL,
	GN_OP,
	GN_WP,
		GN_WP_AVAIL,
		GN_WP_TYPE,
		GN_WP_NAME,
		GN_WP_ISARM,
		GN_WP_EQUIP,
		GN_WP_DMG,
		GN_WP_ATT,
		GN_WP_CRIT,
		GN_WP_MODEL,
		GN_WP_SLOT,
		GN_WP_AB1,
		GN_WP_AB2,
		GN_WP_AB3,
		GN_WP_AB4,
		GN_WP_WP,
		GN_WP_ARM,
		GN_WP_NOONE,
		GN_WP_EMPTY,
		GN_WP_BAD,
		GN_WP_CUSTOM,
		GN_WP_UNKNOWN,
	GN_MP,
		GN_MP_GIL,
	GN_BP,
		GN_BP_UNLOCK,
		GN_BP_LOCK,
		GN_BP_RESCAN,
		GN_BP_ACTIV,
		GN_BP_HP,
		GN_BP_MP,
		GN_BP_OD,
		GN_BP_SLEEP,
		GN_BP_SILENCE,
		GN_BP_SHELL,
		GN_BP_PROT,
		GN_BP_REFLEC,
		GN_BP_WATER,
		GN_BP_FIRE,
		GN_BP_LIGHT,
		GN_BP_ICE,
		GN_BP_REGEN,
		GN_BP_HASTE,
		GN_BP_SLOW,
		GN_BP_COND,
			GN_BP_COND_KO,
			GN_BP_COND_ZOMBIE,
			GN_BP_COND_PETRI,
			GN_BP_COND_POISEN,
			GN_BP_COND_PBREAK,
			GN_BP_COND_MBREAK,
			GN_BP_COND_ABREAK,
			GN_BP_COND_MENBREAK,
			GN_BP_COND_CONFUSED,
			GN_BP_COND_BERSERK,
			GN_BP_COND_PROV,
			GN_BP_COND_THREAT,
			
			GN_BP_COND_SCAN,
			GN_BP_COND_PDEST,
			GN_BP_COND_MDEST,
			GN_BP_COND_SDEST,
			GN_BP_COND_EMPTY,
			GN_BP_COND_ADEST,
			GN_BP_COND_SHIELD,
			GN_BP_COND_BOOST,
			GN_BP_COND_DIE,
			GN_BP_COND_AUTOLIFE,
			GN_BP_COND_CURSE,
			GN_BP_COND_DEFEND,
			GN_BP_COND_GUARD,
			GN_BP_COND_GUARD2,
			GN_BP_COND_DEATH,
		GN_BP_TURNS,
		GN_BP_DEATH_CD,
		GN_BP_ANIMSPD,
		GN_BP_STAND,
		GN_BP_RUN,
};

extern vector<wstring> guiList;
static const char *guiList_en =
	"Tidus\\"
	"Yuna\\"
	"Auron\\"
	"Kimahri\\"
	"Wakka\\"
	"Lulu\\"
	"Rikku\\"
	"Seymour\\"
	"Valefor\\"
	"Ifrit\\"
	"Ixion\\"
	"Shiva\\"
	"Bahamut\\"
	"Anima\\"
	"Yokimbo\\"
	"Mug\\"
	"Dug\\"
	"Rug\\"
	"Unknown\\"
	"Reload\\"
		"Reload Section\\"
		"Reload All\\"
	"Save\\"
		"Save Section\\"
		"Save All\\"
	"Characters\\"
		"Data\\"
			"Attack (Basic / Current)\\"
			"Defense (Basic / Current)\\"
			"Magic (Basic / Current)\\"
			"Magic Defense (Basic / Current)\\"
			"Speed (Basic / Current)\\"
			"Luck (Basic / Current)\\"
			"Evade (Basic / Current)\\"
			"Hit % (Basic / Current)\\"
			"HP (Cur / Max / Base)\\"
			"MP (Cur / Max / Base)\\"
			"AP\\"
			"AP you got till next level\\"
			"Overdrive % (Current / Max)\\"
			"S Lv (Current / Used)\\"
			"Battles\\"
			"Enemys killed\\"
			"Deaths\\"
			"Overdrive Modes\\"
			"Warrior\\"
			"Comrade\\"
			"Healer\\"
			"Tactician\\"
			"Victim\\"
			"Dancer\\"
			"Avenger\\"
			"Slayer\\"
			"Hero\\"
			"Rook\\"
			"Victor\\"
			"Coward\\"
			"Ally\\"
			"Sufferer\\"
			"Daredevil\\"
			"Solo\\"
		"Ability\\"
			"Abilitys\\"
	"Items\\"
		"Items\\"
		"Key Items\\"
	"Aeons\\"
		"Attack (Cur / Add)\\"
		"Defense (Cur / Add)\\"
		"Magic (Cur / Add)\\"
		"Magic Defense (Cur / Add)\\"
		"Speed (Cur / Add)\\"
		"Luck (Cur / Add)\\"
		"Evade (Cur / Add)\\"
		"Hit % (Cur / Add)\\"
		"Available\\"
		"HP (Cur / Max / Add)\\"
		"MP (Cur / Max / Add)\\"
		"Enemys killed\\"
		"Deaths\\"
		"Overdrive % (Cur / Max)\\"
		"Battles before Revive\\"
		"Abilitys\\"
	"Overdrives\\"
	"Weapons\\"
		"Available\\"
		"Weapon Type\\"
		"Weapon Name\\"
		"Is this an armor\\"
		"Equipped on\\"
		"Damage Type\\"
		"Attack\\"
		"Ctritical Hit %\\"
		"Weapon Model\\"
		"Slots\\"
		"Ability 1\\"
		"Ability 2\\"
		"Ability 3\\"
		"Ability 4\\"
		"Weapon\\"
		"Armor\\"
		"No-one\\"
		"------ EMPTY SLOT ------\\"
		"Bad data !!!\\"
		"Custom\\"
		"Unknown\\"
	"Misc\\"
		"Gil\\"
	"Battle\\"
		"Unlock\\"
		"Lock\\"
		"Rescan\\"
		"Active\\"
		"HP (cur / max)\\"
		"MP (cur / max)\\"
		"Overdrive\\"
		"Sleep\\"
		"Silence\\"
		"Shell\\"
		"Protect\\"
		"Reflect\\"
		"Water immunity\\"
		"Fire immunity\\"
		"Lightning immunity\\"
		"Ice immunity\\"
		"Regen\\"
		"Haste\\"
		"Slow\\"
		"Conditions\\"
			"KO\\"
			"Zombie\\"
			"Petrification\\"
			"Poisen\\"
			"Power Break\\"
			"Magic Break\\"
			"Armor Break\\"
			"Mental Break\\"
			"Confused\\"
			"Berserk\\"
			"Provoke\\"
			"Threaten\\"
			"Scan\\"
			"Power Destil.\\"
			"Mana Destil.\\"
			"Speed Destil.\\"
			"-\\"
			"Ability Destil.\\"
			"Shield\\"
			"Boost\\"
			"Die\\"
			"Auto-Life\\"
			"Cursed\\"
			"Defend\\"
			"Guard\\"
			"Guard2\\"
			"Death\\"
		"Turns till action\\"
		"Death countdown\\"
		"Animation speed\\"
		"Stand at location\\"
		"Run to location\\"
	"\0";

#endif // GUI_NAMES_HPP
