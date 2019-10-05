/*
    FFX-Editor is a cheat tool for PCSX2 and Final Fantasy X.

    Copyright (C) 2014  Karol von Zmuda Trzebiatowski <karol.von.zmuda.trzebiatowski at gmail.com>

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
	
	bool unlock( );
	void lock( );
	
private:
	Ui::BattlePanel ui;
	vector<BattleData*> bData;
	bool locked;
	BattleDataThread *battleThread;
	int lastIndex;
	
	bool findBattleData( );
	bool getVariables( PBATTLEDATA bData );
	void setVariables( PBATTLEDATA bData );
	
protected slots:
	void actorChanged( int index );
	void unlockButtonPressed( );
	void lockButtonPressed( );
	void rescanButtonPressed( );
	void battleOver( );
	void text_Click( );
};

#endif // BATTLE_PANEL_HPP
