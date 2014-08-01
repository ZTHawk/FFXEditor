#include "OverdriveData.hpp"
#include "globals.hpp"
#include "MemMng.hpp"
#include "offsets.hpp"
#include "weapon_constants.hpp"

OverdriveData::OverdriveData( )
{
	overdrive_list = new unsigned int[4];
	
	error = false;
}

OverdriveData::~OverdriveData( )
{
	delete overdrive_list;
}

bool OverdriveData::cheackData( )
{
	return (error == false);
}

bool OverdriveData::readData( )
{
	bool result = memMng->read(BASE_OFFSET + OFFSET_OVERDRIVES_BITMASK, overdrive_list, sizeof(unsigned int) * 4) != -1;
	
	return result;
}

bool OverdriveData::writeData( )
{
	bool result = memMng->write(BASE_OFFSET + OFFSET_OVERDRIVES_BITMASK, overdrive_list, sizeof(unsigned int) * 4);
	
	return result;
}
