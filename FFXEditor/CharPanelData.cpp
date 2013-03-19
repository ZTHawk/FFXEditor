#include "constants.hpp"
#include "guiNames.hpp"
#include "info.hpp"
#include "CharPanelData.hpp"
#include "CharData.hpp"

CharPanelData::CharPanelData( QWidget *p )
	: MyPanel(p)
{
	ui.setupUi(this);
	
	ui.attack_Text->setText(QString::fromStdWString(guiList[GN_CP_D_ATT]));
	ui.defense_Text->setText(QString::fromStdWString(guiList[GN_CP_D_DEF]));
	ui.magic_Text->setText(QString::fromStdWString(guiList[GN_CP_D_MAG]));
	ui.magicDef_Text->setText(QString::fromStdWString(guiList[GN_CP_D_MDEF]));
	ui.speed_Text->setText(QString::fromStdWString(guiList[GN_CP_D_SPD]));
	ui.luck_Text->setText(QString::fromStdWString(guiList[GN_CP_D_LUCK]));
	ui.evade_Text->setText(QString::fromStdWString(guiList[GN_CP_D_EVA]));
	ui.hit_Text->setText(QString::fromStdWString(guiList[GN_CP_D_HIT]));
	ui.hp_Text->setText(QString::fromStdWString(guiList[GN_CP_D_HP]));
	ui.mp_Text->setText(QString::fromStdWString(guiList[GN_CP_D_MP]));
	ui.curAP_Text->setText(QString::fromStdWString(guiList[GN_CP_D_AP]));
	ui.AP_got_till_next_lvl_Text->setText(QString::fromStdWString(guiList[GN_CP_D_AP_N]));
	ui.overdrive_Text->setText(QString::fromStdWString(guiList[GN_CP_D_OD]));
	ui.s_lv_Text->setText(QString::fromStdWString(guiList[GN_CP_D_SLV]));
	ui.battles_Text->setText(QString::fromStdWString(guiList[GN_CP_D_BAT]));
	ui.enemys_Text->setText(QString::fromStdWString(guiList[GN_CP_D_KILL]));
	ui.deaths_Text->setText(QString::fromStdWString(guiList[GN_CP_D_DEATH]));
	ui.overdrive_modes_Text->setText(QString::fromStdWString(guiList[GN_CP_D_OD_M]));
	ui.overdrive_warrior_Text->setText(QString::fromStdWString(guiList[GN_CP_D_WAR]));
	ui.overdrive_comrade_Text->setText(QString::fromStdWString(guiList[GN_CP_D_COM]));
	ui.overdrive_healer_Text->setText(QString::fromStdWString(guiList[GN_CP_D_HEAL]));
	ui.overdrive_tactician_Text->setText(QString::fromStdWString(guiList[GN_CP_D_TAC]));
	ui.overdrive_victim_Text->setText(QString::fromStdWString(guiList[GN_CP_D_VICM]));
	ui.overdrive_dancer_Text->setText(QString::fromStdWString(guiList[GN_CP_D_DANC]));
	ui.overdrive_avenger_Text->setText(QString::fromStdWString(guiList[GN_CP_D_AVEN]));
	ui.overdrive_slayer_Text->setText(QString::fromStdWString(guiList[GN_CP_D_SLAY]));
	ui.overdrive_hero_Text->setText(QString::fromStdWString(guiList[GN_CP_D_HERO]));
	ui.overdrive_rook_Text->setText(QString::fromStdWString(guiList[GN_CP_D_ROOK]));
	ui.overdrive_victor_Text->setText(QString::fromStdWString(guiList[GN_CP_D_VIC]));
	ui.overdrive_coward_Text->setText(QString::fromStdWString(guiList[GN_CP_D_COW]));
	ui.overdrive_ally_Text->setText(QString::fromStdWString(guiList[GN_CP_D_ALLY]));
	ui.overdrive_sufferer_Text->setText(QString::fromStdWString(guiList[GN_CP_D_SUF]));
	ui.overdrive_daredevil_Text->setText(QString::fromStdWString(guiList[GN_CP_D_DARE]));
	ui.overdrive_solo_Text->setText(QString::fromStdWString(guiList[GN_CP_D_SOLO]));
	
	ui.attack_Text->setInfoID(INFO_ATTACK);
	ui.defense_Text->setInfoID(INFO_DEFENSE);
	ui.magic_Text->setInfoID(INFO_MAGIC);
	ui.magicDef_Text->setInfoID(INFO_MAGIC_DEF);
	ui.speed_Text->setInfoID(INFO_SPEED);
	ui.luck_Text->setInfoID(INFO_LUCK);
	ui.evade_Text->setInfoID(INFO_EVADE);
	ui.hit_Text->setInfoID(INFO_HIT);
	ui.hp_Text->setInfoID(INFO_HP);
	ui.mp_Text->setInfoID(INFO_MP);
	ui.curAP_Text->setInfoID(INFO_AP);
	ui.AP_got_till_next_lvl_Text->setInfoID(INFO_AP_NEXT);
	ui.overdrive_Text->setInfoID(INFO_OVERDRIVE);
	ui.s_lv_Text->setInfoID(INFO_S_LV);
	ui.battles_Text->setInfoID(INFO_BATTLES);
	ui.enemys_Text->setInfoID(INFO_ENEMYS);
	ui.deaths_Text->setInfoID(INFO_DEATHS);
	ui.overdrive_modes_Text->setInfoID(INFO_OVERDRIVE_MODES);
	ui.overdrive_warrior_Text->setInfoID(INFO_OVERDRIVE_WARRIOR);
	ui.overdrive_comrade_Text->setInfoID(INFO_OVERDRIVE_COMRADE);
	ui.overdrive_healer_Text->setInfoID(INFO_OVERDRIVE_HEALER);
	ui.overdrive_tactician_Text->setInfoID(INFO_OVERDRIVE_TACTICIAN);
	ui.overdrive_victim_Text->setInfoID(INFO_OVERDRIVE_VICTIM);
	ui.overdrive_dancer_Text->setInfoID(INFO_OVERDRIVE_DANCER);
	ui.overdrive_avenger_Text->setInfoID(INFO_OVERDRIVE_AVENGER);
	ui.overdrive_slayer_Text->setInfoID(INFO_OVERDRIVE_SLAYER);
	ui.overdrive_hero_Text->setInfoID(INFO_OVERDRIVE_HERO);
	ui.overdrive_rook_Text->setInfoID(INFO_OVERDRIVE_ROOK);
	ui.overdrive_victor_Text->setInfoID(INFO_OVERDRIVE_VICTOR);
	ui.overdrive_coward_Text->setInfoID(INFO_OVERDRIVE_COWARD);
	ui.overdrive_ally_Text->setInfoID(INFO_OVERDRIVE_ALLY);
	ui.overdrive_sufferer_Text->setInfoID(INFO_OVERDRIVE_SUFFERER);
	ui.overdrive_daredevil_Text->setInfoID(INFO_OVERDRIVE_DAREDEVIL);
	ui.overdrive_solo_Text->setInfoID(INFO_OVERDRIVE_SOLO);
	
	connect(ui.attack_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.defense_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.magic_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.magicDef_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.speed_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.luck_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.evade_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.hit_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.hp_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.mp_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.curAP_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.AP_got_till_next_lvl_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.overdrive_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.s_lv_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.battles_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.enemys_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.deaths_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.overdrive_modes_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.overdrive_warrior_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.overdrive_comrade_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.overdrive_healer_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.overdrive_tactician_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.overdrive_victim_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.overdrive_dancer_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.overdrive_avenger_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.overdrive_slayer_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.overdrive_hero_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.overdrive_rook_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.overdrive_victor_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.overdrive_coward_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.overdrive_ally_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.overdrive_sufferer_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.overdrive_daredevil_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.overdrive_solo_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
}

CharPanelData::~CharPanelData( )
{
	
}

bool CharPanelData::initData( )
{
	return true;
}

bool CharPanelData::reloadData( int depth )
{
	return true;
}

void CharPanelData::SetVariables( CharData *charData )
{
	ui.attack_basic->setText(QString::number(charData->data->attributes_basic[0]));
	ui.attack_current->setText(QString::number(charData->data->attributes[0]));
	ui.defense_basic->setText(QString::number(charData->data->attributes_basic[1]));
	ui.defense_current->setText(QString::number(charData->data->attributes[1]));
	ui.magic_basic->setText(QString::number(charData->data->attributes_basic[2]));
	ui.magic_current->setText(QString::number(charData->data->attributes[2]));
	ui.magicDef_basic->setText(QString::number(charData->data->attributes_basic[3]));
	ui.magicDef_current->setText(QString::number(charData->data->attributes[3]));
	ui.speed_basic->setText(QString::number(charData->data->attributes_basic[4]));
	ui.speed_current->setText(QString::number(charData->data->attributes[4]));
	ui.luck_basic->setText(QString::number(charData->data->attributes_basic[5]));
	ui.luck_current->setText(QString::number(charData->data->attributes[5]));
	ui.evade_basic->setText(QString::number(charData->data->attributes_basic[6]));
	ui.evade_current->setText(QString::number(charData->data->attributes[6]));
	ui.hit_basic->setText(QString::number(charData->data->attributes_basic[7]));
	ui.hit_current->setText(QString::number(charData->data->attributes[7]));
	
	ui.hp_max_base->setText(QString::number(charData->data->hp_base_max));
	ui.mp_max_base->setText(QString::number(charData->data->mp_base_max));
	ui.curAP->setText(QString::number(charData->data->ap));
	ui.AP_got_till_next_lvl->setText(QString::number(charData->data->ap_next));
	ui.hp_current->setText(QString::number(charData->data->hp));
	ui.mp_current->setText(QString::number(charData->data->mp));
	ui.hp_max ->setText(QString::number(charData->data->hp_max));
	ui.mp_max->setText(QString::number(charData->data->mp_max));
	
	ui.overdrive_current->setText(QString::number(charData->data->overdrive_points));
	ui.overdrive_max->setText(QString::number(charData->data->overdrive_points_needed));
	
	ui.s_lv_current->setText(QString::number(charData->data->s_lv));
	ui.s_lv_used->setText(QString::number(charData->data->s_lv_used));
	
	ui.battles->setText(QString::number(charData->data->battles_won));
	ui.enemys->setText(QString::number(charData->data->enemys_killed));
	ui.deaths->setText(QString::number(charData->data->deaths));
	
	ui.overdrive_warrior->setText(QString::number(charData->data->overdrive_modes[0]));
	ui.overdrive_comrade->setText(QString::number(charData->data->overdrive_modes[1]));
	ui.overdrive_healer->setText(QString::number(charData->data->overdrive_modes[3]));
	ui.overdrive_tactician->setText(QString::number(charData->data->overdrive_modes[4]));
	ui.overdrive_victim->setText(QString::number(charData->data->overdrive_modes[5]));
	ui.overdrive_dancer->setText(QString::number(charData->data->overdrive_modes[6]));
	ui.overdrive_avenger->setText(QString::number(charData->data->overdrive_modes[7]));
	ui.overdrive_slayer->setText(QString::number(charData->data->overdrive_modes[8]));
	ui.overdrive_hero->setText(QString::number(charData->data->overdrive_modes[9]));
	ui.overdrive_rook->setText(QString::number(charData->data->overdrive_modes[10]));
	ui.overdrive_victor->setText(QString::number(charData->data->overdrive_modes[11]));
	ui.overdrive_coward->setText(QString::number(charData->data->overdrive_modes[12]));
	ui.overdrive_ally->setText(QString::number(charData->data->overdrive_modes[13]));
	ui.overdrive_sufferer->setText(QString::number(charData->data->overdrive_modes[14]));
	ui.overdrive_daredevil->setText(QString::number(charData->data->overdrive_modes[15]));
	ui.overdrive_solo->setText(QString::number(charData->data->overdrive_modes[16]));
}

bool CharPanelData::GetVariables( CharData *charData )
{
	bool result = true;
	result &= checkEntry(ui.attack_basic, &charData->data->attributes_basic[0], DATA_ATTRIBUTE);
	result &= checkEntry(ui.attack_current, &charData->data->attributes[0], DATA_ATTRIBUTE);
	result &= checkEntry(ui.defense_basic, &charData->data->attributes_basic[1], DATA_ATTRIBUTE);
	result &= checkEntry(ui.defense_current, &charData->data->attributes[1], DATA_ATTRIBUTE);
	result &= checkEntry(ui.magic_basic, &charData->data->attributes_basic[2], DATA_ATTRIBUTE);
	result &= checkEntry(ui.magic_current, &charData->data->attributes[2], DATA_ATTRIBUTE);
	result &= checkEntry(ui.magicDef_basic, &charData->data->attributes_basic[3], DATA_ATTRIBUTE);
	result &= checkEntry(ui.magicDef_current, &charData->data->attributes[3], DATA_ATTRIBUTE);
	result &= checkEntry(ui.speed_basic, &charData->data->attributes_basic[4], DATA_ATTRIBUTE);
	result &= checkEntry(ui.speed_current, &charData->data->attributes[4], DATA_ATTRIBUTE);
	result &= checkEntry(ui.luck_basic, &charData->data->attributes_basic[5], DATA_ATTRIBUTE);
	result &= checkEntry(ui.luck_current, &charData->data->attributes[5], DATA_ATTRIBUTE);
	result &= checkEntry(ui.evade_basic, &charData->data->attributes_basic[6], DATA_ATTRIBUTE);
	result &= checkEntry(ui.evade_current, &charData->data->attributes[6], DATA_ATTRIBUTE);
	result &= checkEntry(ui.hit_basic, &charData->data->attributes_basic[7], DATA_ATTRIBUTE);
	result &= checkEntry(ui.hit_current, &charData->data->attributes[7], DATA_ATTRIBUTE);
	
	// ap_hp_mp
	result &= checkEntry(ui.hp_max_base, &charData->data->hp_base_max, DATA_HP);
	result &= checkEntry(ui.mp_max_base, &charData->data->mp_base_max, DATA_HP);
	result &= checkEntry(ui.curAP, &charData->data->ap, DATA_UINT);
	result &= checkEntry(ui.AP_got_till_next_lvl, &charData->data->ap_next, DATA_UINT);
	result &= checkEntry(ui.hp_current, &charData->data->hp, DATA_HP);
	result &= checkEntry(ui.mp_current, &charData->data->mp, DATA_HP);
	result &= checkEntry(ui.hp_max, &charData->data->hp_max, DATA_HP);
	result &= checkEntry(ui.mp_max, &charData->data->mp_max, DATA_HP);
	
	// overdrive
	result &= checkEntry(ui.overdrive_current, &charData->data->overdrive_points, DATA_UCHAR);
	result &= checkEntry(ui.overdrive_max, &charData->data->overdrive_points_needed, DATA_UCHAR);
	
	// s_lvl
	result &= checkEntry(ui.s_lv_current, &charData->data->s_lv, DATA_UCHAR);
	result &= checkEntry(ui.s_lv_used, &charData->data->s_lv_used, DATA_UCHAR);
	
	// battle_status
	result &= checkEntry(ui.battles, &charData->data->battles_won, DATA_UINT);
	result &= checkEntry(ui.enemys, &charData->data->enemys_killed, DATA_UINT);
	result &= checkEntry(ui.deaths, &charData->data->deaths, DATA_UINT);
	
	// overdrive modes
	result &= checkEntry(ui.overdrive_warrior, &charData->data->overdrive_modes[0], DATA_USHORT);
	result &= checkEntry(ui.overdrive_comrade, &charData->data->overdrive_modes[1], DATA_USHORT);
	result &= checkEntry(ui.overdrive_healer, &charData->data->overdrive_modes[3], DATA_USHORT);
	result &= checkEntry(ui.overdrive_tactician, &charData->data->overdrive_modes[4], DATA_USHORT);
	result &= checkEntry(ui.overdrive_victim, &charData->data->overdrive_modes[5], DATA_USHORT);
	result &= checkEntry(ui.overdrive_dancer, &charData->data->overdrive_modes[6], DATA_USHORT);
	result &= checkEntry(ui.overdrive_avenger, &charData->data->overdrive_modes[7], DATA_USHORT);
	result &= checkEntry(ui.overdrive_slayer, &charData->data->overdrive_modes[8], DATA_USHORT);
	result &= checkEntry(ui.overdrive_hero, &charData->data->overdrive_modes[9], DATA_USHORT);
	result &= checkEntry(ui.overdrive_rook, &charData->data->overdrive_modes[10], DATA_USHORT);
	result &= checkEntry(ui.overdrive_victor, &charData->data->overdrive_modes[11], DATA_USHORT);
	result &= checkEntry(ui.overdrive_coward, &charData->data->overdrive_modes[12], DATA_USHORT);
	result &= checkEntry(ui.overdrive_ally, &charData->data->overdrive_modes[13], DATA_USHORT);
	result &= checkEntry(ui.overdrive_sufferer, &charData->data->overdrive_modes[14], DATA_USHORT);
	result &= checkEntry(ui.overdrive_daredevil, &charData->data->overdrive_modes[15], DATA_USHORT);
	result &= checkEntry(ui.overdrive_solo, &charData->data->overdrive_modes[16], DATA_USHORT);
	
	charData->error = !result;
	
	return result;
}

bool CharPanelData::checkData( int depth )
{
	return true;
}

bool CharPanelData::writeData( int depth )
{
	return true;
}

void CharPanelData::text_Click( )
{
	MyLabel *label = dynamic_cast<MyLabel*>(sender());
	SendNotificationID(label->getInfoID());
}
