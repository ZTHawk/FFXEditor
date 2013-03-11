#ifndef ITEM_PANEL_HPP
#define ITEM_PANEL_HPP

#include "MyPanel.hpp"
#include "ui_ItemPanel.h"

class ItemData;

class ItemPanel : public MyPanel
{
	Q_OBJECT
	
public:
	ItemPanel( QWidget *p );
	~ItemPanel( );
	
	virtual bool reloadData( int depth = 0 );
	virtual bool initData( );
	virtual bool checkData( int depth = 0 );
	virtual bool writeData( int depth = 0 );
	
private:
	Ui::ItemPanel ui;
	ItemData *itemData;
	
	bool eventFilter( QObject *obj , QEvent *ev );
	
protected slots:
	void text_Click( );
};

#endif // ITEM_PANEL_HPP
