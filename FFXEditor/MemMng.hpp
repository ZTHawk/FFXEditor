#ifndef MEM_MNG_HPP
#define MEM_MNG_HPP

class MemMng
{
public:
	MemMng( );
	~MemMng( );
	
	bool init( int procID );
	
	bool read( int address , void *buf , int len );
	int readInt( int address , bool &result );
	short readShort( int address , bool &result );
	unsigned char readByte( int address , bool &result );
	bool write( int address , void *buf , int len );
	bool writeInt( int address , int value );
	bool writeShort( int address , short value );
	bool writeByte( int address , unsigned char value );
	
private:
	int hProcess;
};

extern MemMng *memMng;

#endif // MEM_MNG_HPP
