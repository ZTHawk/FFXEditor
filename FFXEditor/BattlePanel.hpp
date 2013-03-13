#ifndef BATTLE_PANEL_HPP
#define BATTLE_PANEL_HPP

#include "MyPanel.hpp"
#include "ui_BattlePanel.h"

#include <vector>
#include <QThread>

using std::vector;

class BattleData;
typedef struct _BATTLEDATA BATTLEDATA, *PBATTLEDATA;

class BattleDataThread : public QThread
{
public:
	BattleDataThread( int address );
	~BattleDataThread( )
	{
	}
	void run( );
	void stop( );
	
private:
	int address;
	bool running;
};

class BattlePanel : public MyPanel
{
	Q_OBJECT
	
public:
	BattlePanel( QWidget *p );
	~BattlePanel( );
	
	virtual bool reloadData( int depth = 0 );
	virtual bool initData( );
	virtual bool checkData( int depth = 0 );
	virtual bool writeData( int depth = 0 );
	
	void unlock( );
	void lock( );
	
private:
	Ui::BattlePanel ui;
	vector<BattleData*> bData;
	vector<QWidget*> widgetList;
	int bDataSize;
	bool locked;
	BattleDataThread *battleThread;
	int lastIndex;
	
	void findBattleData( );
	bool getVariables( PBATTLEDATA bData );
	void setVariables( PBATTLEDATA bData );
	
protected slots:
	void actorChanged( int index );
	void unlockButtonPressed( );
	void battleOver( );
};

#endif // BATTLE_PANEL_HPP
