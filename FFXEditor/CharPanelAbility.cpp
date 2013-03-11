#include "constants.hpp"
#include "guiNames.hpp"
#include "CharPanelAbility.hpp"
#include "CharData.hpp"
#include "ability_constants.hpp"

#include <QListWidget>

CharPanelAbility::CharPanelAbility( QWidget *p )
	: MyPanel(p)
{
	ui.setupUi(this);
	
	abilityList.resize(3);
	abilityList[0] = ui.abilitys_1;
	abilityList[1] = ui.abilitys_2;
	abilityList[2] = ui.abilitys_3;
	
	int slot = -1;
	for ( int i = 0; i < ABILITY_NAMES_SIZE; ++i )
	{
		if ( i % 32 == 0 )
			++slot;
		
		abilityList[slot]->addItem(QString::fromStdWString(abilityNames[i]));
		abilityList[slot]->item(i % 32)->setCheckState(Qt::Unchecked);
	}
	
	ui.abilitys_Text->setText(QString::fromStdWString(guiList[GN_CP_A_INFO]) + QString(":"));
	
	connect(ui.abilitys_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
}

CharPanelAbility::~CharPanelAbility( )
{
	
}

bool CharPanelAbility::initData( )
{
	return reloadData(0);
}

bool CharPanelAbility::reloadData( int depth )
{
	return true;
}

void CharPanelAbility::SetVariables( CharData *charData )
{
	int i = 0;
	int slot = 0;
	unsigned int tmpMask = 1;
	for ( i = 0; i < ABILITY_NAMES_SIZE; ++i )
	{
		abilityList[slot]->item(i % 32)->setCheckState(
			((charData->data->abilities[slot] & tmpMask) > 0) ? Qt::Checked : Qt::Unchecked);
		if ( tmpMask == (unsigned int)INT_MAX + 1 )
		{
			tmpMask = 1;
			++slot;
		}else
			tmpMask *= 2;
	}
}

bool CharPanelAbility::GetVariables( CharData *charData )
{
	int i = 0;
	int slot = 0;
	unsigned int tmpMask = 1;
	QString str;
	for ( i = 0; i < ABILITY_NAMES_SIZE; ++i )
	{
		setBitmask(charData->data->abilities[slot],
			tmpMask,
			abilityList[slot]->item(i % 32)->checkState() == Qt::Checked);
		
		if ( tmpMask == (unsigned int)INT_MAX + 1 )
		{
			tmpMask = 1;
			++slot;
		}else
			tmpMask *= 2;
	}
	
	return true;
}

bool CharPanelAbility::checkData( int depth )
{
	return true;
}

bool CharPanelAbility::writeData( int depth )
{
	return true;
}

void CharPanelAbility::text_Click( )
{
	SendNotificationID(INFO_ABILITY);
}
