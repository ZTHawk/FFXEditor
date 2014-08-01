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

#include "constants.hpp"
#include "weapon_constants.hpp"
#include "guiNames.hpp"
#include "info.hpp"
#include "WeaponPanel.hpp"
#include "WeaponData.hpp"
#include "nameIdData.hpp"
#include "globals.hpp"

/*
GOOD WEAPON MODEL IDs:
T: 1-8
Y: 11-15
A: 21-25
K: 31-36
W: 41-46
L: 51-56
R: 61-65

GOOD ARMOR MODEL IDs:
T: 66-70
Y: 71-75
A: 76-79
K: 80-84
W: 85-89
L: 90-94
R: 95-98

GOOD SPECIAL MODEL IDs:
100: Flamethrower
101: Rifle
102: Seymore Staff
103: Seymore Armor


BAD WEAPON MODEL IDs:
9 - 10
16 - 20
26 - 30
37 - 40
47 - 50
57 - 60
99

Bruderherz offset = +7E8BE7 (51 81 84 73 74 81 77 74 81 89 00)
eng: Brother(51 81 7e 83 77 74 81)
*/

WeaponPanel::WeaponPanel( QWidget *p )
	: MyPanel(p)
{
	ui.setupUi(this);
	
	weaponData = new WeaponData();
	lastSelectedWeaponsNameIndex = -1;
	
	int i,
		j;
	size_t k;
	for ( i = 0; i < WEAPONS_NAMES_SIZE; ++i )
		ui.weaponName->addItem(QString::fromStdWString(weaponNames[i]));
	
	for ( k = 0; k < wModelNames.size(); ++k )
		ui.weaponModel->addItem(QString::fromStdWString(wModelNames[k].name));
	
	for ( i = 0; i < CHAR_COUNT_ALL; ++i )
	{
		ui.weaponType->addItem(QString::fromStdWString(guiList[i]) + QString(" ") + QString::fromStdWString(guiList[GN_WP_WP]));
		ui.equippedChar->addItem(QString::fromStdWString(guiList[i]));
	}
	ui.equippedChar->addItem(QString::fromStdWString(guiList[GN_WP_NOONE]));
	
	for ( i = 0; i < DAMAGE_TYPE_NAMES_SIZE; ++i )
		ui.damageType->addItem(QString::fromStdWString(damageTypeNames[i]));
	
	for ( i = 0; i < 5; ++i )
		ui.slotCnt->addItem(QString::number(i));
	
	abilityList.resize(4);
	abilityList[0] = ui.ability1;
	abilityList[1] = ui.ability2;
	abilityList[2] = ui.ability3;
	abilityList[3] = ui.ability4;
	for ( i = 0; i < 4; ++i )
		for ( j = 0; j < WEAPON_ABILITY_NAMES_SIZE; ++j )
			abilityList[i]->addItem(QString::fromStdWString(weaponAbilityNames[j]));
	
	ui.available_Text->setText(QString::fromStdWString(guiList[GN_WP_AVAIL]));
	ui.hidden->setText(QString::fromStdWString(guiList[GN_WP_HIDDEN]));
	ui.weaponType_Text->setText(QString::fromStdWString(guiList[GN_WP_TYPE]));
	ui.weaponName_Text->setText(QString::fromStdWString(guiList[GN_WP_NAME]));
	ui.armorWeapon->setText(QString::fromStdWString(guiList[GN_WP_ISARM]));
	ui.equippedChar_Text->setText(QString::fromStdWString(guiList[GN_WP_EQUIP]));
	ui.damageType_Text->setText(QString::fromStdWString(guiList[GN_WP_DMG]));
	ui.attack_Text->setText(QString::fromStdWString(guiList[GN_WP_ATT]));
	ui.critHit_Text->setText(QString::fromStdWString(guiList[GN_WP_CRIT]));
	ui.weaponModel_Text->setText(QString::fromStdWString(guiList[GN_WP_MODEL]));
	ui.slotCnt_Text->setText(QString::fromStdWString(guiList[GN_WP_SLOT]));
	ui.ability1_Text->setText(QString::fromStdWString(guiList[GN_WP_AB1]));
	ui.ability2_Text->setText(QString::fromStdWString(guiList[GN_WP_AB2]));
	ui.ability3_Text->setText(QString::fromStdWString(guiList[GN_WP_AB3]));
	ui.ability4_Text->setText(QString::fromStdWString(guiList[GN_WP_AB4]));
	
	ui.weaponModel_Text->setInfoID(INFO_WEAP_MODELS);
	
	connect(ui.weaponModel_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.slotSelection, SIGNAL(currentRowChanged(int)), this, SLOT(slotSelection_SelectedIndexChanged(int)));
	connect(ui.slotCnt, SIGNAL(currentIndexChanged(int)), this, SLOT(weaponSlotCnt_SelectedIndexChanged(int)));
	connect(ui.weaponType, SIGNAL(currentIndexChanged(int)), this, SLOT(weaponType_SelectedIndexChanged(int)));
	connect(ui.weaponModel, SIGNAL(currentIndexChanged(int)), this, SLOT(weaponModel_SelectedIndexChanged(int)));
	connect(ui.weaponName, SIGNAL(currentIndexChanged(int)), this, SLOT(weaponName_SelectedIndexChanged(int)));
	
	// this will initialize stylesheet
	int tmpVal;
	checkEntry(ui.attack, &tmpVal, DATA_ATTRIBUTE);
	checkEntry(ui.critHit, &tmpVal, DATA_ATTRIBUTE);
}

