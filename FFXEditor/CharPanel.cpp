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

#include "CharPanel.hpp"
#include "constants.hpp"
#include "guiNames.hpp"
#include "info.hpp"
#include "CharData.hpp"
#include "CharPanelData.hpp"
#include "CharPanelAbility.hpp"
#include "globals.hpp"

#include <QPushButton>

CharPanel::CharPanel( QWidget *p )
	: MyPanel(p)
{
	ui.setupUi(this);
	
	lastButtonClicked = NULL;
	lastButtonID = 0;
	
	charData.resize(CHAR_COUNT);
	buttonsMenu.resize(CHAR_COUNT);
	charPanelData = new CharPanelData(ui.container);
	charPanelAbility = new CharPanelAbility(ui.container);
	charPanelAbility->setVisible(false);
	
	panelsMenu.push_back(charPanelData);
	panelsMenu.push_back(charPanelAbility);
	
	buttonsMenu[TIDUS] = ui.button_Tidus;
	buttonsMenu[YUNA] = ui.button_Yuna;
	buttonsMenu[AURON] = ui.button_Auron;
	buttonsMenu[KIMAHRI] = ui.button_Kimahri;
	buttonsMenu[WAKKA] = ui.button_Wakka;
	buttonsMenu[LULU] = ui.button_Lulu;
	buttonsMenu[RIKKU] = ui.button_Rikku;
	buttonsMenu[SEYMOUR] = ui.button_Seymour;
	
	int i;
	for ( i = 0; i < CHAR_COUNT; ++i )
		charData[i] = new CharData(i);
	
	ui.categoryMenu->addItems(QStringList()
		<< QString::fromStdWString(guiList[GN_CP_DATA])
		<< QString::fromStdWString(guiList[GN_CP_ABILITY])
		);
	
	ui.categoryMenu->setCurrentIndex(0);
	
	for ( i = 0; i < CHAR_COUNT; ++i )
	{
		buttonsMenu[i]->setText(QString::fromStdWString(guiList[GN_TIDUS + i]));
		connect(buttonsMenu[i], SIGNAL(clicked(bool)), this, SLOT(buttonClicked()));
	}
	lastButtonClicked = buttonsMenu[0];
	lastButtonClicked->setFlat(true);
	
	connect(ui.categoryMenu, SIGNAL(currentIndexChanged(int)), this, SLOT(menuBoxSelectedIndexChanged(int)));
}

CharPanel::~CharPanel( )
{
}

bool CharPanel::initData( )
{
	// includes charPanelSub reload
	bool result = reloadData(0);
	
	for ( int i = 0; i < 2; ++i )
		result &= panelsMenu[i]->initData();
	
	charPanelData->SetVariables(charData[0]);
	charPanelAbility->SetVariables(charData[0]);
	
	return result;
}

bool CharPanel::reloadData( int depth )
{
	bool result = true;
	if ( depth == 2 )
	{
		result &= charData[lastButtonID]->readData();
	}else
	{
		for ( int i = 0; i < CHAR_COUNT; ++i )
		{
			result &= charData[i]->readData();
		}
	}
	
	if ( result == false )
		return false;
	
	result &= charPanelData->reloadData(depth);
	charPanelData->SetVariables(charData[lastButtonID]);
	
	result &= charPanelAbility->reloadData(depth);
	charPanelAbility->SetVariables(charData[lastButtonID]);
	
	return result;
}

bool CharPanel::checkData( int depth )
{
	charPanelData->GetVariables(charData[lastButtonID]);
	charPanelAbility->GetVariables(charData[lastButtonID]);
	
	bool result = true;
	int badID = -1;
	if ( depth == 2 )
	{
		result &= charData[lastButtonID]->cheackData();
		badID = lastButtonID;
	}else
	{
		for ( int i = 0; i < CHAR_COUNT; ++i )
		{
			result &= charData[i]->cheackData();
			if ( result == false
				&& badID == -1 )
				badID = i;
		}
	}
	if ( result == false )
		SendNotification(QString::fromStdWString(infoList[INFO_ERR_CHK_CHAR_DATA]) + QString(" ") + QString::fromStdWString(guiList[badID]));
	
	return result;
}

bool CharPanel::writeData( int depth )
{
	bool result = true;
	if ( depth == 2 )
	{
		result &= charData[lastButtonID]->writeData();
	}else
	{
		for ( int i = 0; i < CHAR_COUNT; ++i )
			result &= charData[i]->writeData();
	}
	
	return result;
}

void CharPanel::buttonClicked( )
{
	QPushButton *button = static_cast<QPushButton*>(sender());
	if ( button == lastButtonClicked )
		return;
	
	if ( lastButtonClicked != NULL )
	{
		bool result = true;
		result &= charPanelData->GetVariables(charData[lastButtonID]);
		result &= charPanelAbility->GetVariables(charData[lastButtonID]);
		if ( result == false )
		{
			button->setChecked(false);
			return;
		}
		
		lastButtonClicked->setFlat(false);
	}
	
	button->setFlat(true);
	lastButtonClicked = button;
	
	for ( int i = 0; i < CHAR_COUNT; ++i )
	{
		if ( buttonsMenu[i] != button )
			continue;
		lastButtonID = i;
		break;
	}
	charPanelData->SetVariables(charData[lastButtonID]);
	charPanelAbility->SetVariables(charData[lastButtonID]);
}

void CharPanel::menuBoxSelectedIndexChanged( int index )
{
	if ( index == -1 )
		return;
	
	for ( int i = static_cast<int>(panelsMenu.size() - 1); i >= 0; --i )
		panelsMenu[i]->setVisible(i == index);
}

void CharPanel::slotUpdateWeaponOwner( QVector<int> weapOwnerDataVec )
{
	WeapOwnerData tmpOwnerData;
	int j;
	unsigned char oldWeapID,
		oldShieldID;
	for ( int i = 0; i < CHAR_COUNT; ++i )
	{
		oldWeapID = charData[i]->data->weaponID;
		oldShieldID = charData[i]->data->shieldID;
		for ( j = 0; j < weapOwnerDataVec.size(); ++j )
		{
			tmpOwnerData.iVal = weapOwnerDataVec[j];
			if ( tmpOwnerData.charID != i )
				continue;
			if ( tmpOwnerData.isArmor > 0 )
				oldShieldID = tmpOwnerData.weaponSlotIndex;
			else
				oldWeapID = tmpOwnerData.weaponSlotIndex;
		}
		if ( oldWeapID != charData[i]->data->weaponID
			|| oldShieldID != charData[i]->data->shieldID )
		{
			charData[i]->data->weaponID = oldWeapID;
			charData[i]->data->shieldID = oldShieldID;
			charData[i]->writeWeaponIDs_Data();
		}
	}
}
