#ifndef ITEM_DATA_HPP
#define ITEM_DATA_HPP

#pragma pack(push, before_item_struct)
#pragma pack(1)
typedef struct _ITEM_ID_LIST
{
	unsigned char itemID;
	unsigned char bitmask;
}ITEM_ID_LIST, *PITEM_ID_LIST;
#pragma pack(pop, before_item_struct)

class ItemData
{
public:
	PITEM_ID_LIST itemIDList;
	unsigned char *itemAmountList;
	unsigned char *keyItems;
	unsigned char al_bhed_primer_counter;
	unsigned int al_bhed_primer_bitmask;
	
	bool error;
	
	ItemData( );
	~ItemData( );
	
	void selectKeyItem( unsigned char index , bool selected );
	bool isKeyItemSelect( int index );
	
	bool cheackData( );
	bool readData( );
	bool writeData( );
};

#endif // ITEM_DATA_HPP
