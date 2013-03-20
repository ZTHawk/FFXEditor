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
