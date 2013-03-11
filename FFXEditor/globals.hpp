#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include "nameIdData.hpp"
#include <string>
#include <vector>

using std::wstring;
using std::vector;

extern int emulatorProcessID;

extern unsigned int BASE_OFFSET;
extern unsigned int BASE_OFFSET_BASE;
extern unsigned int BASE_OFFSET_SPECIAL;

class FFXEditor;
extern FFXEditor *mainWindow;

extern vector<wstring> abilityNames;

extern vector<wstring> odRikkuNames;
extern vector<wstring> odLuluNames;
extern vector<wstring> odKimahriNames;
extern vector<wstring> odWakkaNames;
extern vector<wstring> odAuronNames;
extern vector<wstring> odTidusNames;

extern vector<wstring> damageTypeNames;
extern vector<wstring> weaponNames;
extern vector<wstring> weaponAbilityNames;
extern vector<NameIdData> wModelNames;

extern vector<wstring> infoList;

extern vector<wstring> itemNames;
extern vector<wstring> keyItemNames;

#endif // GLOBALS_HPP
