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
	
	delete mainWindow;
	delete logManager;
	
	return returnCode;
}