WeaponPanel::~WeaponPanel( )
{
	
}

bool WeaponPanel::initData( )
{
	return reloadData(0);
}

bool WeaponPanel::reloadData( int depth )
{
	weaponData->readData();
	
	setVariables(weaponData->data[0]);
	
	ui.slotSelection->clear();
	for ( int i = 0; i < weaponData->curSize; ++i )
	{
		if ( weaponData->validWeaponSlot(i) == false )
			ui.slotSelection->addItem(QString::fromStdWString(guiList[GN_WP_EMPTY]));
		else
			ui.slotSelection->addItem(QString::fromStdWString(weaponData->getWeaponName(i)));
	}
	
	// set to invalid ID before setting "SelectedIndex" to prevent errors
	//lastSelectedIndex = -1;
	//if ( ui.slotSelection->count() > 0 )
	//	ui.slotSelection->setCurrentIndex(0);
	lastSelectedIndex = 0;
	
	return true;
}

bool WeaponPanel::getVariables( PWEAPONDATA wData )
{
	bool result = true;
	bool previousAvailableState = (wData->available > 0) ? true : false;
	unsigned char oldDestCharID = wData->destinationCharID;
	unsigned short oldWeaponNameSkin = wData->id;
	wData->available = (ui.available->checkState() == Qt::Checked) ? 1 : 0;
	wData->id = static_cast<unsigned char>(ui.weaponName->currentIndex());
	//wData->id2 = 0x50;
	
	wData->isArmor = (ui.armorWeapon->checkState() == Qt::Checked) ? 1 : 0;
	wData->damageFormula = static_cast<unsigned char>(ui.damageType->currentIndex());
	
	if ( wData->destinationCharID == TIDUS
		&& wData->id == 1 )
	{
		// brotherhood
		wData->special_properties |= SWF_BROTHERHOOD;
	}else if ( wData->destinationCharID >= CHAR_COUNT )
		wData->special_properties |= SWF_HIDDEN;
	setBitmask(wData->special_properties, SWF_HIDDEN, ui.hidden->isChecked());
	
	if ( wData->available > 0 )
	{
		if ( wData->id == 0
			&& wData->isArmor == 0 )
		{
			// celestial weapon
			wData->special_properties |= SWF_CELESTIAL_OR_AEON;
		}else if ( wData->id != 0 )
		{
			// remove flag if no celestial weapon
			wData->special_properties &= ~SWF_CELESTIAL_OR_AEON;
		}
	}
	
	wData->destinationCharID = static_cast<unsigned char>(ui.weaponType->currentIndex());
	
	int skinID = arrayIndexToWeaponModelIndex(ui.weaponModel->currentIndex());
	if ( skinID >= 0 )
		wData->skin = static_cast<unsigned short>(skinID);
	else if ( skinID == W_CUSTOM )
	{
		unsigned short tmpSkinID;
		result &= checkEntry(ui.weaponModelIndex, &tmpSkinID, DATA_USHORT);
		if ( result == true )
			wData->skin = tmpSkinID;
	}
	
	if ( ui.equippedChar->currentIndex() == CHAR_COUNT_ALL )
		wData->equippedCharID = 0xFF;
	else
		wData->equippedCharID = static_cast<unsigned char>(ui.equippedChar->currentIndex());
	
	result &= checkEntry(ui.attack, &wData->attackPower, DATA_ATTRIBUTE);
	result &= checkEntry(ui.critHit, &wData->critHit, DATA_ATTRIBUTE);
	
	wData->slotCnt = static_cast<unsigned char>(ui.slotCnt->currentIndex());
	
	for ( int i = 3; i >= 0; --i )
	{
		if ( abilityList[i]->currentIndex() == WEAPON_ABILITY_NAMES_SIZE - 1  // check if empty selected
			|| i >= wData->slotCnt )                                            // check if slot is available, if not clear it
		{
			*((&(wData->slot1_ability)) + (i * 2)) = 0xFF;
			*((&(wData->slot1_used)) + (i * 2)) = 0;
		}else
		{
			*((&(wData->slot1_ability)) + (i * 2)) = static_cast<unsigned char>(abilityList[i]->currentIndex());
			*((&(wData->slot1_used)) + (i * 2)) = 0x80;
		}
	}
	
	weaponData->error = !result;
	
	// change weapon name in global list (left side)
	if ( result == true
		&& wData->available > 0
		&& lastSelectedIndex != -1
		&& ( (previousAvailableState == false
				&& ui.slotSelection->item(lastSelectedIndex)->text().compare(
					QString::fromStdWString(guiList[GN_WP_EMPTY])) == 0)
			|| (oldDestCharID != wData->destinationCharID
				|| oldWeaponNameSkin != wData->id) ) )
	{
		ui.slotSelection->item(lastSelectedIndex)->setText(QString::fromStdWString(weaponData->getWeaponName(lastSelectedIndex)));
	}else if ( wData->available == 0
		&& previousAvailableState == true )
	{
		ui.slotSelection->item(lastSelectedIndex)->setText(QString::fromStdWString(guiList[GN_WP_EMPTY]));
	}
	
	return result;
}

