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
