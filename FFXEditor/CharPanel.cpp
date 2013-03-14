#include "CharPanel.hpp"
#include "constants.hpp"
#include "guiNames.hpp"
#include "CharData.hpp"
#include "CharPanelData.hpp"
#include "CharPanelAbility.hpp"

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
	
	for ( i = 0; i < CHAR_COUNT; ++i )
	{
		buttonsMenu[i]->setText(QString::fromStdWString(guiList[GN_TIDUS + i]));
		buttonsMenu[i]->setCheckable(true);
		connect(buttonsMenu[i], SIGNAL(clicked(bool)), this, SLOT(buttonClicked()));
	}
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
	
	lastButtonClicked = buttonsMenu[0];
	lastButtonClicked->setChecked(true);
	lastButtonClicked->setFlat(true);
	
	ui.categoryMenu->setCurrentIndex(0);
	
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
		
		lastButtonClicked->setChecked(false);
		lastButtonClicked->setFlat(false);
	}
	
	button->setChecked(true);
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
