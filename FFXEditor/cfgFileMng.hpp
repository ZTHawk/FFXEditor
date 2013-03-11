/*
 Author: Karl Trzebiatowski
 Date: 30.06.2011
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
