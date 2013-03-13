#include "constants.hpp"
#include "guiNames.hpp"
#include "BattlePanel.hpp"
#include "BattleData.hpp"
#include "MemMng.hpp"
#include "globals.hpp"
#include "offsets.hpp"
#include "utils.hpp"

BattleDataThread::BattleDataThread( int address )
{
	this->address = address;
	running = true;
}

void BattleDataThread::stop( )
{
	running = false;
}

void BattleDataThread::run( )
{
	int pos = 1;
	while ( running == true
		&& pos > 0 )
	{
		this->msleep(1000);
		// -1 and +1 because findOffsetOfByteArray return 0 if nothing has been found
		// so make sure it returns 1 in case it has found the specific data
		pos = findOffsetOfByteArray(const_cast<unsigned char*>(battleDataContainerA),
			BATTLE_DATA_CONTAINER_LEN,
			address - 1,
			address + BATTLE_DATA_CONTAINER_LEN + 1);
	}
}

BattlePanel::BattlePanel( QWidget *p )
	: MyPanel(p)
{
	ui.setupUi(this);
	
	locked = true;
	bDataSize = 0;
	battleThread = NULL;
	lastIndex = 0;
	
	widgetList.push_back(ui.hp_Text);
	widgetList.push_back(ui.hp_cur);
	widgetList.push_back(ui.hp_max);
	widgetList.push_back(ui.mp_Text);
	widgetList.push_back(ui.mp_cur);
	widgetList.push_back(ui.mp_max);
	widgetList.push_back(ui.overdrive_Text);
	widgetList.push_back(ui.overdrive_cur);
	widgetList.push_back(ui.haste_Text);
	widgetList.push_back(ui.haste_cur);
	widgetList.push_back(ui.slow_Text);
	widgetList.push_back(ui.slow_cur);
	widgetList.push_back(ui.turnsTillAction_Text);
	widgetList.push_back(ui.turnsTillAction_cur);
	widgetList.push_back(ui.battleActivity);
	widgetList.push_back(ui.animSpeed_Text);
	widgetList.push_back(ui.animSpeed_cur);
	widgetList.push_back(ui.standAtLoc_Text);
	widgetList.push_back(ui.standAtLoc_cur);
	widgetList.push_back(ui.runToLoc_Text);
	widgetList.push_back(ui.runToLoc_cur);
	
	for ( int i = static_cast<int>(widgetList.size()) - 1; i >= 0; --i )
		widgetList[i]->setVisible(false);
	
	ui.unlockButton->setText(QString::fromStdWString(guiList[GN_BP_UNLOCK]));
	
	ui.hp_Text->setText(QString::fromStdWString(guiList[GN_BP_HP]));
	ui.mp_Text->setText(QString::fromStdWString(guiList[GN_BP_MP]));
	ui.overdrive_Text->setText(QString::fromStdWString(guiList[GN_BP_OD]));
	ui.haste_Text->setText(QString::fromStdWString(guiList[GN_BP_HASTE]));
	ui.slow_Text->setText(QString::fromStdWString(guiList[GN_BP_SLOW]));
	ui.turnsTillAction_Text->setText(QString::fromStdWString(guiList[GN_BP_TURNS]));
	ui.battleActivity->setText(QString::fromStdWString(guiList[GN_BP_ACTIV]));
	
	ui.animSpeed_Text->setText(QString::fromStdWString(guiList[GN_BP_ANIMSPD]));
	ui.standAtLoc_Text->setText(QString::fromStdWString(guiList[GN_BP_STAND]));
	ui.runToLoc_Text->setText(QString::fromStdWString(guiList[GN_BP_RUN]));
	
	connect(ui.actorList, SIGNAL(currentRowChanged(int)), this, SLOT(actorChanged(int)));
	connect(ui.unlockButton, SIGNAL(clicked(bool)), this, SLOT(unlockButtonPressed()));
}

