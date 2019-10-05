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
	
public slots:
	void slotUpdateWeaponOwner( QVector<int> weapOwnerDataVec );
};

#endif // CHAR_PANEL_HPP
