#ifndef PROCESS_MNG_HPP
#define PROCESS_MNG_HPP

void FindProcess( );
void ProcClose( int handle );
int ProcOpen( int procID );
bool ProcReadMem( int handle , int address , void *buf , int len , int &bytesRead );
bool ProcWriteMem( int handle , int address , void *buf , int len , int &bytesWritten );

bool readFromProcess( int address , void *buf , int len );
int readIntFromProcess( int address , bool &result );
short readShortFromProcess( int address , bool &result );
unsigned char readByteFromProcess( int address , bool &result );
bool writeToProcess( int address , void *buf , int len );
bool writeIntToProcess( int address , int value );
bool writeShortToProcess( int address , short value );
bool writeByteToProcess( int address , unsigned char value );

#endif // PROCESS_MNG_HPP
