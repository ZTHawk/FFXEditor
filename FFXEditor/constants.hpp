#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include "offsets.hpp"
#include "limits.h"
#include <vector>
#include <string.h>

using std::wstring;
using std::vector;

#define FRAME_WIDTH  640
#define FRAME_HEIGHT 560

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

enum
{
	TAB_GLOBAL = 0,
	
	TAB_CHAR_START,
	TAB_TIDUS = TAB_CHAR_START,
	TAB_YUNA,
	TAB_AURON,
	TAB_KIMAHRI,
	TAB_WAKKA,
	TAB_LULU,
	TAB_RIKKU
};

#define AEON_COUNT 10

const static int char_offsets[] =
{
	OFFSET_TIDUS,
	OFFSET_YUNA,
	OFFSET_AURON,
	OFFSET_KIMAHRI,
	OFFSET_WAKKA,
	OFFSET_LULU,
	OFFSET_RIKKU,
	OFFSET_SEYMOUR,
	OFFSET_AEON_VALEFOR,
	OFFSET_AEON_IFRIT,
	OFFSET_AEON_IXION,
	OFFSET_AEON_SHIVA,
	OFFSET_AEON_BAHAMUT,
	OFFSET_AEON_ANIMA,
	OFFSET_AEON_YOJIMBO,
	OFFSET_AEON_MUG,
	OFFSET_AEON_DUG,
	OFFSET_AEON_RUG
};

#define AEON_AVAILABLE_VALUE  0x11

enum MAX_DATA_VALUES
{
	// these values have to be sorted !!
	DATA_ITEM = 99,
	DATA_ATTRIBUTE = 255,
	DATA_UCHAR = UCHAR_MAX,
	
	DATA_OD_MODES = 65535,
	DATA_USHORT = USHRT_MAX,
	
	DATA_MP = 9999999, // default max is 9999
	DATA_HP = 9999999, // default max is 99999
	DATA_BITMASK = UINT_MAX,
	DATA_UINT = UINT_MAX,
};

typedef struct _CHAR_BASIC_ATTRIBUTES
{
	unsigned char attack;
	unsigned char defense;
	unsigned char magic;
	unsigned char magicDef;
	unsigned char speed;
	unsigned char luck;
	unsigned char evade;
	unsigned char hit;
}CHAR_BASIC_ATTRIBUTES, *PCHAR_BASIC_ATTRIBUTES;
const static CHAR_BASIC_ATTRIBUTES char_basic_sttributes[] =
{
	{15, 10, 5, 5, 10, 18, 5, 5},
	{5, 5, 20, 20, 10, 17, 30, 3},
	{20, 15, 5, 5, 5, 17, 5, 3},
	{16, 15, 17, 5, 6, 18, 5, 5},
	{14, 10, 10, 5, 7, 19, 5, 25},
	{5, 8, 20, 30, 5, 17, 40, 3},
	{10, 8, 10, 8, 16, 18, 5, 5}
};

enum LANGUAGE_VERSIONS
{
	LANG_UNKNOWN = 0,
	LANG_DE = 1,
	LANG_EN = 2,
	LANG_ES = 3,
	LANG_INT = 4,
	LANG_US = 5,
	LANG_JP = 6,
};

const static char *emulatorName = "pcsx2";

#endif // CONSTANTS_HPP
