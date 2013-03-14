#include "constants.hpp"
#include "guiNames.hpp"
#include "info.hpp"
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
		this->msleep(500);
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
	battleThread = NULL;
	lastIndex = 0;
	
	ui.mainInfo->setPlainText(QString::fromStdWString(infoList[INFO_BATTLE]));
	ui.unlockButton->setText(QString::fromStdWString(guiList[GN_BP_UNLOCK]));
	ui.lockButton->setText(QString::fromStdWString(guiList[GN_BP_LOCK]));
	ui.rescanButton->setText(QString::fromStdWString(guiList[GN_BP_RESCAN]));
	
	ui.hp_Text->setText(QString::fromStdWString(guiList[GN_BP_HP]));
	ui.mp_Text->setText(QString::fromStdWString(guiList[GN_BP_MP]));
	ui.overdrive_Text->setText(QString::fromStdWString(guiList[GN_BP_OD]));
	ui.deathCountdown_Text->setText(QString::fromStdWString(guiList[GN_BP_DEATH_CD]));
	ui.sleep_Text->setText(QString::fromStdWString(guiList[GN_BP_SLEEP]));
	ui.silence_Text->setText(QString::fromStdWString(guiList[GN_BP_SILENCE]));
	ui.shell_Text->setText(QString::fromStdWString(guiList[GN_BP_SHELL]));
	ui.protect_Text->setText(QString::fromStdWString(guiList[GN_BP_PROT]));
	ui.reflect_Text->setText(QString::fromStdWString(guiList[GN_BP_REFLEC]));
	ui.waterIm_Text->setText(QString::fromStdWString(guiList[GN_BP_WATER]));
	ui.fireIm_Text->setText(QString::fromStdWString(guiList[GN_BP_FIRE]));
	ui.lightIm_Text->setText(QString::fromStdWString(guiList[GN_BP_LIGHT]));
	ui.iceIm_Text->setText(QString::fromStdWString(guiList[GN_BP_ICE]));
	ui.regen_Text->setText(QString::fromStdWString(guiList[GN_BP_REGEN]));
	ui.haste_Text->setText(QString::fromStdWString(guiList[GN_BP_HASTE]));
	ui.slow_Text->setText(QString::fromStdWString(guiList[GN_BP_SLOW]));
	ui.conditionList_Text->setText(QString::fromStdWString(guiList[GN_BP_COND]));
	ui.turnsTillAction_Text->setText(QString::fromStdWString(guiList[GN_BP_TURNS]));
	ui.battleActivity->setText(QString::fromStdWString(guiList[GN_BP_ACTIV]));
	
	ui.animSpeed_Text->setText(QString::fromStdWString(guiList[GN_BP_ANIMSPD]));
	ui.standAtLoc_Text->setText(QString::fromStdWString(guiList[GN_BP_STAND]));
	ui.runToLoc_Text->setText(QString::fromStdWString(guiList[GN_BP_RUN]));
	
	for ( int i = 0; i < BATTLEDATA_BITMASK_SIZE; ++i )
	{
		ui.conditionList->addItem(QString::fromStdWString(guiList[GN_BP_COND + 1 + i]));
		ui.conditionList->item(i)->setCheckState(Qt::Unchecked);
	}
	
	ui.hp_Text->setInfoID(INFO_BATTLE_HP);
	ui.mp_Text->setInfoID(INFO_BATTLE_MP);
	ui.overdrive_Text->setInfoID(INFO_BATTLE_OD);
	ui.deathCountdown_Text->setInfoID(INFO_BATTLE_DEATH_CD);
	ui.sleep_Text->setInfoID(INFO_BATTLE_STATUS);
	ui.silence_Text->setInfoID(INFO_BATTLE_STATUS);
	ui.shell_Text->setInfoID(INFO_BATTLE_STATUS);
	ui.protect_Text->setInfoID(INFO_BATTLE_STATUS);
	ui.reflect_Text->setInfoID(INFO_BATTLE_STATUS);
	ui.waterIm_Text->setInfoID(INFO_BATTLE_STATUS);
	ui.fireIm_Text->setInfoID(INFO_BATTLE_STATUS);
	ui.lightIm_Text->setInfoID(INFO_BATTLE_STATUS);
	ui.iceIm_Text->setInfoID(INFO_BATTLE_STATUS);
	ui.regen_Text->setInfoID(INFO_BATTLE_STATUS);
	ui.haste_Text->setInfoID(INFO_BATTLE_STATUS);
	ui.slow_Text->setInfoID(INFO_BATTLE_STATUS);
	ui.conditionList_Text->setInfoID(INFO_BATTLE_COND);
	ui.turnsTillAction_Text->setInfoID(INFO_BATTLE_TURN_ACTION);
	ui.animSpeed_Text->setInfoID(INFO_BATTLE_ANIM);
	ui.standAtLoc_Text->setInfoID(INFO_BATTLE_STAND_AT);
	ui.runToLoc_Text->setInfoID(INFO_BATTLE_RUN_TO);
	
	QObjectList list = children();
	QWidget *w;
	for ( int i = 0; i < list.size(); ++i )
	{
		w = dynamic_cast<QWidget*>(list.at(i));
		w->setVisible(w == ui.unlockButton);
		if ( w->inherits("MyLabel") == true
			&& dynamic_cast<MyLabel*>(w)->getInfoID() != -1 )
			connect(w, SIGNAL(clicked()), this, SLOT(text_Click()));
	}
	ui.mainInfo->setVisible(true);
	
	connect(ui.actorList, SIGNAL(currentRowChanged(int)), this, SLOT(actorChanged(int)));
	connect(ui.unlockButton, SIGNAL(clicked(bool)), this, SLOT(unlockButtonPressed()));
	connect(ui.lockButton, SIGNAL(clicked(bool)), this, SLOT(lockButtonPressed()));
	connect(ui.rescanButton, SIGNAL(clicked(bool)), this, SLOT(rescanButtonPressed()));
}

