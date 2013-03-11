#include "CharData.hpp"
#include "constants.hpp"
#include "globals.hpp"
#include "MemMng.hpp"
#include "offsets.hpp"

CharData::CharData( int charID )
{
	this->charID = charID;
	
	data = new CHARDATA;
	memset(data, 0, sizeof(CHARDATA));
	
	error = false;
}

CharData::~CharData( )
{
	delete data;
}

bool CharData::cheackData( )
{
	return (error == false);
}

bool CharData::readData( )
{
	bool result = memMng->read(BASE_OFFSET + char_offsets[charID], data, sizeof(CHARDATA));
	
	return result;
}

bool CharData::writeData( )
{
	bool result = memMng->write(BASE_OFFSET + char_offsets[charID], data, sizeof(CHARDATA));
	
	return result;
}
