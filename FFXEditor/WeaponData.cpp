#include "constants.hpp"
#include "weapon_constants.hpp"
#include "guiNames.hpp"
#include "WeaponData.hpp"
#include "globals.hpp"
#include "MemMng.hpp"
#include "offsets.hpp"
#include "weapon_constants.hpp"

#if defined _DEBUG
vector<PWEAPONDATA> dataVec;
#endif

WeaponData::WeaponData( )
{
	data = new WEAPONDATA[256];
	memset(data, 0, sizeof(WEAPONDATA) * 256);
	
	error = false;
	curSize = 0;
}

WeaponData::~WeaponData( )
{
	delete data;
}

bool WeaponData::cheackData( )
{
	/*for ( int i = 0; i < WEAPON_MAX_SIZE; ++i )
	{
		// TODO: do not check via model
		// aeon weapons have no model
		//if ( data[i].skin != 0 )
		if ( data[i].destinationCharID < CHAR_COUNT_ALL )
			continue;
		
		data[i].destinationCharID = 0xFF;
		data[i].available = 0;
		data[i].special_properties |= 0x02;
	}*/
	
	return (error == false);
}

bool WeaponData::readData( )
{
	bool result = memMng->read(BASE_OFFSET + OFFSET_WEAPON_DATA, data, sizeof(WEAPONDATA) * WEAPON_MAX_SIZE);
	curSize = 0;
	
	for ( int i = WEAPON_MAX_SIZE - 1; i >= 0; --i )
	{
		if ( validWeaponSlot(i) == false )
			continue;
		
		curSize = i + 1;
		break;
	}
#if defined _DEBUG
	int is = sizeof(WEAPONDATA);
	for ( int i = 0; i < curSize; ++i )
	{
		dataVec.push_back(&data[i]);
	}
#endif
	return result;
}

bool WeaponData::writeData( )
{
	bool result = memMng->write(BASE_OFFSET + OFFSET_WEAPON_DATA, data, sizeof(WEAPONDATA) * WEAPON_MAX_SIZE);
	
	return result;
}

wstring WeaponData::getWeaponName( int index )
{
	if ( data[index].id >= WEAPONS_NAMES_SIZE )
		return guiList[GN_WP_BAD];
	
	if ( data[index].destinationCharID >= CHAR_COUNT )
		return wstring(L"")
			.append(guiList[GN_AP])
			.append(L" ")
			.append(wstring(guiList[data[index].destinationCharID]))
			.append(L" (")
			.append(data[index].isArmor ? guiList[GN_WP_ARM]
				: guiList[GN_WP_WP])
			.append(L")");
	
	if ( data[index].destinationCharID == SEYMOUR )
		return wstring(L"")
		.append(guiList[GN_SEYMOUR])
		.append(L" (")
		.append(data[index].isArmor ? guiList[GN_WP_ARM]
			: guiList[GN_WP_WP])
		.append(L")");
	
	return weaponNames[WEAPONS_NAMES_SIZE * data[index].destinationCharID + data[index].id];
}

bool WeaponData::validWeaponSlot( int index )
{
	return ( data[index].available != 0
			/*&& (data[index].special_properties & 0x02) == 0*/ );
}
