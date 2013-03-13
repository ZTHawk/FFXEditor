#include "ffxeditor.hpp"

#include "constants.hpp"
#include "globals.hpp"
#include "offsets.hpp"
#include "guiNames.hpp"
#include "cfgFileMng.hpp"
#include "MemMng.hpp"
#include "processMng.hpp"
#include "string_helper.hpp"
#include "utils.hpp"
#include "ability_constants.hpp"
#include "item_constants.hpp"
#include "overdrive_constants.hpp"
#include "weapon_constants.hpp"

#include "AeonPanel.hpp"
#include "BattlePanel.hpp"
#include "CharPanel.hpp"
#include "GlobalPanel.hpp"
#include "ItemPanel.hpp"
#include "OverdrivesPanel.hpp"
#include "WeaponPanel.hpp"

#include <QAction>
#include <QMenu>

FFXEditor::FFXEditor(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	
	initNames();
	parseCharArrayToStringVector(infoList_en, infoList);
	
	ui.aboutLabel->setText("by Karl 'ZHawk' Trzebiatowski");
	this->setWindowTitle(QString("FFX-Editor v") + QString(FFXEDITOR_VERSION));
	
	ui.menuBox->addItems(QStringList()
		<< QString::fromStdWString(guiList[GN_CP])
		<< QString::fromStdWString(guiList[GN_IP])
		<< QString::fromStdWString(guiList[GN_AP])
		<< QString::fromStdWString(guiList[GN_OP])
		<< QString::fromStdWString(guiList[GN_WP])
		<< QString::fromStdWString(guiList[GN_MP])
		<< QString::fromStdWString(guiList[GN_BP])
		);
	
	QMenu *reloadMenu = new QMenu();
	QAction *reloadAction = new QAction(QString::fromStdWString(guiList[GN_REL_SEC]), reloadMenu);
	QAction *reloadAction2 = new QAction(QString::fromStdWString(guiList[GN_REL_ALL]), reloadMenu);
	reloadMenu->addAction(reloadAction);
	reloadMenu->addAction(reloadAction2);
	ui.reloadButton->setMenu(reloadMenu);
	ui.reloadButton->setText(QString::fromStdWString(guiList[GN_REL]));
	
	QMenu *saveMenu = new QMenu();
	QAction *saveAction = new QAction(QString::fromStdWString(guiList[GN_SAVE_SEC]), saveMenu);
	QAction *saveAction2 = new QAction(QString::fromStdWString(guiList[GN_SAVE_ALL]), saveMenu);
	saveMenu->addAction(saveAction);
	saveMenu->addAction(saveAction2);
	ui.saveButton->setMenu(saveMenu);
	ui.saveButton->setText(QString::fromStdWString(guiList[GN_SAVE]));
	
	panelsMenu.push_back(new CharPanel(ui.containerMain));
	panelsMenu.push_back(new ItemPanel(ui.containerMain));
	panelsMenu.push_back(new AeonPanel(ui.containerMain));
	panelsMenu.push_back(new OverdrivesPanel(ui.containerMain));
	panelsMenu.push_back(new WeaponPanel(ui.containerMain));
	panelsMenu.push_back(new GlobalPanel(ui.containerMain));
	panelsMenu.push_back(new BattlePanel(ui.containerMain));
	
	connect(ui.reloadButton, SIGNAL(clicked(bool)), this, SLOT(reloadButton_Click()));
	connect(ui.saveButton, SIGNAL(clicked(bool)), this, SLOT(SaveButton_Click()));
	connect(reloadAction, SIGNAL(triggered(bool)), this, SLOT(reloadButtonSection_Click()));
	connect(saveAction, SIGNAL(triggered(bool)), this, SLOT(saveButtonSection_Click()));
	connect(reloadAction2, SIGNAL(triggered(bool)), this, SLOT(reloadButtonAll_Click()));
	connect(saveAction2, SIGNAL(triggered(bool)), this, SLOT(saveButtonAll_Click()));
	connect(ui.menuBox, SIGNAL(currentIndexChanged(int)), this, SLOT(menuBox_SelectedIndexChanged(int)));

}

