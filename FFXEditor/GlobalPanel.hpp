#ifndef GLOBAL_PANEL_HPP
#define GLOBAL_PANEL_HPP

#include "MyPanel.hpp"
#include "ui_GlobalPanel.h"

class GlobalPanel : public MyPanel
{
	Q_OBJECT
	
public:
	GlobalPanel( QWidget *p );
	~GlobalPanel( );
	
	virtual bool reloadData( int depth = 0 );
	virtual bool initData( );
	virtual bool checkData( int depth = 0 );
	virtual bool writeData( int depth = 0 );
	
private:
	Ui::GlobalPanel ui;
	int gilNum;
};

#endif // GLOBAL_PANEL_HPP
