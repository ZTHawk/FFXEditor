#ifndef CHAR_PANEL_DATA_HPP
#define CHAR_PANEL_DATA_HPP

#include "MyPanel.hpp"
#include "ui_CharPanelData.h"

class CharData;

class CharPanelData : public MyPanel
{
	Q_OBJECT
	
public:
	CharPanelData( QWidget *p );
	~CharPanelData( );
	
	virtual bool initData( );
	virtual bool reloadData( int depth = 0 );
	virtual bool checkData( int depth = 0 );
	virtual bool writeData( int depth = 0 );
	void SetVariables( CharData *charData );
	bool GetVariables( CharData *charData );
	
	char ID;
	
private:
	Ui::CharPanelData ui;
	
public slots:
	void text_Click( );
};

#endif // CHAR_PANEL_DATA_HPP
