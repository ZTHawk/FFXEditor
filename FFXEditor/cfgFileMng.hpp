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

#ifndef _CONFIG_FILE_MNG_HPP_
#define _CONFIG_FILE_MNG_HPP_

#include <list>
#include <string>

using std::list;
using std::wstring;

#include <QString>

class CfgFileMng
{
private:
	struct Tuple
	{
		wstring key;
		wstring value;
		Tuple( wstring a , wstring b )
		{
			key = a;
			value = b;
		};
	};
	wstring fileName;
	list<Tuple> data;
	
public:
	CfgFileMng( const wstring cfgFileName );
	~CfgFileMng( );
	
	bool loadStart( );
	wstring getString( const wstring key , const wstring def = L"" ) const;
	int getInt( const wstring key , const int def = 0 ) const;
	float getFloat( const wstring key , const float def = 0 ) const;
	void loadEnd( );
};

#endif // _CONFIG_FILE_MNG_HPP_
