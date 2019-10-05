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

#ifndef MY_LABEL_HPP
#define MY_LABEL_HPP

#include <QLabel>
#include <QMouseEvent>

class MyLabel : public QLabel
{
	Q_OBJECT
public:
	MyLabel( QWidget *p )
		: QLabel(p)
	{
		infoID = -1;
	}
	
	void setInfoID( int infoID )
	{
		this->infoID = infoID;
	}
	int getInfoID( )
	{
		return infoID;
	}
	
	void setText( const QString &str , bool autoColon = true )
	{
		if ( autoColon == true )
			QLabel::setText(str + QString(":"));
		else
			QLabel::setText(str);
		adjustSize();
	}
	
private:
	int infoID;
	
signals:
	void clicked( );
	
protected:
	void mouseReleaseEvent( QMouseEvent *ev )
	{
		QLabel::mouseReleaseEvent(ev);
		if ( ev->button() == Qt::LeftButton )
		{
			ev->accept();
			emit clicked();
		}
	};
};

#endif // MY_LABEL_HPP
