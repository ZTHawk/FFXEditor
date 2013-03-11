#ifndef CHAR_PANEL_HPP
#define CHAR_PANEL_HPP

#include "MyPanel.hpp"
#include "ui_CharPanel.h"

#include <vector>

using std::vector;

class CharData;
class CharPanelData;
class CharPanelAbility;
class QPushButton;

class CharPanel : public MyPanel
{
	Q_OBJECT
	
public:
	CharPanel( QWidget *p );
	~CharPanel( );
	
	virtual bool reloadData( int depth = 0 );
	virtual bool initData( );
	virtual bool checkData( int depth = 0 );
	virtual bool writeData( int depth = 0 );
	
private:
	Ui::CharPanel ui;
	
	bool reloadData( bool init );
	CharPanelData *charPanelData;
	CharPanelAbility *charPanelAbility;
	vector<CharData*> charData;
	vector<QPushButton*> buttonsMenu;
	vector<MyPanel*> panelsMenu;
	QPushButton *lastButtonClicked;
	int lastButtonID;
	
protected slots:
	void buttonClicked( );
	void menuBoxSelectedIndexChanged( int index );
};

#endif // CHAR_PANEL_HPP
