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
#include "ability_constants.hpp"
#include "guiNames.hpp"
#include "info.hpp"
#include "AeonPanel.hpp"
#include "CharData.hpp"
#include "globals.hpp"

AeonPanel::AeonPanel( QWidget *p )
	: MyPanel(p)
{
	ui.setupUi(this);
	
	lastButtonClicked = NULL;
	lastButtonID = 0;
	
	ui.attack_Text->setText(QString::fromStdWString(guiList[GN_AP_ATT]));
	ui.defense_Text->setText(QString::fromStdWString(guiList[GN_AP_DEF]));
	ui.magic_Text->setText(QString::fromStdWString(guiList[GN_AP_MAG]));
	ui.magicDef_Text->setText(QString::fromStdWString(guiList[GN_AP_MDEF]));
	ui.speed_Text->setText(QString::fromStdWString(guiList[GN_AP_SPD]));
	ui.luck_Text->setText(QString::fromStdWString(guiList[GN_AP_LUCK]));
	ui.evade_Text->setText(QString::fromStdWString(guiList[GN_AP_EVA]));
	ui.hit_Text->setText(QString::fromStdWString(guiList[GN_AP_HIT]));
	ui.available->setText(QString::fromStdWString(guiList[GN_AP_AVAIL]));
	ui.hp_Text->setText(QString::fromStdWString(guiList[GN_AP_HP]));
	ui.mp_Text->setText(QString::fromStdWString(guiList[GN_AP_MP]));
	ui.enemys_Text->setText(QString::fromStdWString(guiList[GN_AP_KILL]));
	ui.deaths_Text->setText(QString::fromStdWString(guiList[GN_AP_DEATH]));
	ui.overdrive_Text->setText(QString::fromStdWString(guiList[GN_AP_OD]));
	ui.battles_revive_Text->setText(QString::fromStdWString(guiList[GN_AP_BTL]));
	ui.ability_Text->setText(QString::fromStdWString(guiList[GN_AP_ABIL]));
	
	ui.attack_Text->setInfoID(INFO_AEON_ATTACK);
	ui.defense_Text->setInfoID(INFO_AEON_DEFENSE);
	ui.magic_Text->setInfoID(INFO_AEON_MAGIC);
	ui.magicDef_Text->setInfoID(INFO_AEON_MAGIC_DEF);
	ui.speed_Text->setInfoID(INFO_AEON_SPEED);
	ui.luck_Text->setInfoID(INFO_AEON_LUCK);
	ui.evade_Text->setInfoID(INFO_AEON_EVADE);
	ui.hit_Text->setInfoID(INFO_AEON_HIT);
	ui.hp_Text->setInfoID(INFO_AEON_HP);
	ui.mp_Text->setInfoID(INFO_AEON_MP);
	ui.enemys_Text->setInfoID(INFO_AEON_ENEMYS);
	ui.deaths_Text->setInfoID(INFO_AEON_DEATHS);
	ui.overdrive_Text->setInfoID(INFO_OVERDRIVE);
	ui.battles_revive_Text->setInfoID(INFO_AEON_BATTLES_REVIVE);
	ui.ability_Text->setInfoID(INFO_ABILITY);
	
	connect(ui.attack_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.defense_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.magic_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.magicDef_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.speed_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.luck_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.evade_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.hit_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.hp_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.mp_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.enemys_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.deaths_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.overdrive_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.battles_revive_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.ability_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	
	aeonData.resize(AEON_END - AEON_START);
	buttonsMenu.resize(AEON_END - AEON_START);
	
	buttonsMenu[VALEFOR - AEON_START] = ui.button_valefor;
	buttonsMenu[IFRIT - AEON_START] = ui.button_ifrit;
	buttonsMenu[IXION - AEON_START] = ui.button_ixion;
	buttonsMenu[SHIVA - AEON_START] = ui.button_shiva;
	buttonsMenu[BAHAMUT - AEON_START] = ui.button_bahamut;
	buttonsMenu[ANIMA - AEON_START] = ui.button_anima;
	buttonsMenu[YOJIMBO - AEON_START] = ui.button_yojimbo;
	buttonsMenu[MUG - AEON_START] = ui.button_mug;
	buttonsMenu[DUG - AEON_START] = ui.button_dug;
	buttonsMenu[RUG - AEON_START] = ui.button_rug;
	
	int i;
	for ( int i = AEON_START; i < AEON_END; ++i )
		aeonData[i - AEON_START] = new CharData(i);
	
	for ( i = 0; i < AEON_END - AEON_START; ++i )
	{
		buttonsMenu[i]->setText(QString::fromStdWString(guiList[GN_TIDUS + AEON_START + i]));
		buttonsMenu[i]->setCheckable(true);
		connect(buttonsMenu[i], SIGNAL(clicked(bool)), this, SLOT(button_Click()));
	}
	
	int slot = -1;
	for ( int i = 0; i < ABILITY_NAMES_SIZE; ++i )
	{
		if ( i % 32 == 0 )
			++slot;
		
		ui.abilityList->addItem(QString::fromStdWString(abilityNames[i]));
		ui.abilityList->item(i)->setCheckState(Qt::Unchecked);
	}
	
	checkData(2);
}

AeonPanel::~AeonPanel( )
{
	
}

bool AeonPanel::initData( )
{
	return reloadData(0);
}

bool AeonPanel::reloadData( int depth )
{
	bool result = true;
	if ( depth == 2 )
	{
		result &= aeonData[lastButtonID]->readData();
	}else
	{
		for ( int i = 0; i < AEON_END - AEON_START; ++i )
		{
			result &= aeonData[i]->readData();
		}
	}
	
	if ( result == false )
		return false;
	
	setVariables(aeonData[lastButtonID]);
	
	return result;
}

bool AeonPanel::checkData( int depth )
{
	getVariables(aeonData[lastButtonID]);
	
	bool result = true;
	int badID = -1;
	if ( depth == 2 )
	{
		result &= aeonData[lastButtonID]->cheackData();
		badID = lastButtonID;
	}else
	{
		for ( int i = 0; i < 10; ++i )
		{
			result &= aeonData[i]->cheackData();
			if ( result == false
				&& badID == -1 )
				badID = i;
		}
	}
	if ( result == false )
		SendNotification(QString::fromStdWString(infoList[INFO_ERR_CHK_AEON_DATA]) + QString(" ") + QString::fromStdWString(guiList[AEON_START + badID]));
	
	return result;
}

bool AeonPanel::writeData( int depth )
{
	bool result = true;
	if ( depth == 2 )
	{
		result &= aeonData[lastButtonID]->writeData();
	}else
	{
		for ( int i = 0; i < 10; ++i )
			result &= aeonData[i]->writeData();
	}
	
	return result;
}

bool AeonPanel::getVariables( CharData *aeonData )
{
	aeonData->data->available = (ui.available->isChecked() == true) ? AEON_AVAILABLE_VALUE : 0;
	
	bool result =
		checkEntry(ui.attack_cur, &aeonData->data->attributes[0], DATA_ATTRIBUTE)
		&& checkEntry(ui.attack_add, &aeonData->data->attributes_basic[0], DATA_ATTRIBUTE)
		&& checkEntry(ui.defense_cur, &aeonData->data->attributes[1], DATA_ATTRIBUTE)
		&& checkEntry(ui.defense_add, &aeonData->data->attributes_basic[1], DATA_ATTRIBUTE)
		&& checkEntry(ui.magic_cur, &aeonData->data->attributes[2], DATA_ATTRIBUTE)
		&& checkEntry(ui.magic_add, &aeonData->data->attributes_basic[2], DATA_ATTRIBUTE)
		&& checkEntry(ui.magicDef_cur, &aeonData->data->attributes[3], DATA_ATTRIBUTE)
		&& checkEntry(ui.magicDef_add, &aeonData->data->attributes_basic[3], DATA_ATTRIBUTE)
		&& checkEntry(ui.speed_cur, &aeonData->data->attributes[4], DATA_ATTRIBUTE)
		&& checkEntry(ui.speed_add, &aeonData->data->attributes_basic[4], DATA_ATTRIBUTE)
		&& checkEntry(ui.luck_cur, &aeonData->data->attributes[5], DATA_ATTRIBUTE)
		&& checkEntry(ui.luck_add, &aeonData->data->attributes_basic[5], DATA_ATTRIBUTE)
		&& checkEntry(ui.evade_cur, &aeonData->data->attributes[6], DATA_ATTRIBUTE)
		&& checkEntry(ui.evade_add, &aeonData->data->attributes_basic[6], DATA_ATTRIBUTE)
		&& checkEntry(ui.hit_cur, &aeonData->data->attributes[7], DATA_ATTRIBUTE)
		&& checkEntry(ui.hit_add, &aeonData->data->attributes_basic[7], DATA_ATTRIBUTE)
		
		&& checkEntry(ui.hp_add, &aeonData->data->hp_base_max, DATA_HP)
		&& checkEntry(ui.mp_add, &aeonData->data->mp_base_max, DATA_MP)
		&& checkEntry(ui.hp_cur, &aeonData->data->hp, DATA_HP)
		&& checkEntry(ui.mp_cur, &aeonData->data->mp, DATA_MP)
		&& checkEntry(ui.hp_max, &aeonData->data->hp_max, DATA_HP)
		&& checkEntry(ui.mp_max, &aeonData->data->mp_max, DATA_MP)
		
		&& checkEntry(ui.enemys, &aeonData->data->enemys_killed, DATA_UINT)
		&& checkEntry(ui.deaths, &aeonData->data->deaths, DATA_UINT)
		
		&& checkEntry(ui.overdrive_cur, &aeonData->data->overdrive_points, DATA_UCHAR)
		&& checkEntry(ui.overdrive_max, &aeonData->data->overdrive_points_needed, DATA_UCHAR)
		
		&& checkEntry(ui.battles_revive, &aeonData->data->battles_till_revive, DATA_UINT);
	
	aeonData->error = !result;
	
	int i = 0;
	int slot = 0;
	unsigned int tmpMask = 1;
	for ( i = 0; i < ABILITY_NAMES_SIZE; ++i )
	{
		setBitmask(aeonData->data->abilities[slot], tmpMask,
			ui.abilityList->item(i)->checkState() == Qt::Checked);
		
		if ( tmpMask == (unsigned int)INT_MAX + 1 )
		{
			tmpMask = 1;
			++slot;
		}else
			tmpMask *= 2;
	}
	
	return result;
}

void AeonPanel::setVariables( CharData *aeonData )
{
	ui.available->setChecked(aeonData->data->available == AEON_AVAILABLE_VALUE);
	
	ui.attack_cur->setText(QString::number(aeonData->data->attributes[0]));
	ui.attack_add->setText(QString::number(aeonData->data->attributes_basic[0]));
	ui.defense_cur->setText(QString::number(aeonData->data->attributes[1]));
	ui.defense_add->setText(QString::number(aeonData->data->attributes_basic[1]));
	ui.magic_cur->setText(QString::number(aeonData->data->attributes[2]));
	ui.magic_add->setText(QString::number(aeonData->data->attributes_basic[2]));
	ui.magicDef_cur->setText(QString::number(aeonData->data->attributes[3]));
	ui.magicDef_add->setText(QString::number(aeonData->data->attributes_basic[3]));
	ui.speed_cur->setText(QString::number(aeonData->data->attributes[4]));
	ui.speed_add->setText(QString::number(aeonData->data->attributes_basic[4]));
	ui.luck_cur->setText(QString::number(aeonData->data->attributes[5]));
	ui.luck_add->setText(QString::number(aeonData->data->attributes_basic[5]));
	ui.evade_cur->setText(QString::number(aeonData->data->attributes[6]));
	ui.evade_add->setText(QString::number(aeonData->data->attributes_basic[6]));
	ui.hit_cur->setText(QString::number(aeonData->data->attributes[7]));
	ui.hit_add->setText(QString::number(aeonData->data->attributes_basic[7]));
	
	ui.hp_add->setText(QString::number(aeonData->data->hp_base_max));
	ui.mp_add->setText(QString::number(aeonData->data->mp_base_max));
	ui.hp_cur->setText(QString::number(aeonData->data->hp));
	ui.mp_cur->setText(QString::number(aeonData->data->mp));
	ui.hp_max->setText(QString::number(aeonData->data->hp_max));
	ui.mp_max->setText(QString::number(aeonData->data->mp_max));
	
	ui.enemys->setText(QString::number(aeonData->data->enemys_killed));
	ui.deaths->setText(QString::number(aeonData->data->deaths));
	
	ui.overdrive_cur->setText(QString::number(aeonData->data->overdrive_points));
	ui.overdrive_max->setText(QString::number(aeonData->data->overdrive_points_needed));
	
	ui.battles_revive->setText(QString::number(aeonData->data->battles_till_revive));
	
	int i = 0;
	int slot = 0;
	unsigned int tmpMask = 1;
	for ( i = 0; i < ABILITY_NAMES_SIZE; ++i )
	{
		ui.abilityList->item(i)->setCheckState(
			((aeonData->data->abilities[slot] & tmpMask) > 0) ? Qt::Checked : Qt::Unchecked);
		
		if ( tmpMask == (unsigned int)INT_MAX + 1 )
		{
			tmpMask = 1;
			++slot;
		}else
			tmpMask *= 2;
	}
}

void AeonPanel::button_Click( )
{
	QPushButton *button = static_cast<QPushButton*>(sender());
	if ( button == lastButtonClicked )
		return;
	
	if ( lastButtonClicked != NULL )
	{
		if ( getVariables(aeonData[lastButtonID]) == false )
		{
			button->setChecked(false);
			return;
		}
		lastButtonClicked->setChecked(false);
		lastButtonClicked->setFlat(false);
	}
	
	lastButtonClicked = button;
	button->setChecked(true);
	button->setFlat(true);
	
	for ( int i = 0; i < AEON_END - AEON_START; ++i )
	{
		if ( buttonsMenu[i] != button )
			continue;
		lastButtonID = i;
		break;
	}
	
	setVariables(aeonData[lastButtonID]);
}

void AeonPanel::text_Click( )
{
	MyLabel *label = dynamic_cast<MyLabel*>(sender());
	SendNotificationID(label->getInfoID());
}

void AeonPanel::slotUpdateWeaponOwner( QVector<int> weapOwnerDataVec )
{
	WeapOwnerData tmpOwnerData;
	int j;
	unsigned char oldWeapID,
		oldShieldID;
	for ( int i = 0; i < AEON_END - AEON_START; ++i )
	{
		oldWeapID = aeonData[i]->data->weaponID;
		oldShieldID = aeonData[i]->data->shieldID;
		for ( j = 0; j < weapOwnerDataVec.size(); ++j )
		{
			tmpOwnerData.iVal = weapOwnerDataVec[j];
			if ( tmpOwnerData.charID != AEON_START + i )
				continue;
			if ( tmpOwnerData.isArmor > 0 )
				oldShieldID = tmpOwnerData.weaponSlotIndex;
			else
				oldWeapID = tmpOwnerData.weaponSlotIndex;
		}
		if ( oldWeapID != aeonData[i]->data->weaponID
			|| oldShieldID != aeonData[i]->data->shieldID )
		{
			aeonData[i]->data->weaponID = oldWeapID;
			aeonData[i]->data->shieldID = oldShieldID;
			aeonData[i]->writeWeaponIDs_Data();
		}
	}
}
