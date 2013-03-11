#ifndef UTILS_HPP
#define UTILS_HPP

#include "iostream"
#include <string.h>
#include <vector>

#include <QPoint>
#include <QString>

using std::wstring;
using std::vector;

void SendNotification( QString msg );
void SendNotification( char *msg );
void SendNotificationID( int msgID );

char* strstrCaseIn( char *str1 , const char *str2 , bool isUnicode = false );
bool containsNoneDigits( const char *text );

bool stringToValue_Check( const char *text , void *buf , unsigned int numByType );

void setBitmask( unsigned int &target , unsigned int mask , bool set );
void setBitmask( unsigned char &target , unsigned char mask , bool set );

unsigned int findOffsetOfByteArray( const unsigned char byteArray[] , const int byteArrayLen , unsigned int searchOffset = 0x02000000 , unsigned int searchOffsetEnd = 0x3FFFFFFF );

void parseCharArrayToStringVector( const char *charArray , vector<wstring> &stringVec );

wstring asciiFFX_ascii( char *str );
unsigned char* ascii_asciiFFX( wstring str );

#endif // UTILS_HPP
