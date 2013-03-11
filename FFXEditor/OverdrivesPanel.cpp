#include "constants.hpp"
#include "overdrive_constants.hpp"
#include "guiNames.hpp"
#include "OverdrivesPanel.hpp"
#include "OverdriveData.hpp"

OverdrivesPanel::OverdrivesPanel( QWidget *p )
	: MyPanel(p)
{
	ui.setupUi(this);
	
	overdriveData = new OverdriveData();
	
	ui.od_tidus_Text->setText(QString::fromStdWString(guiList[GN_TIDUS]) + QString(":"));
	ui.od_auron_Text->setText(QString::fromStdWString(guiList[GN_AURON]) + QString(":"));
	ui.od_wakka_Text->setText(QString::fromStdWString(guiList[GN_WAKKA]) + QString(":"));
	ui.od_kimahri_Text->setText(QString::fromStdWString(guiList[GN_KIMAHRI]) + QString(":"));
	ui.od_lulu_Text->setText(QString::fromStdWString(guiList[GN_LULU]) + QString(":"));
	ui.od_rikku_Text->setText(QString::fromStdWString(guiList[GN_RIKKU]) + QString(":"));
	
	int i = 0;
	for ( i = 0; i < OD_TIDUS_NAMES_SIZE; ++i )
	{
		ui.od_tidus->addItem(QString::fromStdWString(odTidusNames[i]));
		ui.od_tidus->item(i)->setCheckState(Qt::Unchecked);
	}
	for ( i = 0; i < OD_AURON_NAMES_SIZE; ++i )
	{
		ui.od_auron->addItem(QString::fromStdWString(odAuronNames[i]));
		ui.od_auron->item(i)->setCheckState(Qt::Unchecked);
	}
	for ( i = 0; i < OD_WAKKA_NAMES_SIZE; ++i )
	{
		ui.od_wakka->addItem(QString::fromStdWString(odWakkaNames[i]));
		ui.od_wakka->item(i)->setCheckState(Qt::Unchecked);
	}
	for ( i = 0; i < OD_KIMAHRI_NAMES_SIZE; ++i )
	{
		ui.od_kimahri->addItem(QString::fromStdWString(odKimahriNames[i]));
		ui.od_kimahri->item(i)->setCheckState(Qt::Unchecked);
	}
	for ( i = 0; i < OD_LULU_NAMES_SIZE; ++i )
	{
		ui.od_lulu->addItem(QString::fromStdWString(odLuluNames[i]));
		ui.od_lulu->item(i)->setCheckState(Qt::Unchecked);
	}
	for ( i = 0; i < OD_RIKKU_NAMES_SIZE; ++i )
	{
		ui.od_rikku->addItem(QString::fromStdWString(odRikkuNames[i]));
		ui.od_rikku->item(i)->setCheckState(Qt::Unchecked);
	}
}

OverdrivesPanel::~OverdrivesPanel( )
{
	
}

