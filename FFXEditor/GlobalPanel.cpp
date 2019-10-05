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

#include "constants.hpp"
#include "guiNames.hpp"
#include "GlobalPanel.hpp"
#include "globals.hpp"
#include "offsets.hpp"
#include "MemMng.hpp"
#include "utils.hpp"

GlobalPanel::GlobalPanel( QWidget *p )
	: MyPanel(p)
{
	ui.setupUi(this);
	
	gilNum = 0;
	
	ui.gil_Text->setText(QString::fromStdWString(guiList[GN_MP_GIL]));
	
#ifdef _DEBUG
	connect(ui.t, SIGNAL(textChanged()), this, SLOT(tEdit()));
	connect(ui.tf, SIGNAL(textChanged()), this, SLOT(tfEdit()));
#else
	ui.t->setVisible(false);
	ui.tf->setVisible(false);
#endif
	
	checkData(2);
}

GlobalPanel::~GlobalPanel( )
{
	
}

bool GlobalPanel::initData( )
{
	return reloadData(0);
}

bool GlobalPanel::reloadData( int depth )
{
	bool result = true;
	
	gilNum = memMng->readInt(BASE_OFFSET + OFFSET_GIL, result);
	if ( result == true )
		ui.gil->setText(QString::number(gilNum));
	
	return result;
}

bool GlobalPanel::checkData( int depth )
{
	bool result = true;
	
	result &= checkEntry(ui.gil, &gilNum, DATA_UINT);
	
	return result;
}

bool GlobalPanel::writeData( int depth )
{
	bool result = true;
	
	result &= memMng->writeInt(BASE_OFFSET + OFFSET_GIL, gilNum);
	
	return result;
}

#ifdef _DEBUG
bool editing = false;
void GlobalPanel::tEdit( )
{
	if ( editing == true )
		return;
	QString str = ui.t->toPlainText();
	if ( str.size() % 2 == 1 )
		return;
	QByteArray arr;
	arr.resize(str.size() / 2);
	for ( int i = 0; i < str.size(); i += 2 )
	{
		arr[i / 2] = str.mid(i, 2).toInt(NULL, 16);
	}
	QString newStr = QString::fromStdWString(asciiFFX_ascii(arr.data()));
	editing = true;
	ui.tf->setPlainText(newStr);
	editing = false;
}

void GlobalPanel::tfEdit( )
{
	if ( editing == true )
		return;
	QString str = ui.tf->toPlainText();
	std::wstring wStr = str.toStdWString();
	unsigned char *cStr = ascii_asciiFFX(wStr);
	QByteArray arr((char*)cStr);
	QString newStr;
	for ( int i = 0; i < arr.size(); ++i )
	{
		newStr.push_back(QString::number((unsigned char)arr[i], 16).rightJustified(2, '0'));
	}
	delete cStr;
	editing = true;
	ui.t->setPlainText(newStr);
	editing = false;
}
#else
void GlobalPanel::tEdit( ){}
void GlobalPanel::tfEdit( ){}
#endif
