/*
    FFX-Editor is a cheat tool for PCSX2 and Final Fantasy X.

    Copyright (C) 2014  Karl Zmuda Trzebiatowski <karl.zmuda.trzebiatowski at gmail.com>

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
