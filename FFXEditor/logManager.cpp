#include "logManager.hpp"

#include <QDateTime>

LogManager::LogManager( QString fileName , int lvl )
{
	logLvl = lvl;
	curLogLvl = lvl;
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

int LogManager::getLogLvl( )
{
	return logLvl;
}

void LogManager::setLogLvl( int lvl )
{
	if ( lvl < LOG_DEBUG
		|| lvl > LOG_FATAL )
		return;
	logLvl = lvl;
}

bool LogManager::isActiveLevel( int lvl )
{
	return (lvl >= logLvl);
}

void LogManager::log( QString text )
{
	initStream();
	QDateTime date = QDateTime::currentDateTime();
	*fileStream << date.toString("<yyyy.MM.dd hh:mm:ss> ") << text << "\n";
}

void LogManager::log( std::string text )
{
	log(QString::fromStdString(text));
}

void LogManager::log( std::wstring text )
{
	log(QString::fromStdWString(text));
}

void LogManager::initStream( )
{
	if ( file == NULL )
	{
		file = new QFile(fileName);
		if ( file->open(QIODevice::WriteOnly | QIODevice::Append) == false )
		{
			delete file;
			file = NULL;
			curLogLvl = 9999;
			return;
		}
		fileStream = new QTextStream(file);
	}
}

LogManager& LogManager::operator()( int curLogLvl )
{
	this->curLogLvl = curLogLvl;
	if ( curLogLvl != -1
		&& curLogLvl < logLvl )
		return *this;
	initStream();
	QDateTime date = QDateTime::currentDateTime();
	*fileStream << date.toString("<yyyy.MM.dd hh:mm:ss> ");
	return *this;
}

LogManager& LogManager::operator<<( std::string str )
{
	if ( curLogLvl != -1
		&& curLogLvl < logLvl )
		return *this;
	*fileStream << QString::fromStdString(str);
	return *this;
}

LogManager& LogManager::operator<<( std::wstring str )
{
	if ( curLogLvl != -1
		&& curLogLvl < logLvl )
		return *this;
	*fileStream << QString::fromStdWString(str);
	return *this;
}

LogManager& LogManager::operator<<( unsigned int val )
{
	if ( curLogLvl != -1
		&& curLogLvl < logLvl )
		return *this;
	*fileStream << val;
	return *this;
}

LogManager& LogManager::operator<<( int val )
{
	if ( curLogLvl != -1
		&& curLogLvl < logLvl )
		return *this;
	*fileStream << val;
	return *this;
}

LogManager& LogManager::operator<<( LogFuncs val )
{
	if ( curLogLvl != -1
		&& curLogLvl < logLvl )
		return *this;
	*fileStream << "\n";
	fileStream->flush();
	this->curLogLvl = -1;
	return *this;
}
