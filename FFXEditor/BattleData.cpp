#include "BattleData.hpp"
#include "constants.hpp"
#include "globals.hpp"
#include "MemMng.hpp"
#include "offsets.hpp"

BattleData::BattleData( int addressInit , int address )
{
	this->address = address;
	this->addressInit = addressInit;
	data = new BATTLEDATA;
	memset(data, 0, sizeof(BATTLEDATA));
	
	error = false;
}

BattleData::~BattleData( )
{
	delete data;
}

bool BattleData::cheackData( )
{
	return (error == false);
}

bool BattleData::readData( )
{
	bool valid;
	if ( memMng->readByte(addressInit, valid) != 0xCD )
		return false;
	
	bool result = true;
	data->animSpeed = memMng->readByte(addressInit + BD_OFFSET_ANIM_SPEED, result);
	data->standAtLocation = memMng->readByte(addressInit + BD_OFFSET_STAND_AT_LOCATION, result);
	data->runToLocation = memMng->readByte(addressInit + BD_OFFSET_RUN_TO_LOCATION, result);
	memMng->read(addressInit + BD_OFFSET_NAME, data->nameBytes, 200);
	
	data->hp_max = memMng->readInt(address + BD_OFFSET_HP_MAX, result);
	data->mp_max = memMng->readInt(address + BD_OFFSET_MP_MAX, result);
	data->overdrive = memMng->readByte(address + BD_OFFSET_OVERDRIVE, result);
	data->deathCountDown = memMng->readShort(address + BD_OFFSET_DEATH_COUNTDOWN, result);
	data->hp = memMng->readInt(address + BD_OFFSET_HP, result);
	data->mp = memMng->readInt(address + BD_OFFSET_MP, result);
	data->conditionMask = memMng->readByte(address + BD_OFFSET_CONDITIONS_BITMASK, result);
	data->sleepCnt = memMng->readByte(address + BD_OFFSET_SLEEP_CNT, result);
	data->silenceCnt = memMng->readByte(address + BD_OFFSET_SILENCE_CNT, result);
	data->shellCnt = memMng->readByte(address + BD_OFFSET_SHELL_CNT, result);
	data->protectCnt = memMng->readByte(address + BD_OFFSET_PROTECT_CNT, result);
	data->reflectCnt = memMng->readByte(address + BD_OFFSET_REFLECT_CNT, result);
	data->waterImmunityCnt = memMng->readByte(address + BD_OFFSET_WATER_IMMUNITY_CNT, result);
	data->fireImmunityCnt = memMng->readByte(address + BD_OFFSET_FIRE_IMMUNITY_CNT, result);
	data->lightningImmunityCnt = memMng->readByte(address + BD_OFFSET_LIGHTNING_IMMUNITY_CNT, result);
	data->iceImmunityCnt = memMng->readByte(address + BD_OFFSET_ICE_IMMUNITY_CNT, result);
	data->regenCnt = memMng->readByte(address + BD_OFFSET_REGEN_CNT, result);
	data->hasteCnt = memMng->readByte(address + BD_OFFSET_HASTE_CNT, result);
	data->slowCnt = memMng->readByte(address + BD_OFFSET_SLOW_CNT, result);
	data->conditionMask2 = memMng->readShort(address + BD_OFFSET_CONDITION2_BITMASK, result);
	data->turnsTillAction = memMng->readByte(address + BD_OFFSET_TURN_TILL_ACTION, result);
	
	int tmpAddress = address;
	if ( langVersion == LANG_US )
		tmpAddress += BD_OFFSET_SPECIAL;
	data->battleActivity = memMng->readByte(tmpAddress + BD_OFFSET_BATTLE_ACTIVITY, result);
	
	return result;
}

bool BattleData::writeData( )
{
	bool result = true;
	result &= memMng->writeByte(addressInit + BD_OFFSET_ANIM_SPEED, data->animSpeed);
	result &= memMng->writeByte(addressInit + BD_OFFSET_STAND_AT_LOCATION, data->standAtLocation);
	result &= memMng->writeByte(addressInit + BD_OFFSET_RUN_TO_LOCATION, data->runToLocation);
	
	result &= memMng->writeInt(address + BD_OFFSET_HP_MAX, data->hp_max);
	result &= memMng->writeInt(address + BD_OFFSET_MP_MAX, data->mp_max);
	result &= memMng->writeByte(address + BD_OFFSET_OVERDRIVE, data->overdrive);
	result &= memMng->writeByte(address + BD_OFFSET_DEATH_COUNTDOWN, data->deathCountDown);
	result &= memMng->writeInt(address + BD_OFFSET_HP, data->hp);
	result &= memMng->writeInt(address + BD_OFFSET_MP, data->mp);
	result &= memMng->writeShort(address + BD_OFFSET_CONDITIONS_BITMASK, data->conditionMask);
	result &= memMng->writeByte(address + BD_OFFSET_SLEEP_CNT, data->sleepCnt);
	result &= memMng->writeByte(address + BD_OFFSET_SILENCE_CNT, data->silenceCnt);
	result &= memMng->writeByte(address + BD_OFFSET_SHELL_CNT, data->shellCnt);
	result &= memMng->writeByte(address + BD_OFFSET_PROTECT_CNT, data->protectCnt);
	result &= memMng->writeByte(address + BD_OFFSET_REFLECT_CNT, data->reflectCnt);
	result &= memMng->writeByte(address + BD_OFFSET_WATER_IMMUNITY_CNT, data->waterImmunityCnt);
	result &= memMng->writeByte(address + BD_OFFSET_FIRE_IMMUNITY_CNT, data->fireImmunityCnt);
	result &= memMng->writeByte(address + BD_OFFSET_LIGHTNING_IMMUNITY_CNT, data->lightningImmunityCnt);
	result &= memMng->writeByte(address + BD_OFFSET_ICE_IMMUNITY_CNT, data->iceImmunityCnt);
	result &= memMng->writeByte(address + BD_OFFSET_REGEN_CNT, data->regenCnt);
	result &= memMng->writeByte(address + BD_OFFSET_HASTE_CNT, data->hasteCnt);
	result &= memMng->writeByte(address + BD_OFFSET_SLOW_CNT, data->slowCnt);
	result &= memMng->writeShort(address + BD_OFFSET_CONDITION2_BITMASK, data->conditionMask2);
	result &= memMng->writeByte(address + BD_OFFSET_TURN_TILL_ACTION, data->turnsTillAction);
	
	int tmpAddress = address;
	if ( langVersion == LANG_US )
		tmpAddress += BD_OFFSET_SPECIAL;
	result &= memMng->writeByte(tmpAddress + BD_OFFSET_BATTLE_ACTIVITY, data->battleActivity);
	
	return result;
}

int BattleData::getInitAdr( )
{
	return addressInit;
}
