#ifndef WEAPON_PANEL_HPP
#define WEAPON_PANEL_HPP

#include "MyPanel.hpp"
#include "ui_WeaponPanel.h"

#include <vector>

using std::vector;

class QComboBox;
class WeaponData;
typedef struct _WEAPONDATA WEAPONDATA, *PWEAPONDATA;

class WeaponPanel : public MyPanel
{
	Q_OBJECT

public:
	WeaponPanel( QWidget *p );
	~WeaponPanel( );
	
	virtual bool reloadData( int depth = 0 );
	virtual bool initData( );
	virtual bool checkData( int depth = 0 );
	virtual bool writeData( int depth = 0 );
	
private:
	Ui::WeaponPanel ui;
	WeaponData *weaponData;
	vector<QComboBox*> abilityList;
	int lastSelectedIndex;
	int lastSelectedWeaponsNameIndex;
	
	bool getVariables( PWEAPONDATA wData );
	void setVariables( WEAPONDATA wData );
	int arrayIndexToWeaponModelIndex( int index );
	int weaponModelIndexToArrayIndex( unsigned short weaponModelIndex );
	
protected slots:
	void text_Click( );
	void slotSelection_SelectedIndexChanged( int index );
	void weaponSlotCnt_SelectedIndexChanged( int index );
	void weaponType_SelectedIndexChanged( int index );
	void weaponModel_SelectedIndexChanged( int index );
	void weaponName_SelectedIndexChanged( int index );
};

#endif // WEAPON_PANEL_HPP
