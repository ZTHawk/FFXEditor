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

#ifndef WEAPON_PANEL_HPP
#define WEAPON_PANEL_HPP

#include "MyPanel.hpp"
#include "ui_WeaponPanel.h"

#include <vector>

using std::vector;

class QComboBox;
class WeaponData;
typedef struct _WEAPONDATA WEAPONDATA, *PWEAPONDATA;

class WeaponPanel : public MyPanel
{
	Q_OBJECT

public:
	WeaponPanel( QWidget *p );
	~WeaponPanel( );
	
	virtual bool reloadData( int depth = 0 );
	virtual bool initData( );
	virtual bool checkData( int depth = 0 );
	virtual bool writeData( int depth = 0 );
	
private:
	Ui::WeaponPanel ui;
	WeaponData *weaponData;
	vector<QComboBox*> abilityList;
	int lastSelectedIndex;
	int lastSelectedWeaponsNameIndex;
	
	bool getVariables( PWEAPONDATA wData );
	void setVariables( WEAPONDATA wData );
	int arrayIndexToWeaponModelIndex( int index );
	int weaponModelIndexToArrayIndex( unsigned short weaponModelIndex );
	
signals:
	void updateWeaponOwner( QVector<int> weapOwnerDataVec );
	
protected slots:
	void text_Click( );
	void slotSelection_SelectedIndexChanged( int index );
	void weaponSlotCnt_SelectedIndexChanged( int index );
	void weaponType_SelectedIndexChanged( int index );
	void weaponModel_SelectedIndexChanged( int index );
	void weaponName_SelectedIndexChanged( int index );
};

#endif // WEAPON_PANEL_HPP