BattlePanel::~BattlePanel( )
{
	if ( battleThread != NULL )
	{
		battleThread->stop();
		battleThread->wait(800);
		delete battleThread;
	}
}

bool BattlePanel::initData( )
{
	return true;
}

bool BattlePanel::reloadData( int depth )
{
	if ( locked == true )
		return false;
	
	if ( bData.size() == 0 )
	{
		if ( findBattleData() == false )
			return false;
		
		ui.actorList->clear();
		if ( bData.size() > 0 )
		{
			for ( size_t i = 0; i < bData.size(); ++i )
				ui.actorList->addItem(QString::fromStdWString(asciiFFX_ascii(bData[i]->data->nameBytes)));
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
			for ( size_t i = 0; i < bData.size(); ++i )
				bData[i]->readData();
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
		for ( size_t i = 0; i < bData.size(); ++i )
			result &= bData[i]->cheackData();
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
		for ( size_t i = 0; i < bData.size(); ++i )
			result &= bData[i]->writeData();
	}
	
	return result;
}

bool BattlePanel::unlock( )
{
	locked = false;
	if ( reloadData() == false )
		return false;
	
	// todo fix crash when not in battle
	battleThread = new BattleDataThread(bData[0]->getInitAdr());
	connect(battleThread, SIGNAL(finished()), this, SLOT(battleOver()));
	battleThread->start();
	
	return true;
}

void BattlePanel::lock( )
{
	locked = true;
	lastIndex = 0;
	for ( int i = static_cast<int>(bData.size()) - 1; i >= 0; --i )
		delete bData[i];
	bData.clear();
	delete battleThread;
	battleThread = NULL;
}

bool BattlePanel::findBattleData( )
{
	unsigned int baseEnd = BASE_OFFSET + 30000000;
	int bDataSize = 0;
	int specialChar_lastChar;
	unsigned char identChars[BD_INDENT_LEN];
	unsigned int pos = 1,
		pos2,
		posBase,
		offStart;
	
	offStart = BASE_OFFSET;
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
		
		bData.push_back(new BattleData(posBase, pos2));
		bData[bDataSize]->readData();
		++bDataSize;
		offStart = posBase + BD_CONTAINER_SKIP_LEN;
	}
	
	return (bDataSize > 0);
}

bool BattlePanel::getVariables( PBATTLEDATA bData )
{
	bool result = true;
	result &= checkEntry(ui.hp_cur, &bData->hp, DATA_UINT);
	result &= checkEntry(ui.hp_max, &bData->hp_max, DATA_UINT);
	result &= checkEntry(ui.mp_cur, &bData->mp, DATA_UINT);
	result &= checkEntry(ui.mp_max, &bData->mp_max, DATA_UINT);
	result &= checkEntry(ui.overdrive_cur, &bData->overdrive, DATA_ATTRIBUTE);
	result &= checkEntry(ui.deathCountdown_cur, &bData->deathCountDown, DATA_ATTRIBUTE);
	result &= checkEntry(ui.sleep_cur, &bData->sleepCnt, DATA_ATTRIBUTE);
	result &= checkEntry(ui.silence_cur, &bData->silenceCnt, DATA_ATTRIBUTE);
	result &= checkEntry(ui.shell_cur, &bData->shellCnt, DATA_ATTRIBUTE);
	result &= checkEntry(ui.protect_cur, &bData->protectCnt, DATA_ATTRIBUTE);
	result &= checkEntry(ui.reflect_cur, &bData->reflectCnt, DATA_ATTRIBUTE);
	result &= checkEntry(ui.waterIm_cur, &bData->waterImmunityCnt, DATA_ATTRIBUTE);
	result &= checkEntry(ui.fireIm_cur, &bData->fireImmunityCnt, DATA_ATTRIBUTE);
	result &= checkEntry(ui.lightIm_cur, &bData->lightningImmunityCnt, DATA_ATTRIBUTE);
	result &= checkEntry(ui.iceIm_cur, &bData->iceImmunityCnt, DATA_ATTRIBUTE);
	result &= checkEntry(ui.regen_cur, &bData->regenCnt, DATA_ATTRIBUTE);
	result &= checkEntry(ui.haste_cur, &bData->hasteCnt, DATA_ATTRIBUTE);
	result &= checkEntry(ui.slow_cur, &bData->slowCnt, DATA_ATTRIBUTE);
	result &= checkEntry(ui.turnsTillAction_cur, &bData->turnsTillAction, DATA_ATTRIBUTE);
	bData->battleActivity = ui.battleActivity->isChecked();
	
	result &= checkEntry(ui.animSpeed_cur, &bData->animSpeed, DATA_ATTRIBUTE);
	result &= checkEntry(ui.standAtLoc_cur, &bData->standAtLocation, DATA_ATTRIBUTE);
	result &= checkEntry(ui.runToLoc_cur, &bData->runToLocation, DATA_ATTRIBUTE);
	
	bool newState;
	bData->conditionMask = 0;
	bData->conditionMask2 = 0;
	for ( int i = 0; i < BATTLEDATA_BITMASK_SIZE; ++i )
	{
		if ( ui.conditionList->item(i)->checkState() != Qt::Checked )
			continue;
		
		if ( i < BATTLEDATA_BITMASK1_SIZE )
			bData->conditionMask |= (1<<i);
		else
			bData->conditionMask2 |= (1<<(i - BATTLEDATA_BITMASK1_SIZE));
	}
	
	return result;
}