void WeaponPanel::setVariables( WEAPONDATA wData )
{
	ui.available->setChecked(wData.available > 0);
	ui.hidden->setChecked((wData.special_properties & SWF_HIDDEN) > 0);

	if ( wData.destinationCharID >= CHAR_COUNT_ALL )
		wData.destinationCharID = CHAR_COUNT_ALL;
	ui.weaponType->setCurrentIndex(wData.destinationCharID);
	
	if ( wData.equippedCharID == 255
		|| (wData.equippedCharID > CHAR_COUNT_ALL
			&& wData.equippedCharID < 255) )
		wData.equippedCharID = CHAR_COUNT_ALL;
	ui.equippedChar->setCurrentIndex(wData.equippedCharID);
	
	ui.armorWeapon->setChecked(wData.isArmor > 0);
	ui.damageType->setCurrentIndex(wData.damageFormula);
	ui.attack->setText(QString::number(wData.attackPower));
	ui.critHit->setText(QString::number(wData.critHit));
	
	if ( wData.slotCnt > 4 )
		wData.slotCnt = 4;
	ui.slotCnt->setCurrentIndex(wData.slotCnt);
	
	for ( int i = 3; i >= 0; --i )
	{
		if ( wData.slotCnt <= i )
		{
			abilityList[i]->setEnabled(false);
			abilityList[i]->setCurrentIndex(WEAPON_ABILITY_NAMES_SIZE - 1);
		}else
		{
			abilityList[i]->setEnabled(true);
			unsigned char abilityID = *((&(wData.slot1_ability)) + (i * 2));
			unsigned char abilityUsed = *((&(wData.slot1_used)) + (i * 2));
			if ( (abilityUsed == 0x00
					&& abilityID == 0x00)
				|| abilityID >= WEAPON_ABILITY_NAMES_SIZE )
				abilityList[i]->setCurrentIndex(WEAPON_ABILITY_NAMES_SIZE - 1);
			else
				abilityList[i]->setCurrentIndex(abilityID);
		}
	}
	
	if ( wData.id > WEAPONS_NAMES_SIZE )
		wData.id = 0;
	ui.weaponName->setCurrentIndex(wData.id);
	
	ui.weaponModel->setCurrentIndex(weaponModelIndexToArrayIndex(wData.skin));
	ui.weaponModelIndex->setText(QString::number(wData.skin));
}

int WeaponPanel::arrayIndexToWeaponModelIndex( int arrayIndex )
{
	if ( arrayIndex < 0
		|| arrayIndex >= static_cast<int>(wModelNames.size()) )
		return 0;
	
	return wModelNames[arrayIndex].id;
}

int WeaponPanel::weaponModelIndexToArrayIndex( unsigned short weaponModelIndex )
{
	for ( size_t i = 0; i < wModelNames.size(); ++i )
	{
		if ( weaponModelIndex == wModelNames[i].id )
			return static_cast<int>(i);
	}
	
	return 0;
}

