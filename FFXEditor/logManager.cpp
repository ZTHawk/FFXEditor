#include "logManager.hpp"

#include <QDateTime>

LogManager::LogManager( QString fileName , LogLvl lvl )
{
	logLvl = lvl;
	file = NULL;
	fileStream = NULL;
	this->fileName = fileName;
}

LogManager::~LogManager( )
{
	if ( fileStream != NULL )
		delete fileStream;
	if ( file != NULL )
	{
		file->close();
		delete file;
	}
}

LogManager::LogLvl LogManager::getLogLvl( )
{
	return logLvl;
}

void LogManager::setLogLvl( LogLvl lvl )
{
	logLvl = lvl;
}

void LogManager::setLogLvl( int lvl )
{
	if ( lvl < LOG_DEBUG
		|| lvl > LOG_FATAL )
		return;
	logLvl = (LogManager::LogLvl)lvl;
}

bool LogManager::isActiveLevel( LogLvl lvl )
{
	return (lvl >= logLvl);
}

void LogManager::log( QString text )
{
	if ( file == NULL )
	{
		file = new QFile(fileName);
		if ( file->open(QIODevice::WriteOnly | QIODevice::Append) == false )
		{
			delete file;
			file = NULL;
			return;
		}
		fileStream = new QTextStream(file);
	}
	QDateTime date = QDateTime::currentDateTime();
	*fileStream << date.toString("<yyyy.MM.dd hh:mm:ss> ") << text << "\n";
}
