#ifndef BATTLE_DATA_HPP
#define BATTLE_DATA_HPP

typedef struct _BATTLEDATA
{
	unsigned char animSpeed;
	unsigned char standAtLocation;
	unsigned char runToLocation;
	char nameBytes[200];
	
	unsigned int hp_max;
	unsigned int mp_max;
	unsigned char overdrive;
	unsigned char deathCountDown;
	unsigned int hp;
	unsigned int mp;
	unsigned short conditionMask;
	unsigned char sleepCnt;
	unsigned char silenceCnt;
	unsigned char shellCnt;
	unsigned char protectCnt;
	unsigned char reflectCnt;
	unsigned char waterImmunityCnt;
	unsigned char fireImmunityCnt;
	unsigned char lightningImmunityCnt;
	unsigned char iceImmunityCnt;
	unsigned char regenCnt;
	unsigned char hasteCnt;
	unsigned char slowCnt;
	unsigned short conditionMask2;
	unsigned char turnsTillAction;
	unsigned char battleActivity;
}BATTLEDATA, *PBATTLEDATA;

class BattleData
{
public:
	PBATTLEDATA data;
	bool error;
	
	BattleData( int addressInit , int address );
	~BattleData( );
	
	bool cheackData( );
	bool readData( );
	bool writeData( );
	int getInitAdr( );
	
private:
	int address;
	int addressInit;
};

#endif // BATTLE_DATA_HPP