BattlePanel::~BattlePanel( )
{
	if ( battleThread != NULL )
	{
		battleThread->stop();
		battleThread->wait(1500);
		delete battleThread;
	}
}

bool BattlePanel::initData( )
{
	return true;//reloadData(0);
}

bool BattlePanel::reloadData( int depth )
{
	if ( locked == true )
		return false;
	
	if ( bData.size() == 0 )
	{
		findBattleData();
		
		ui.actorList->clear();
		if ( bDataSize > 0 )
		{
			for ( int i = 0; i < bDataSize; ++i )
			{
				ui.actorList->addItem(QString::fromStdWString(asciiFFX_ascii(bData[i]->data->nameBytes)));
			}
			ui.actorList->setCurrentRow(0);
		}
	}else
	{
		int curRow = ui.actorList->currentRow();
		if ( depth == 2 )
		{
			bData[ui.actorList->currentRow()]->readData();
		}else
		{
			for ( int i = 0; i < bDataSize; ++i )
			{
				bData[i]->readData();
			}
		}
		setVariables(bData[curRow]->data);
	}
	
	return true;
}

bool BattlePanel::checkData( int depth )
{
	bool result = true;
	if ( depth == 2 )
	{
		result &= bData[lastIndex]->cheackData();
	}else
	{
		for ( int i = 0; i < bDataSize; ++i )
		{
			result &= bData[i]->cheackData();
		}
	}
	
	return result;
}

bool BattlePanel::writeData( int depth )
{
	bool result = true;
	getVariables(bData[lastIndex]->data);
	if ( depth == 2 )
	{
		result &= bData[lastIndex]->writeData();
	}else
	{
		for ( int i = 0; i < bDataSize; ++i )
			result &= bData[i]->writeData();
	}
	
	return result;
}

void BattlePanel::unlock( )
{
	locked = false;
	//bData.resize(8);
	if ( reloadData() == false )
		return;
	
	// todo fix crash when not in battle
	battleThread = new BattleDataThread(bData[0]->getInitAdr());
	connect(battleThread, SIGNAL(finished()), this, SLOT(battleOver()));
	battleThread->start();
}

void BattlePanel::lock( )
{
	locked = true;
	for ( int i = 0; i < bDataSize; ++i )
		delete bData[i];
	bDataSize = 0;
	bData.clear();
	delete battleThread;
	battleThread = NULL;
}

void BattlePanel::findBattleData( )
{
	unsigned int baseEnd = BASE_OFFSET + 30000000;
	bDataSize = 0;
	int specialChar_lastChar;
	unsigned char identChars[BD_INDENT_LEN];
	unsigned int pos = 1,
		pos2,
		posBase,
		offStart;
	
	offStart = BASE_OFFSET;
	if ( bData.size() == 0 )
		bData.resize(8, NULL);
	while ( pos != 0 )
	{
		pos = findOffsetOfByteArray(const_cast<unsigned char*>(battleDataContainerA),
			BATTLE_DATA_CONTAINER_LEN,
			offStart,
			baseEnd);
		if ( pos == 0 )
			break;
		
		// update offset for next loop
		offStart = pos + 4;
		
		pos2 = findOffsetOfByteArray(const_cast<unsigned char*>(battleDataContainerB),
			BATTLE_DATA_CONTAINER_LEN,
			pos + BATTLE_DATA_CONTAINER_DISTANCE,
			pos + BATTLE_DATA_CONTAINER_DISTANCE + BATTLE_DATA_CONTAINER_LEN);
		if ( pos2 == 0 )
			continue;
		
		// possible data found
		// check if player, enemy or something else
		memMng->read(pos + BD_INDENT_OFFSET_FROM_CONT_A,
			identChars,
			BD_INDENT_LEN);
		specialChar_lastChar = BD_INDENT_LEN - 1;
		if ( identChars[specialChar_lastChar] == 0 )
			--specialChar_lastChar;
		if ( identChars[specialChar_lastChar] != BD_IDENT_ENDCHAR )
			continue;
		
		if ( (identChars[0] & BD_IDENT_CHAR_MASK2) == 0
			&& (identChars[1] & BD_IDENT_CHAR_MASK) == 0 )
			continue;
		
		posBase = pos;
		pos = pos2 + BD_COMMON_SEARCH_OFFSET;
		pos2 = findOffsetOfByteArray(const_cast<unsigned char*>(battleData_commonSearch),
			BD_COMMON_SEARCH_LEN,
			pos,
			pos + BD_COMMON_SEARCH_MAX_SEARCH_LEN);
		if ( pos2 == 0 )
			continue;
		
		bData[bDataSize] = new BattleData(posBase, pos2);
		bData[bDataSize]->readData();
		++bDataSize;
		offStart = posBase + BD_CONTAINER_SKIP_LEN;
	}
	if ( bDataSize == 0 )
		bData.clear();
}