void BattlePanel::setVariables( PBATTLEDATA bData )
{
	ui.hp_cur->setText(QString::number(bData->hp));
	ui.hp_max->setText(QString::number(bData->hp_max));
	ui.mp_cur->setText(QString::number(bData->mp));
	ui.mp_max->setText(QString::number(bData->mp_max));
	ui.overdrive_cur->setText(QString::number(bData->overdrive));
	ui.deathCountdown_cur->setText(QString::number(bData->deathCountDown));
	ui.sleep_cur->setText(QString::number(bData->sleepCnt));
	ui.silence_cur->setText(QString::number(bData->silenceCnt));
	ui.shell_cur->setText(QString::number(bData->shellCnt));
	ui.protect_cur->setText(QString::number(bData->protectCnt));
	ui.reflect_cur->setText(QString::number(bData->reflectCnt));
	ui.waterIm_cur->setText(QString::number(bData->waterImmunityCnt));
	ui.fireIm_cur->setText(QString::number(bData->fireImmunityCnt));
	ui.lightIm_cur->setText(QString::number(bData->lightningImmunityCnt));
	ui.iceIm_cur->setText(QString::number(bData->iceImmunityCnt));
	ui.regen_cur->setText(QString::number(bData->regenCnt));
	ui.haste_cur->setText(QString::number(bData->hasteCnt));
	ui.slow_cur->setText(QString::number(bData->slowCnt));
	ui.turnsTillAction_cur->setText(QString::number(bData->turnsTillAction));
	ui.battleActivity->setChecked(bData->battleActivity == 1);
	
	ui.animSpeed_cur->setText(QString::number(bData->animSpeed));
	ui.standAtLoc_cur->setText(QString::number(bData->standAtLocation));
	ui.runToLoc_cur->setText(QString::number(bData->runToLocation));
	
	unsigned int newState;
	for ( int i = 0; i < BATTLEDATA_BITMASK_SIZE; ++i )
	{
		if ( i < BATTLEDATA_BITMASK1_SIZE )
			newState = (bData->conditionMask
				& (1<<i));
		else
			newState = (bData->conditionMask2
				& (1<<(i - BATTLEDATA_BITMASK1_SIZE)));
		ui.conditionList->item(i)->setCheckState(newState > 0
			? Qt::Checked : Qt::Unchecked);
	}
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
	if ( unlock() == false )
		return;
	
	QObjectList list = children();
	QWidget *w;
	for ( int i = 0; i < list.size(); ++i )
	{
		w = dynamic_cast<QWidget*>(list.at(i));
		w->setVisible(w != ui.unlockButton);
	}
	ui.mainInfo->setVisible(false);
}

void BattlePanel::battleOver( )
{
	lock();
	
	QObjectList list = children();
	QWidget *w;
	for ( int i = 0; i < list.size(); ++i )
	{
		w = dynamic_cast<QWidget*>(list.at(i));
		w->setVisible(w == ui.unlockButton);
	}
	ui.mainInfo->setVisible(true);
}

void BattlePanel::lockButtonPressed( )
{
	battleThread->stop();
	// battleOver will be called once thread ends
}

void BattlePanel::rescanButtonPressed( )
{
	disconnect(battleThread, SIGNAL(finished()), this, SLOT(battleOver()));
	battleThread->stop();
	battleThread->wait(800);
	lock();
	if ( unlock() == false )
		lock();
}

void BattlePanel::text_Click( )
{
	MyLabel *label = dynamic_cast<MyLabel*>(sender());
	SendNotificationID(label->getInfoID());
}
