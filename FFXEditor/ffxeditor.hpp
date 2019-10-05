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

#ifndef FFXEDITOR_HPP
#define FFXEDITOR_HPP

#include <QMainWindow>
#include "ui_ffxeditor.h"

#include <vector>

using std::vector;

class MyPanel;
class CfgFileMng;

class FFXEditor : public QMainWindow
{
	Q_OBJECT
	
public:
	FFXEditor(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~FFXEditor();
	
	void init( CfgFileMng *cfgFileMng );
	void setInfo( QString msg );
	
private:
	enum PANEL_INDEXES
	{
		PANEL_CHAR = 0,
		PANEL_ITEM,
		PANEL_AEON,
		PANEL_OVERDRIVE,
		PANEL_WEAPON,
		PANEL_GLOBAL,
		PANEL_BATTLE,
		
		PANEL_COUNT,
	};
	Ui::FFXEditorClass ui;
	vector<MyPanel*> panelsMenu;
	
	void initData( bool errorOccured );
	void initNames( );
	void initGUINames( );
	void initInfoNames( );
	void initOverdriveNames( );
	void initAbilityNames( );
	void initItemNames( );
	void initKeyItemNames( );
	void initModelNames( );
	void initWeaponAbilityNames( );
	void initWeaponDmgTypeNames( );
	void initWeaponNames( );
	void addModelNameData( std::wstring name , int id );
	
public slots:
	void reloadButton_Click( );
	void SaveButton_Click( );
	void reloadButtonSection_Click( );
	void saveButtonSection_Click( );
	void reloadButtonAll_Click( );
	void saveButtonAll_Click( );
	void menuBox_SelectedIndexChanged( int index );
};

#endif // FFXEDITOR_HPP