bool OverdrivesPanel::reloadData( int depth )
{
	if ( overdriveData->readData() == false )
	{
		SendNotification("Error while reading overdrive data.");
		return false;
	}
	
	int i = 0;
	int slot = 0;
	
	unsigned int tmpMask = OVERDRIVES_BITMASK_TIDUS;
	for ( i = 0; i < OD_TIDUS_NAMES_SIZE; ++i )
	{
		ui.od_tidus->item(i)->setCheckState(
			((overdriveData->overdrive_list[0] & tmpMask) > 0) ? Qt::Checked : Qt::Unchecked);
		tmpMask *= 2;
	}
	
	tmpMask = OVERDRIVES_BITMASK_AURON;
	for ( i = 0; i < OD_AURON_NAMES_SIZE; ++i )
	{
		ui.od_auron->item(i)->setCheckState(
			((overdriveData->overdrive_list[0] & tmpMask) > 0) ? Qt::Checked : Qt::Unchecked);
		tmpMask *= 2;
	}
	
	tmpMask = OVERDRIVES_BITMASK_WAKKA;
	for ( i = 0; i < OD_WAKKA_NAMES_SIZE; ++i )
	{
		ui.od_wakka->item(i)->setCheckState(
			((overdriveData->overdrive_list[0] & tmpMask) > 0) ? Qt::Checked : Qt::Unchecked);
		tmpMask *= 2;
	}
	
	tmpMask = OVERDRIVES_BITMASK_KIMAHRI;
	for ( i = 0; i < OD_KIMAHRI_NAMES_SIZE; ++i )
	{
		ui.od_kimahri->item(i)->setCheckState(
			((overdriveData->overdrive_list[0] & tmpMask) > 0) ? Qt::Checked : Qt::Unchecked);
		tmpMask *= 2;
	}
	
	tmpMask = OVERDRIVES_BITMASK_LULU;
	for ( i = 0, slot = 0; i < OD_LULU_NAMES_SIZE; ++i )
	{
		ui.od_lulu->item(i)->setCheckState(
			((overdriveData->overdrive_list[slot] & tmpMask) > 0) ? Qt::Checked : Qt::Unchecked);

		if ( tmpMask == (unsigned int)INT_MAX + 1 )
		{
			tmpMask = 1;
			slot = 1;
		}else
			tmpMask *= 2;
	}
	
	tmpMask = OVERDRIVES_BITMASK_RIKKU;
	for ( i = 0, slot = 1; i < OD_RIKKU_NAMES_SIZE; ++i )
	{
		ui.od_rikku->item(i)->setCheckState(
			((overdriveData->overdrive_list[slot] & tmpMask) > 0) ? Qt::Checked : Qt::Unchecked);

		if ( tmpMask == (unsigned int)INT_MAX + 1 )
		{
			tmpMask = 1;
			++slot;
		}else
			tmpMask *= 2;
	}
	
	return true;
}

bool OverdrivesPanel::initData( )
{
	return reloadData(0);
}

bool OverdrivesPanel::checkData( int depth )
{
	return true;
}

bool OverdrivesPanel::writeData( int depth )
{
	int i = 0;
	int slot = 0;
	
	unsigned int tmpMask = OVERDRIVES_BITMASK_TIDUS;
	for ( i = 0; i < OD_TIDUS_NAMES_SIZE; ++i )
	{
		setBitmask(overdriveData->overdrive_list[0], tmpMask,
			ui.od_tidus->item(i)->checkState() == Qt::Checked);
		
		tmpMask *= 2;
	}
	
	tmpMask = OVERDRIVES_BITMASK_AURON;
	for ( i = 0; i < OD_AURON_NAMES_SIZE; ++i )
	{
		setBitmask(overdriveData->overdrive_list[0], tmpMask,
			ui.od_auron->item(i)->checkState() == Qt::Checked);
		
		tmpMask *= 2;
	}
	
	tmpMask = OVERDRIVES_BITMASK_WAKKA;
	for ( i = 0; i < OD_WAKKA_NAMES_SIZE; ++i )
	{
		setBitmask(overdriveData->overdrive_list[0], tmpMask,
			ui.od_wakka->item(i)->checkState() == Qt::Checked);
		
		tmpMask *= 2;
	}
	
	tmpMask = OVERDRIVES_BITMASK_KIMAHRI;
	for ( i = 0; i < OD_KIMAHRI_NAMES_SIZE; ++i )
	{
		setBitmask(overdriveData->overdrive_list[0], tmpMask,
			ui.od_kimahri->item(i)->checkState() == Qt::Checked);
		
		tmpMask *= 2;
	}
	
	tmpMask = OVERDRIVES_BITMASK_LULU;
	for ( i = 0; i < OD_LULU_NAMES_SIZE; ++i )
	{
		setBitmask(overdriveData->overdrive_list[slot], tmpMask,
			ui.od_lulu->item(i)->checkState() == Qt::Checked);
		
		if ( tmpMask == (unsigned int)INT_MAX + 1 )
		{
			++slot;
			tmpMask = 1;
		}else
			tmpMask *= 2;
	}
	
	tmpMask = OVERDRIVES_BITMASK_RIKKU;
	for ( i = 0; i < OD_RIKKU_NAMES_SIZE; ++i )
	{
		setBitmask(overdriveData->overdrive_list[slot], tmpMask,
			ui.od_rikku->item(i)->checkState() == Qt::Checked);
		
		if ( tmpMask == (unsigned int)INT_MAX + 1 )
		{
			++slot;
			tmpMask = 1;
		}else
			tmpMask *= 2;
	}
	
	return overdriveData->writeData();
}
