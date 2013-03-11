#ifndef CHAR_PANEL_ABILITY_HPP
#define CHAR_PANEL_ABILITY_HPP

#include "MyPanel.hpp"

#include "ui_CharPanelAbility.h"
#include <vector>

using std::vector;

class CharData;
class QListWidget;

class CharPanelAbility : public MyPanel
{
	Q_OBJECT
	
public:
	CharPanelAbility( QWidget *p );
	~CharPanelAbility( );
	
	virtual bool initData( );
	virtual bool reloadData( int depth = 0 );
	virtual bool checkData( int depth = 0 );
	virtual bool writeData( int depth = 0 );
	void SetVariables( CharData *charData );
	bool GetVariables( CharData *charData );
	
private:
	Ui::CharPanelAbility ui;
	vector<QListWidget*> abilityList;
	
protected slots:
	void text_Click( );
};

#endif // CHAR_PANEL_ABILITY_HPP
