#ifndef OVERDRIVES_PANEL_HPP
#define OVERDRIVES_PANEL_HPP

#include "MyPanel.hpp"
#include "ui_OverdrivesPanel.h"

#include <vector>

using std::vector;

class OverdriveData;

class OverdrivesPanel : public MyPanel
{
	Q_OBJECT
	
public:
	OverdrivesPanel( QWidget *p );
	~OverdrivesPanel( );
	
	virtual bool reloadData( int depth = 0 );
	virtual bool initData( );
	virtual bool checkData( int depth = 0 );
	virtual bool writeData( int depth = 0 );
	
private:
	Ui::OverdrivesPanel ui;
	OverdriveData* overdriveData;
};

#endif // OVERDRIVES_PANEL_HPP
