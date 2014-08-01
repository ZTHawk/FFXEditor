/*
    FFX-Editor is a cheat tool for PCSX2 and Final Fantasy X.

    Copyright (C) 2014  Karl Zmuda Trzebiatowski <karl.zmuda.trzebiatowski at gmail.com>

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

#include "MyPanel.hpp"

#include <QStyle>

bool MyPanel::checkEntry( QLineEdit *textBox , void *buf , int type )
{
	bool result = true;
	QString str = textBox->text();
	QByteArray arr = str.toLatin1();
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
