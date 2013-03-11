#include "BattlePanel.hpp"
#include "BattleData.hpp"
#include "MemMng.hpp"
#include "globals.hpp"
#include "offsets.hpp"
#include "utils.hpp"

BattlePanel::BattlePanel( QWidget *p )
	: MyPanel(p)
{
	ui.setupUi(this);
	
	locked = true;
}

BattlePanel::~BattlePanel( )
{
}

bool BattlePanel::initData( )
{
	return reloadData(0);
}

bool BattlePanel::reloadData( int depth )
{
	if ( locked == true )
		return false;
	
	unsigned int baseEnd = BASE_OFFSET + 30000000;
	int bdCnt = 0;
	int specialChar_lastChar;
	unsigned char identChars[BD_INDENT_LEN];
	unsigned int pos = 1,
		pos2,
		posBase,
		offStart;
	
	offStart = BASE_OFFSET;
	if ( bData.size() == 0 )
		bData.resize(8);
	while ( pos != 0 )
	{
		pos = findOffsetOfByteArray(const_cast<unsigned char*>(battleDataContainerA),
			BATTLE_DATA_CONTAINER_LEN,
			offStart,
			baseEnd);
		if ( pos == 0 )
			break;
		
		// update offset for next loop
		offStart = pos + 4;
		
		pos2 = findOffsetOfByteArray(const_cast<unsigned char*>(battleDataContainerB),
			BATTLE_DATA_CONTAINER_LEN,
			pos + BATTLE_DATA_CONTAINER_DISTANCE,
			pos + BATTLE_DATA_CONTAINER_DISTANCE + BATTLE_DATA_CONTAINER_LEN);
		if ( pos2 == 0 )
			continue;
		
		// possible data found
		// check if player, enemy or something else
		memMng->read(pos + BD_INDENT_OFFSET_FROM_CONT_A,
			identChars,
			BD_INDENT_LEN);
		specialChar_lastChar = BD_INDENT_LEN - 1;
		if ( identChars[specialChar_lastChar] == 0 )
			--specialChar_lastChar;
		if ( identChars[specialChar_lastChar] != BD_IDENT_ENDCHAR )
			continue;
		
		if ( (identChars[0] & BD_IDENT_CHAR_MASK2) == 0
			&& (identChars[1] & BD_IDENT_CHAR_MASK) == 0 )
			continue;
		
		posBase = pos;
		pos = pos2 + BD_COMMON_SEARCH_OFFSET;
		pos2 = findOffsetOfByteArray(const_cast<unsigned char*>(battleData_commonSearch),
			BD_COMMON_SEARCH_LEN,
			pos,
			pos + BD_COMMON_SEARCH_MAX_SEARCH_LEN);
		if ( pos2 == 0 )
			continue;
		
		bData[bdCnt] = new BattleData(posBase, pos2);
		bData[bdCnt]->readData();
		++bdCnt;
		offStart = posBase + BD_CONTAINER_SKIP_LEN;
	}
	return true;
}

bool BattlePanel::checkData( int depth )
{
	bool result = true;
	for ( size_t i = 0; i < bData.size(); ++i )
	{
		if ( bData[i] != NULL )
			result &= bData[i]->cheackData();
	}
	
	return result;
}

bool BattlePanel::writeData( int depth )
{
	bool result = true;
	for ( size_t i = 0; i < bData.size(); ++i )
	{
		if ( bData[i] != NULL )
			result &= bData[i]->writeData();
	}
	
	return result;
}

void BattlePanel::unlock( )
{
	locked = false;
	bData.resize(8);
}

void BattlePanel::lock( )
{
	locked = true;
	bData.clear();
}
