/*
 Author: Karl Trzebiatowski
 Date: 30.06.2011
*/

#ifndef _STRING_HELPER_HPP_
#define _STRING_HELPER_HPP_

#pragma warning( disable : 4505 )

#include <sstream>
#include <string>

using std::string;
using std::wstring;
using std::wstringstream;

static void trim( string &str )
{
	size_t posE = str.find_last_not_of(" \t");
	if ( posE != string::npos )
	{
		str.erase(str.begin() + posE + 1, str.end());
		size_t posS = str.find_first_not_of(" \t");
		if ( posS != 0 )
			str.erase(0, posS);
	}else
		str.erase(str.begin(), str.end());
};

static wstring fromInt( const int number )
{
   wstringstream ss;
   ss << number;
   return ss.str();
};

#endif // _STRING_HELPER_HPP_
