#ifndef OVERDRIVE_DATA_HPP
#define OVERDRIVE_DATA_HPP

class OverdriveData
{
public:
	unsigned int *overdrive_list;
	bool error;
	
	OverdriveData( );
	~OverdriveData( );
	
	bool cheackData( );
	bool readData( );
	bool writeData( );
};

#endif // OVERDRIVE_DATA_HPP
