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

#include "cfgFileMng.hpp"
#include "string_helper.hpp"

#include <QFile>
#include <QString>
#include <QTextStream>

CfgFileMng::CfgFileMng( const wstring cfgFileName )
{
	fileName = cfgFileName;
}

CfgFileMng::~CfgFileMng( )
{
	
}

bool CfgFileMng::loadStart( )
{
	QFile f(QString::fromStdWString(fileName));
	if ( f.open(QIODevice::ReadOnly | QIODevice::Text) == false )
		return false;
	
	QTextStream in(&f);
	QString line,
		key,
		value;
	int pos;
	while ( in.atEnd() == false )
	{
		line = in.readLine();
		// empty or no valid data
		if ( line.size() < 3 )
			continue;
		
		line = line.trimmed();
		// comment
		if ( line.startsWith("#") == true )
			continue;
		
		pos = line.indexOf('=');
		if ( pos == -1 )
			continue;
		
		key = line.left(pos);
		value = line.mid(pos + 1);
		
		key = key.trimmed();
		value = value.trimmed().replace("\\n", "\n");
		
		Tuple tup(key.toStdWString(), value.toStdWString());
		data.push_back(tup);
	}
	f.close();
	
	return true;
}

wstring CfgFileMng::getString( const wstring key , const wstring def ) const
{
	list<Tuple>::const_iterator it = data.begin();
	while ( it != data.end() )
	{
		if ( key.compare(it->key) != 0 )
		{
			++it;
			continue;
		}
		if ( it->value.size() == 0 )
			return def;
		return it->value;
	}
	return def;
}

int CfgFileMng::getInt( const wstring key , const int def ) const
{
	wstring value = getString(key);
	if ( value.size() == 0 )
		return def;
	return _wtoi(value.c_str());
}

float CfgFileMng::getFloat( const wstring key , const float def ) const
{
	wstring value = getString(key);
	if ( value.size() == 0 )
		return def;
	return _wtof(value.c_str());
}

void CfgFileMng::loadEnd( )
{
	data.clear();
}
