/*
 Author: Karl Trzebiatowski
 Date: 30.06.2011
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
		value = value.trimmed();
		
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
