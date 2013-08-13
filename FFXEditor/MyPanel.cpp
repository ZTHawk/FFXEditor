#include "MyPanel.hpp"

#include <QStyle>

bool MyPanel::checkEntry( QLineEdit *textBox , void *buf , int type )
{
	bool result = true;
	QString str = textBox->text();
	QByteArray arr = str.toAscii();
	char *cStr = arr.data();
	result &= stringToValue_Check(cStr,
		buf,
		type);
	
	if ( result == false )
		textBox->setProperty("bad", "on");
	else
		textBox->setProperty("bad", "off");
	textBox->style()->unpolish(textBox);
	textBox->style()->polish(textBox);
	
	return result;
};
