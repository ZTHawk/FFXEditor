#include "constants.hpp"
#include "guiNames.hpp"
#include "GlobalPanel.hpp"
#include "globals.hpp"
#include "offsets.hpp"
#include "MemMng.hpp"

GlobalPanel::GlobalPanel( QWidget *p )
	: MyPanel(p)
{
	ui.setupUi(this);
	
	gilNum = 0;
	
	ui.gil_Text->setText(QString::fromStdWString(guiList[GN_MP_GIL]) + QString(":"));
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
	else
		SendNotification("Error while reading misc data.");
	
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
