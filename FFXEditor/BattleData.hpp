#ifndef BATTLE_DATA_HPP
#define BATTLE_DATA_HPP

#pragma pack(push, before_struct)
#pragma pack(1)
typedef struct _BATTLEDATA
{
	unsigned char animSpeed;
	unsigned char standAtLocation;
	unsigned char runToLocation;
}BATTLEDATA, *PBATTLEDATA;
typedef struct _BATTLEDATA2
{
	unsigned int max_hp;
	unsigned int max_mp;
	unsigned char overdrive;
	unsigned int hp;
	unsigned int mp;
	unsigned char hasteAmount;
	unsigned char slowAmount;
	unsigned char turnsTillAction;
	unsigned char disableBattleActivity;
}BATTLEDATA2, *PBATTLEDATA2;
#pragma pack(pop, before_struct)

class BattleData
{
public:
	PBATTLEDATA data;
	PBATTLEDATA2 data2;
	bool error;
	
	BattleData( int addressInit , int address );
	~BattleData( );
	
	bool cheackData( );
	bool readData( );
	bool writeData( );
	
private:
	int address;
	int addressInit;
};

#endif // BATTLE_DATA_HPP
