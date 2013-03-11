#ifndef MY_PANEL_HPP
#define MY_PANEL_HPP

#include "utils.hpp"
#include "iostream"

#include <QByteArray>
#include <QLineEdit>
#include <QPalette>
#include <QString>
#include <QWidget>

class MyPanel : public QWidget
{
public:
	MyPanel( QWidget *p )
		: QWidget(p)
	{
	};
	
	virtual bool initData( ) = 0;
	virtual bool reloadData( int depth = 0 ) = 0;
	virtual bool checkData( int depth = 0 ) = 0;
	virtual bool writeData( int depth = 0 ) = 0;
	bool checkEntry( QLineEdit *textBox , void *buf , int type )
	{
		bool result = true;
		QString str = textBox->text();
		QByteArray arr = str.toAscii();
		char *cStr = arr.data();
		result &= stringToValue_Check(cStr,
			buf,
			type);
		
		if ( result == false )
			textBox->setStyleSheet("background-color: red;");
		else
			textBox->setStyleSheet("");
		
		return result;
	};
	
protected:
	class ButtonData : public QObjectUserData
	{
	public:
		ButtonData( )
		{
		};
		ButtonData( int id )
		{
			infoID = id;
		};
		int infoID;
	};
};

#endif // MY_PANEL_HPP