FFXEditor::~FFXEditor()
{

}

void FFXEditor::init( )
{
	FindProcess();
	memMng = new MemMng();
	memMng->init(emulatorProcessID);
	
	BASE_OFFSET_BASE = findOffsetOfByteArray(reinterpret_cast<unsigned char*>(const_cast<unsigned char*>(seachBytesArray)), SEARCH_BYTES_ARRAY_LEN);
	if ( BASE_OFFSET_BASE == 0 )
		SendNotification("Error finding FFX data.");
	else
	{
		unsigned char *specialBytes = new unsigned char[SEARCH_SPECIAL_BYTE_AMOUNT];
		memset(specialBytes, SEARCH_SPECIAL_BYTE, SEARCH_SPECIAL_BYTE_AMOUNT);
		BASE_OFFSET_SPECIAL = findOffsetOfByteArray(specialBytes, SEARCH_SPECIAL_BYTE_AMOUNT, BASE_OFFSET_BASE);
		delete specialBytes;
		if ( BASE_OFFSET_SPECIAL != 0 )
		{
			BASE_OFFSET = BASE_OFFSET_SPECIAL + SEARCH_SPECIAL_BYTE_OFFSET;
		}else
		{
			BASE_OFFSET = BASE_OFFSET_BASE + SEARCH_BYTE_OFFSET;
			unsigned int tmpOffset = findOffsetOfByteArray((unsigned char*)&seachBytesArray2, SEARCH_BYTES_ARRAY_2_LEN, BASE_OFFSET);
			if ( tmpOffset != 0
				&& tmpOffset != BASE_OFFSET_BASE )
				BASE_OFFSET = tmpOffset + SEARCH_BYTES_ARRAY_2_LEN;
		}
		
		// find language
		unsigned int langPos = findOffsetOfByteArray(langVersionArray, LANGVERSION_ARRAY_LEN, BASE_OFFSET_BASE + LANGVERSION_SEARCH_OFFSET, BASE_OFFSET_BASE);
		if ( langPos != 0 )
		{
			langPos += LANGVERSION_SUBSEARCH_OFFSET;
			char *cStr = new char[10];
			memMng->read(langPos, cStr, 10);
			std::string langIdentifier(cStr, 10);
			delete cStr;
			if ( langIdentifier.compare(0, 4, "SLUS") == 0 )
				langVersion = LANG_US;
		}
	}
	initData();
}

void FFXEditor::initNames( )
{
	initGUINames();
	initOverdriveNames();
	initAbilityNames();
	initItemNames();
	initKeyItemNames();
	initModelNames();
	initWeaponAbilityNames();
	initWeaponDmgTypeNames();
	initWeaponNames();
}

void FFXEditor::initGUINames( )
{
	CfgFileMng cfgFileMng(L"cfg/general.cfg");
	cfgFileMng.loadStart();
	std::vector<std::wstring> tmpVec;
	parseCharArrayToStringVector(guiList_en, tmpVec);
	guiList.resize(tmpVec.size());
	for ( size_t i = 0; i < tmpVec.size(); ++i )
		guiList[i] = cfgFileMng.getString(fromInt(static_cast<int>(i)), tmpVec[i]);
	cfgFileMng.loadEnd();
}

