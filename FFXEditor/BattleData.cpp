#include "BattleData.hpp"
#include "globals.hpp"
#include "MemMng.hpp"
#include "offsets.hpp"

BattleData::BattleData( int addressInit , int address )
{
	this->address = address;
	this->addressInit = addressInit;
	data = new BATTLEDATA;
	memset(data, 0, sizeof(BATTLEDATA));
	data2 = new BATTLEDATA2;
	memset(data, 0, sizeof(BATTLEDATA2));
	
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
	
	data2->max_hp = memMng->readInt(address + BD_OFFSET_HP_MAX, result);
	data2->max_mp = memMng->readInt(address + BD_OFFSET_MP_MAX, result);
	data2->overdrive = memMng->readByte(address + BD_OFFSET_OVERDRIVE, result);
	data2->hp = memMng->readInt(address + BD_OFFSET_HP, result);
	data2->mp = memMng->readInt(address + BD_OFFSET_MP, result);
	data2->hasteAmount = memMng->readByte(address + BD_OFFSET_HASTE_AMOUNT, result);
	data2->slowAmount = memMng->readByte(address + BD_OFFSET_SLOW_AMOUNT, result);
	data2->turnsTillAction = memMng->readByte(address + BD_OFFSET_TURN_TILL_ACTION, result);
	data2->disableBattleActivity = memMng->readByte(address + BD_OFFSET_DISABLE_ACTIVITY, result);
	
	return result;
}

bool BattleData::writeData( )
{
	bool result = true;
	result &= memMng->writeByte(addressInit + BD_OFFSET_ANIM_SPEED, data->animSpeed);
	result &= memMng->writeByte(addressInit + BD_OFFSET_STAND_AT_LOCATION, data->standAtLocation);
	result &= memMng->writeByte(addressInit + BD_OFFSET_RUN_TO_LOCATION, data->runToLocation);
	
	result &= memMng->writeInt(address + BD_OFFSET_HP_MAX, data2->max_hp);
	result &= memMng->writeInt(address + BD_OFFSET_MP_MAX, data2->max_mp);
	result &= memMng->writeByte(address + BD_OFFSET_OVERDRIVE, data2->overdrive);
	result &= memMng->writeInt(address + BD_OFFSET_HP, data2->hp);
	result &= memMng->writeInt(address + BD_OFFSET_MP, data2->mp);
	result &= memMng->writeByte(address + BD_OFFSET_HASTE_AMOUNT, data2->hasteAmount);
	result &= memMng->writeByte(address + BD_OFFSET_SLOW_AMOUNT, data2->slowAmount);
	result &= memMng->writeByte(address + BD_OFFSET_TURN_TILL_ACTION, data2->turnsTillAction);
	result &= memMng->writeByte(address + BD_OFFSET_DISABLE_ACTIVITY, data2->disableBattleActivity);
	
	return result;
}
