#ifndef AEON_PANEL_HPP
#define AEON_PANEL_HPP

#include "MyPanel.hpp"
#include "ui_AeonPanel.h"

#include <vector>

using std::vector;

class CharData;
class QPushButton;

class AeonPanel : public MyPanel
{
	Q_OBJECT
	
public:
	AeonPanel( QWidget *p );
	~AeonPanel( );
	
	virtual bool reloadData( int depth = 0 );
	virtual bool initData( );
	virtual bool checkData( int depth = 0 );
	virtual bool writeData( int depth = 0 );
	
private:
	Ui::AeonPanel ui;
	vector<QPushButton*> buttonsMenu;
	vector<CharData*> aeonData;
	QPushButton *lastButtonClicked;
	int lastButtonID;
	
	bool getVariables( CharData *aeonData );
	void setVariables( CharData *aeonData );
	
protected slots:
	void button_Click( );
	void text_Click( );
};

#endif // AEON_PANEL_HPP