bool BattlePanel::getVariables( PBATTLEDATA bData )
{
	bool result = true;
	result &= checkEntry(ui.hp_cur, &bData->hp, DATA_UINT);
	result &= checkEntry(ui.hp_max, &bData->hp_max, DATA_UINT);
	result &= checkEntry(ui.mp_cur, &bData->mp, DATA_UINT);
	result &= checkEntry(ui.mp_max, &bData->mp_max, DATA_UINT);
	result &= checkEntry(ui.overdrive_cur, &bData->overdrive, DATA_ATTRIBUTE);
	result &= checkEntry(ui.haste_cur, &bData->hasteCnt, DATA_ATTRIBUTE);
	result &= checkEntry(ui.slow_cur, &bData->slowCnt, DATA_ATTRIBUTE);
	result &= checkEntry(ui.turnsTillAction_cur, &bData->turnsTillAction, DATA_ATTRIBUTE);
	bData->battleActivity = ui.battleActivity->isChecked();
	
	result &= checkEntry(ui.animSpeed_cur, &bData->animSpeed, DATA_ATTRIBUTE);
	result &= checkEntry(ui.standAtLoc_cur, &bData->standAtLocation, DATA_ATTRIBUTE);
	result &= checkEntry(ui.runToLoc_cur, &bData->runToLocation, DATA_ATTRIBUTE);
	
	return result;
}

void BattlePanel::setVariables( PBATTLEDATA bData )
{
	ui.hp_cur->setText(QString::number(bData->hp));
	ui.hp_max->setText(QString::number(bData->hp_max));
	ui.mp_cur->setText(QString::number(bData->mp));
	ui.mp_max->setText(QString::number(bData->mp_max));
	ui.overdrive_cur->setText(QString::number(bData->overdrive));
	ui.haste_cur->setText(QString::number(bData->hasteCnt));
	ui.slow_cur->setText(QString::number(bData->slowCnt));
	ui.turnsTillAction_cur->setText(QString::number(bData->turnsTillAction));
	ui.battleActivity->setChecked(bData->battleActivity == 1);
	
	ui.animSpeed_cur->setText(QString::number(bData->animSpeed));
	ui.standAtLoc_cur->setText(QString::number(bData->standAtLocation));
	ui.runToLoc_cur->setText(QString::number(bData->runToLocation));
}

void BattlePanel::actorChanged( int index )
{
	if ( index < 0 )
		return;
	
	if ( lastIndex != index )
	{
		if ( getVariables(bData[lastIndex]->data) == false )
			return;
	}
	
	lastIndex = index;
	setVariables(bData[index]->data);
}

void BattlePanel::unlockButtonPressed( )
{
	ui.unlockButton->setVisible(false);
	for ( int i = static_cast<int>(widgetList.size()) - 1; i >= 0; --i )
	{
		widgetList[i]->setVisible(true);
	}
	unlock();
}

void BattlePanel::battleOver( )
{
	lock();
	ui.unlockButton->setVisible(true);
	for ( int i = static_cast<int>(widgetList.size()) - 1; i >= 0; --i )
	{
		widgetList[i]->setVisible(false);
	}
}
