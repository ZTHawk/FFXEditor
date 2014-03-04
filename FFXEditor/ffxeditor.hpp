#ifndef FFXEDITOR_HPP
#define FFXEDITOR_HPP

#include <QMainWindow>
#include "ui_ffxeditor.h"

#include <vector>

using std::vector;

class MyPanel;
class CfgFileMng;

class FFXEditor : public QMainWindow
{
	Q_OBJECT
	
public:
	FFXEditor(QWidget *parent = 0, Qt::WFlags flags = 0);
	~FFXEditor();
	
	void init( CfgFileMng *cfgFileMng );
	void setInfo( QString msg );
	
private:
	enum PANEL_INDEXES
	{
		PANEL_CHAR = 0,
		PANEL_ITEM,
		PANEL_AEON,
		PANEL_OVERDRIVE,
		PANEL_WEAPON,
		PANEL_GLOBAL,
		PANEL_BATTLE,
		
		PANEL_COUNT,
	};
	Ui::FFXEditorClass ui;
	vector<MyPanel*> panelsMenu;
	
	void initData( bool errorOccured );
	void initNames( );
	void initGUINames( );
	void initInfoNames( );
	void initOverdriveNames( );
	void initAbilityNames( );
	void initItemNames( );
	void initKeyItemNames( );
	void initModelNames( );
	void initWeaponAbilityNames( );
	void initWeaponDmgTypeNames( );
	void initWeaponNames( );
	void addModelNameData( std::wstring name , int id );
	
public slots:
	void reloadButton_Click( );
	void SaveButton_Click( );
	void reloadButtonSection_Click( );
	void saveButtonSection_Click( );
	void reloadButtonAll_Click( );
	void saveButtonAll_Click( );
	void menuBox_SelectedIndexChanged( int index );
};

#endif // FFXEDITOR_HPP