bool WeaponPanel::checkData( int depth )
{
	if ( lastSelectedIndex != -1 )
		getVariables(&weaponData->data[lastSelectedIndex]);
	
	return weaponData->cheackData();
}

bool WeaponPanel::writeData( int depth )
{
	bool result = weaponData->writeData();
	if ( result == true )
	{
		QVector<int> weapOwnerDataVec;
		WEAPONDATA wData;
		WeapOwnerData tmpOwnerData,
			tmpOwnerData2;
		int j;
		for ( int i = 0; i < weaponData->curSize; ++i )
		{
			if ( weaponData->validWeaponSlot(i) == false )
				continue;
			wData = weaponData->data[i];
			if ( wData.equippedCharID == 0xFF )
				continue;
			
			tmpOwnerData.charID = wData.equippedCharID;
			tmpOwnerData.weaponSlotIndex = i;
			tmpOwnerData.isArmor = wData.isArmor;
			for ( j = 0; j < weapOwnerDataVec.size(); ++j )
			{
				tmpOwnerData2.iVal = weapOwnerDataVec[j];
				if ( tmpOwnerData2.charID != tmpOwnerData.charID )
					continue;
				if ( tmpOwnerData2.isArmor != tmpOwnerData.isArmor )
					continue;
				tmpOwnerData2.weaponSlotIndex = tmpOwnerData.weaponSlotIndex;
				weapOwnerDataVec[j] = tmpOwnerData2.iVal;
				break;
			}
			if ( j >= weapOwnerDataVec.size() )
				weapOwnerDataVec.push_back(tmpOwnerData.iVal);
		}
		emit updateWeaponOwner(weapOwnerDataVec);
	}
	return result;
}

void WeaponPanel::text_Click( )
{
	MyLabel *label = dynamic_cast<MyLabel*>(sender());
	SendNotificationID(label->getInfoID());
}

void WeaponPanel::slotSelection_SelectedIndexChanged( int index )
{
	if ( index == -1 )
		return;
	
	if ( lastSelectedIndex == index )
		return;
	
	if ( lastSelectedIndex != -1
		&& getVariables(&weaponData->data[lastSelectedIndex]) == false )
	{
		ui.slotSelection->setCurrentRow(lastSelectedIndex);
		return;
	}
	
	setVariables(weaponData->data[index]);
	
	lastSelectedIndex = index;
}

void WeaponPanel::weaponSlotCnt_SelectedIndexChanged( int index )
{
	if ( index == -1 )
		return;
	
	for ( int i = 0; i < 4; ++i )
		abilityList[i]->setEnabled(i < index);
}

void WeaponPanel::weaponType_SelectedIndexChanged( int index )
{
	if ( index == -1 )
		return;
	
	int tmpCurIndex = ui.weaponName->currentIndex(),
		tmpLastSelWeapNameIndex = lastSelectedWeaponsNameIndex;
	ui.weaponName->clear();
	if ( index < CHAR_COUNT - 1 ) // -1 to ignore seymour 
	{
		int baseOffsetToNames = WEAPONS_NAMES_SIZE * index;
		for ( int i = 0; i < WEAPONS_NAMES_SIZE; ++i )
			ui.weaponName->addItem(QString::fromStdWString(weaponNames[baseOffsetToNames + i]));
	}else
	{
		ui.weaponName->addItem(QString::fromStdWString(guiList[GN_UNKNOWN]));
		tmpCurIndex = 0;
	}
	lastSelectedWeaponsNameIndex = tmpLastSelWeapNameIndex;
	int wpnCnt = ui.weaponName->count();
	if ( tmpCurIndex != lastSelectedWeaponsNameIndex
		&& lastSelectedWeaponsNameIndex != -1 )
		tmpCurIndex = lastSelectedWeaponsNameIndex;
	if ( wpnCnt <= tmpCurIndex )
		tmpCurIndex = wpnCnt - 1;
	ui.weaponName->setCurrentIndex(tmpCurIndex);
}

void WeaponPanel::weaponModel_SelectedIndexChanged( int index )
{
	if ( index == -1 )
		return;
	
	ui.weaponModelIndex->setVisible(index == 0);
	
}

void WeaponPanel::weaponName_SelectedIndexChanged( int index )
{
	if ( index == -1 )
		return;
	
	lastSelectedWeaponsNameIndex = index;
}
