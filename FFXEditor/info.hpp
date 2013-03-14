#ifndef INFO_HPP
#define INFO_HPP

#include <vector>
#include <string.h>

using std::wstring;
using std::vector;

enum INFO
{
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
};

extern vector<wstring> infoList;
static const char *infoList_en =
	"This box shows additional info. Just click a text to get more information about it.\n"
		"Do not use this while in a battle. Wait untill the fight is over, then hit \"Reload\" and modify as you wish.\\"
	"MaxValue: 255\nThe \"Basic\" value is the initial character value.\n"
		"\"Current\" shows your current attack including Sphere settings.\n"
		"Modifying \"Current\" does not do anything. It is updated once you enter Status menu.\\"
	"MaxValue: 99999\n\"Cur\" are your actual HP.\n"
		"\"Max\" defines how many HP you can have.\n"
		"\"Base\" defines the default max HP you have without upgrades.\n"
		"Note: If \"Base\" is lower than \"Max\" then \"Max\" will be reseted to \"Base\"\\"
	"MaxValue: 9999\n\"Cur\" are your actual MP.\n"
		"\"Max\" defines how many MP you can have.\n"
		"\"Base\" defines the default max MP you have without upgrades.\n"
		"Note: If \"Base\" is lower than \"Max\" then \"Max\" will be reseted to \"Base\"\\"
	"This value represents the AP you earned till now.\n"
		"Modifying this value does not increase S Lv\\"
	"This is NOT the amount of AP you need till next S.Lv but the amount you got on your way till next S.Lv.\n"
		"This is like a bank acount: Once this value is bigger than the amount needed till next S.Lv.\n"
		"It will be substracted from this value and you get one S.Lv.\n"
		"So if this value is pretty high you can get many S.Lv.\\"
	"MaxValue: 255\n\"Current\" show the current Overdrive Points.\n"
		"\"Max\" defines how many points are needed till Overdrive is available.\n"
		"Modifying the value \"Max\" is not recommended as is can result not being able use Overdrives untill you switch it back.\n"
		"But you can set \"Current\" to 200 so you can execute two Overdrives. (This only works once. Use FFX Editor again)\\"
	"MaxValue: 255\n\"Current\" defines how many S Lv points you have left.\n"
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
	
	"MaxValue: 255\n\"Current\" shows your current attack.\n"
		"\"Add\" defines how many points have been added to this attribute.\n"
		"It is updated once you enter Status menu.\\"
	"MaxValue: 99999\n\"Cur\" are your actual HP.\n"
		"\"Max\" defines how many HP that aeon can have.\n"
		"\"Add\" defines how many HP have been added.\n"
		"Info: Reviving a dead aeon by increasing the HP will also need to reset \"Battles befor Revive\" value\\"
	"MaxValue: 9999\n\"Cur\" are your actual MP.\n"
		"\"Max\" defines how many MP you can have.\n"
		"\"Add\" defines how many MP have been added.\\"
	"Determines how many enemys this aeon has killed.\n"
		"Only the final hit counts.\\"
	"Determines how often this aeon died.\\"
	"Determines how many battles you need to fight before this aeon can be sumoned again.\\"
	"Using \"Custom\" model index is dangerous. Save your game before editing.\n"
		"Some models will crash when entering a battle and others do when doing an attack.\\"
	"\0";

#endif // INFO_HPP
