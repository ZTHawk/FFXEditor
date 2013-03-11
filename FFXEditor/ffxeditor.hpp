#ifndef FFXEDITOR_HPP
#define FFXEDITOR_HPP

#include <QtGui/QMainWindow>
#include "ui_ffxeditor.h"

#include <vector>

using std::vector;

class MyPanel;

class FFXEditor : public QMainWindow
{
	Q_OBJECT
	
public:
	FFXEditor(QWidget *parent = 0, Qt::WFlags flags = 0);
	~FFXEditor();
	
	void init( );
	void setInfo( QString msg );
	
private:
	Ui::FFXEditorClass ui;
	vector<MyPanel*> panelsMenu;
	
	void initData( );
	void initNames( );
	void initGUINames( );
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
