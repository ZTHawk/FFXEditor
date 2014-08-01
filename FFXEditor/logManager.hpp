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

#ifndef LOG_MANAGER_HPP
#define LOG_MANAGER_HPP

#include <QFile>
#include <QString>
#include <QTextStream>

#include <string.h>

using std::string;
using std::wstring;

class LogManager
{
private:
	typedef void (*LogFuncs)();
	
public:
	enum LogLvl
	{
		LOG_DEBUG = 0,
		LOG_INFO,
		LOG_WARNING,
		LOG_ERROR,
		LOG_FATAL,
	};
	
	LogManager( QString fileName , int lvl = LOG_WARNING );
	~LogManager( );
	
	void setLogLvl( int lvl );
	
	int getLogLvl( );
	bool isActiveLevel( int lvl = LOG_WARNING );
	void log( LogLvl lvl , QString text );
	void log( QString text );
	void log( std::string text );
	void log( std::wstring text );
	
	LogManager& operator()( int curLogLevel );
	LogManager& operator<<( QString str );
	LogManager& operator<<( std::string str );
	LogManager& operator<<( std::wstring str );
	LogManager& operator<<( unsigned int val );
	LogManager& operator<<( int val );
	LogManager& operator<<( LogFuncs val );
	static void endl( ){};
	
private:
	int logLvl;
	int curLogLvl;
	QString fileName;
	QFile *file;
	QTextStream *fileStream;
	
	void initStream( );
};

#endif // LOG_MANAGER_HPP
