#include "globals.hpp"
#include "ffxeditor.hpp"
#include "nameIdData.hpp"
#include "cfgFileMng.hpp"
#include "logManager.hpp"

#include <QApplication>

#include <string>
#include <vector>

using std::wstring;
using std::vector;

int emulatorProcessID = -1;

unsigned int BASE_OFFSET = 0;
unsigned int BASE_OFFSET_BASE = 0;
unsigned int BASE_OFFSET_SPECIAL = 0;

unsigned int langVersion = 0;

vector<wstring> abilityNames;

vector<wstring> odRikkuNames;
vector<wstring> odLuluNames;
vector<wstring> odKimahriNames;
vector<wstring> odWakkaNames;
vector<wstring> odAuronNames;
vector<wstring> odTidusNames;

vector<wstring> damageTypeNames;
vector<wstring> weaponNames;
vector<wstring> weaponAbilityNames;
vector<NameIdData> wModelNames;

vector<wstring> guiList;
vector<wstring> infoList;

vector<wstring> itemNames;
vector<wstring> keyItemNames;

FFXEditor *mainWindow;
LogManager *logManager = NULL;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	CfgFileMng cfgFileMng(L"cfg/main.cfg");
	cfgFileMng.loadStart();
	int logLvl = cfgFileMng.getInt(L"logLvl", LogManager::LOG_ERROR);
	logManager = new LogManager("log.txt", logLvl);
	mainWindow = new FFXEditor();
	mainWindow->init(&cfgFileMng);
	cfgFileMng.loadEnd();
	
	mainWindow->show();
	int returnCode = a.exec();
	
	delete logManager;
	
	return returnCode;
}
