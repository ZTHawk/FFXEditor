/*
    FFX-Editor is a cheat tool for PCSX2 and Final Fantasy X.

    Copyright (C) 2014  Karl Zmuda Trzebiatowski <karl.zmuda.trzebiatowski at gmail.com>

	This file is part of FFX-Editor.

    FFX-Editor is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FFX-Editor is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with FFX-Editor; if not, see <http://www.gnu.org/licenses/>.
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
