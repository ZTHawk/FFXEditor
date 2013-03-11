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
		
	}
	
	void setInfoID( int infoID )
	{
		this->infoID = infoID;
	}
	int getInfoID( )
	{
		return infoID;
	}
	
	void setText( const QString &str )
	{
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