void FFXEditor::initOverdriveNames( )
{
	CfgFileMng cfgFileMng(L"cfg/overdrives.cfg");
	cfgFileMng.loadStart();
	std::vector<std::wstring> tmpVec;
	parseCharArrayToStringVector(odTidusNames_en, tmpVec);
	parseCharArrayToStringVector(odAuronNames_en, tmpVec);
	parseCharArrayToStringVector(odWakkaNames_en, tmpVec);
	parseCharArrayToStringVector(odKimahriNames_en, tmpVec);
	parseCharArrayToStringVector(odLuluNames_en, tmpVec);
	parseCharArrayToStringVector(odRikkuNames_en, tmpVec);
	odTidusNames.resize(OD_TIDUS_NAMES_SIZE);
	odAuronNames.resize(OD_AURON_NAMES_SIZE);
	odWakkaNames.resize(OD_WAKKA_NAMES_SIZE);
	odKimahriNames.resize(OD_KIMAHRI_NAMES_SIZE);
	odLuluNames.resize(OD_LULU_NAMES_SIZE);
	odRikkuNames.resize(OD_RIKKU_NAMES_SIZE);
	int i,
		j = 0;
	for ( i = 0; i < OD_TIDUS_NAMES_SIZE; ++i, ++j )
		odTidusNames[i] = cfgFileMng.getString(fromInt(j), tmpVec[j]);
	for ( i = 0; i < OD_AURON_NAMES_SIZE; ++i, ++j )
		odAuronNames[i] = cfgFileMng.getString(fromInt(j), tmpVec[j]);
	for ( i = 0; i < OD_WAKKA_NAMES_SIZE; ++i, ++j )
		odWakkaNames[i] = cfgFileMng.getString(fromInt(j), tmpVec[j]);
	for ( i = 0; i < OD_KIMAHRI_NAMES_SIZE; ++i, ++j )
		odKimahriNames[i] = cfgFileMng.getString(fromInt(j), tmpVec[j]);
	for ( i = 0; i < OD_LULU_NAMES_SIZE; ++i, ++j )
		odLuluNames[i] = cfgFileMng.getString(fromInt(j), tmpVec[j]);
	for ( i = 0; i < OD_RIKKU_NAMES_SIZE; ++i, ++j )
		odRikkuNames[i] = cfgFileMng.getString(fromInt(j), tmpVec[j]);
	cfgFileMng.loadEnd();
}

void FFXEditor::initAbilityNames( )
{
	CfgFileMng cfgFileMng(L"cfg/abilities.cfg");
	cfgFileMng.loadStart();
	std::vector<std::wstring> tmpVec;
	parseCharArrayToStringVector(abilityNames_en, tmpVec);
	abilityNames.resize(tmpVec.size());
	for ( size_t i = 0; i < tmpVec.size(); ++i )
		abilityNames[i] = cfgFileMng.getString(fromInt(static_cast<int>(i)), tmpVec[i]);
	cfgFileMng.loadEnd();
}

void FFXEditor::initItemNames( )
{
	CfgFileMng cfgFileMng(L"cfg/items.cfg");
	cfgFileMng.loadStart();
	std::vector<std::wstring> tmpVec;
	parseCharArrayToStringVector(itemNames_en, tmpVec);
	itemNames.resize(tmpVec.size());
	for ( size_t i = 0; i < tmpVec.size(); ++i )
		itemNames[i] = cfgFileMng.getString(fromInt(static_cast<int>(i)), tmpVec[i]);
	cfgFileMng.loadEnd();
}

void FFXEditor::initKeyItemNames( )
{
	CfgFileMng cfgFileMng(L"cfg/keyItems.cfg");
	cfgFileMng.loadStart();
	std::vector<std::wstring> tmpVec;
	parseCharArrayToStringVector(keyItemNames_en, tmpVec);
	keyItemNames.resize(tmpVec.size());
	for ( size_t i = 0; i < tmpVec.size(); ++i )
		keyItemNames[i] = cfgFileMng.getString(fromInt(static_cast<int>(i)), tmpVec[i]);
	cfgFileMng.loadEnd();
}

void FFXEditor::addModelNameData( std::wstring name , int id )
{
	if ( name.size() == 0 )
		return;
	
	NameIdData nid;
	nid.name = name;
	nid.id = id;
	wModelNames.push_back(nid);
}

