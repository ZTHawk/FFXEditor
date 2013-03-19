#ifndef LOG_MANAGER_HPP
#define LOG_MANAGER_HPP

#include <QFile>
#include <QString>
#include <QTextStream>

class LogManager
{
public:
	enum LogLvl
	{
		LOG_DEBUG = 0,
		LOG_INFO,
		LOG_WARNING,
		LOG_ERROR,
		LOG_FATAL,
	};
	
	LogManager( QString fileName , LogLvl lvl = LOG_WARNING );
	~LogManager( );
	
	void setLogLvl( LogLvl lvl );
	void setLogLvl( int lvl );
	
	LogManager::LogLvl getLogLvl( );
	bool isActiveLevel( LogLvl lvl = LOG_WARNING );
	void log( LogLvl lvl , QString text );
	void log( QString text );
	
private:
	LogLvl logLvl;
	QString fileName;
	QFile *file;
	QTextStream *fileStream;
};

#endif // LOG_MANAGER_HPP
