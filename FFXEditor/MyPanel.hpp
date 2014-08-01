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

#ifndef MY_PANEL_HPP
#define MY_PANEL_HPP

#include "utils.hpp"
#include "iostream"

#include <QByteArray>
#include <QLineEdit>
#include <QPalette>
#include <QString>
#include <QWidget>

class MyPanel : public QWidget
{
public:
	MyPanel( QWidget *p )
		: QWidget(p)
	{
	};
	
	virtual bool initData( ) = 0;
	virtual bool reloadData( int depth = 0 ) = 0;
	virtual bool checkData( int depth = 0 ) = 0;
	virtual bool writeData( int depth = 0 ) = 0;
	bool checkEntry( QLineEdit *textBox , void *buf , int type );
	
protected:
	class ButtonData : public QObjectUserData
	{
	public:
		ButtonData( )
		{
		};
		ButtonData( int id )
		{
			infoID = id;
		};
		int infoID;
	};
};

#endif // MY_PANEL_HPP