void FFXEditor::initModelNames( )
{
	CfgFileMng cfgFileMng(L"cfg/weaponModels.cfg");
	cfgFileMng.loadStart();
	addModelNameData(L"Custom", W_CUSTOM);
	addModelNameData(L"Unknown", W_UNKNOWN);
	std::vector<std::wstring> tmpVec;
	parseCharArrayToStringVector(weaponModelNames_en, tmpVec);
	int cnt = 0,
		i;
	addModelNameData(cfgFileMng.getString(L"0", tmpVec[cnt++]), 0);
	for ( i = 16385; i <= 16391; ++i )
		addModelNameData(cfgFileMng.getString(fromInt(i), tmpVec[cnt++]), i);
	for ( i = 16395; i <= 16400; ++i )
		addModelNameData(cfgFileMng.getString(fromInt(i), tmpVec[cnt++]), i);
	for ( i = 16405; i <= 16409; ++i )
		addModelNameData(cfgFileMng.getString(fromInt(i), tmpVec[cnt++]), i);
	for ( i = 16415; i <= 16420; ++i )
		addModelNameData(cfgFileMng.getString(fromInt(i), tmpVec[cnt++]), i);
	for ( i = 16425; i <= 16430; ++i )
		addModelNameData(cfgFileMng.getString(fromInt(i), tmpVec[cnt++]), i);
	for ( i = 16435; i <= 16440; ++i )
		addModelNameData(cfgFileMng.getString(fromInt(i), tmpVec[cnt++]), i);
	for ( i = 16445; i <= 16482; ++i )
		addModelNameData(cfgFileMng.getString(fromInt(i), tmpVec[cnt++]), i);
	
	for ( i = 1; i <= 16384; ++i )
		addModelNameData(cfgFileMng.getString(fromInt(i), L""), i);
	for ( i = 16392; i <= 16394; ++i )
		addModelNameData(cfgFileMng.getString(fromInt(i), L""), i);
	for ( i = 16401; i <= 16404; ++i )
		addModelNameData(cfgFileMng.getString(fromInt(i), L""), i);
	for ( i = 16410; i <= 16414; ++i )
		addModelNameData(cfgFileMng.getString(fromInt(i), L""), i);
	for ( i = 16421; i <= 16424; ++i )
		addModelNameData(cfgFileMng.getString(fromInt(i), L""), i);
	for ( i = 16431; i <= 16434; ++i )
		addModelNameData(cfgFileMng.getString(fromInt(i), L""), i);
	for ( i = 16441; i <= 16444; ++i )
		addModelNameData(cfgFileMng.getString(fromInt(i), L""), i);
	for ( i = 16483; i <= USHRT_MAX; ++i )
		addModelNameData(cfgFileMng.getString(fromInt(i), L""), i);
	cfgFileMng.loadEnd();
}

void FFXEditor::initWeaponAbilityNames( )
{
	CfgFileMng cfgFileMng(L"cfg/weaponAbility.cfg");
	cfgFileMng.loadStart();
	std::vector<std::wstring> tmpVec;
	parseCharArrayToStringVector(weaponAbilityNames_en, tmpVec);
	weaponAbilityNames.resize(tmpVec.size());
	for ( size_t i = 0; i < tmpVec.size(); ++i )
		weaponAbilityNames[i] = cfgFileMng.getString(fromInt(static_cast<int>(i)), tmpVec[i]);
	cfgFileMng.loadEnd();
}

void FFXEditor::initWeaponDmgTypeNames( )
{
	CfgFileMng cfgFileMng(L"cfg/weaponDamageTypes.cfg");
	cfgFileMng.loadStart();
	std::vector<std::wstring> tmpVec;
	parseCharArrayToStringVector(damageTypeNames_en, tmpVec);
	damageTypeNames.resize(tmpVec.size());
	for ( size_t i = 0; i < tmpVec.size(); ++i )
		damageTypeNames[i] = cfgFileMng.getString(fromInt(static_cast<int>(i)), tmpVec[i]);
	cfgFileMng.loadEnd();
}

void FFXEditor::initWeaponNames( )
{
	CfgFileMng cfgFileMng(L"cfg/weapons.cfg");
	cfgFileMng.loadStart();
	std::vector<std::wstring> tmpVec;
	parseCharArrayToStringVector(weaponNames_en, tmpVec);
	weaponNames.resize(tmpVec.size());
	for ( size_t i = 0; i < tmpVec.size(); ++i )
		weaponNames[i] = cfgFileMng.getString(fromInt(static_cast<int>(i)), tmpVec[i]);
	cfgFileMng.loadEnd();
}

void FFXEditor::setInfo( QString msg )
{
	ui.infoLabel->setPlainText(msg);
}

void FFXEditor::initData( )
{
	SendNotificationID(INFO_GLOBAL);
	
	bool result = true;
	for ( size_t i = 0; i < panelsMenu.size(); ++i )
	{
		if ( result == true )
			result &= panelsMenu[i]->initData();
		panelsMenu[i]->setVisible(i == 0);
	}
	
	ui.menuBox->setCurrentIndex(0);
}

void FFXEditor::reloadButtonAll_Click( )
{
	//if ( emulatorProcessID == -1 )
	//	return;
	
	//if ( BASE_OFFSET_SPECIAL == 0 )
	//{
	//	unsigned char *specialBytes = new unsigned char[SEARCH_SPECIAL_BYTE_AMOUNT];
	//	for ( int i = 0; i < SEARCH_SPECIAL_BYTE_AMOUNT; ++i )
	//		specialBytes[i] = SEARCH_SPECIAL_BYTE;
	//	BASE_OFFSET_SPECIAL = findOffsetOfByteArray(specialBytes, SEARCH_SPECIAL_BYTE_AMOUNT, BASE_OFFSET_BASE);
	//	delete specialBytes;
	//}
	
	bool result = true;
	for ( size_t i = 0; i < panelsMenu.size(); ++i )
		result &= panelsMenu[i]->reloadData();
}

void FFXEditor::saveButtonAll_Click( )
{
	if ( emulatorProcessID == -1 )
		return;
	
	bool result = true;
	for ( size_t i = 0; i < panelsMenu.size(); ++i )
		if ( result == true )
			result &= panelsMenu[i]->checkData();
	
	if ( result == false )
		return;
	
	for ( size_t i = 0; i < panelsMenu.size(); ++i )
		if ( result == true )
			result &= panelsMenu[i]->writeData();
	
	if ( result == true )
		SendNotification("");
}

void FFXEditor::reloadButtonSection_Click( )
{
	if ( emulatorProcessID == -1 )
		return;
	
	int panelIndex = ui.menuBox->currentIndex();
	bool result = true;
	result &= panelsMenu[panelIndex]->reloadData();
}

void FFXEditor::saveButtonSection_Click( )
{
	if ( emulatorProcessID == -1 )
		return;
	
	int panelIndex = ui.menuBox->currentIndex();
	bool result = true;
	result &= panelsMenu[panelIndex]->checkData();
	
	if ( result == false )
		return;
	
	result &= panelsMenu[panelIndex]->writeData();
	
	if ( result == true )
		SendNotification("");
}

void FFXEditor::reloadButton_Click( )
{
	if ( emulatorProcessID == -1 )
		return;
	
	int panelIndex = ui.menuBox->currentIndex();
	bool result = true;
	result &= panelsMenu[panelIndex]->reloadData(2);
}

void FFXEditor::SaveButton_Click( )
{
	if ( emulatorProcessID == -1 )
		return;
	
	int panelIndex = ui.menuBox->currentIndex();
	bool result = true;
	result &= panelsMenu[panelIndex]->checkData(2);
	
	if ( result == false )
		return;
	
	result &= panelsMenu[panelIndex]->writeData(2);
	
	if ( result == true )
		SendNotification("");
}

void FFXEditor::menuBox_SelectedIndexChanged( int index )
{
	for ( int i = static_cast<int>(panelsMenu.size() - 1); i >= 0; --i )
		panelsMenu[i]->setVisible(i == index);
}
