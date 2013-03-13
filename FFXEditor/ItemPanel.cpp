#include "constants.hpp"
#include "guiNames.hpp"
#include "ItemPanel.hpp"
#include "ItemData.hpp"
#include "constants.hpp"
#include "item_constants.hpp"
#include "offsets.hpp"

#include <QComboBox>
#include <QLineEdit>
#include <QVBoxLayout>

ItemPanel::ItemPanel( QWidget *p )
	: MyPanel(p)
{
	ui.setupUi(this);
	
	itemData = new ItemData();
	
	QHeaderView *hHeader = ui.items_table->horizontalHeader();
	hHeader->setResizeMode(0, QHeaderView::Fixed);
	hHeader->setResizeMode(1, QHeaderView::Fixed);
	hHeader->setResizeMode(2, QHeaderView::Fixed);
	hHeader->setResizeMode(3, QHeaderView::Fixed);
	ui.items_table->setColumnWidth(0, 135);
	ui.items_table->setColumnWidth(1, 30);
	ui.items_table->setColumnWidth(2, 135);
	ui.items_table->setColumnWidth(3, 30);
	
	QColor altBase(Qt::lightGray);
	altBase.setAlpha(150);
	QPalette pal = ui.items_table->palette();
	pal.setColor(QPalette::AlternateBase, altBase);
	ui.items_table->setPalette(pal);
	ui.items_table->setStyleSheet("QTableWidget{background-color: rgba(255, 255, 255, 0);"
		"padding: 2 2 2 2;}");
	
	ui.items_Text->setText(QString::fromStdWString(guiList[GN_IP_ITEM]));
	ui.keyItems_Text->setText(QString::fromStdWString(guiList[GN_IP_KEYS]));
	
	connect(ui.items_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
	connect(ui.keyItems_Text, SIGNAL(clicked()), this, SLOT(text_Click()));
}

ItemPanel::~ItemPanel( )
{
	
}

bool ItemPanel::initData( )
{
	QStringList strLst;
	for ( int i = 0; i < KEY_ITEM_NAMES_SIZE; ++i )
		strLst << QString::fromStdWString(keyItemNames[i]);
	ui.keyItems->addItems(strLst);
	
	QColor base = QColor(Qt::white),
		altBase = QColor(211, 211, 211, 180);
	for ( int i = 0; i < KEY_ITEM_NAMES_SIZE; ++i )
	{
		ui.keyItems->item(i)->setCheckState(Qt::Unchecked);
		ui.keyItems->item(i)->setBackgroundColor((i % 2) == 0 ? base : altBase);
	}
	return reloadData(0);
}

bool ItemPanel::reloadData( int depth )
{
	ui.items_table->clear();
	
	bool result = true;
	result &= itemData->readData();
	if ( result == false )
	{
		SendNotification("Error while reading item data.");
		return false;
	}
	
	int counter = 0;
	int maxCounter = 0;
	for ( int i = 255; i >= 0; --i )
	{
		if ( itemData->itemIDList[i].bitmask > 0
			&& itemData->itemAmountList[i] > 0 )
		{
			maxCounter = i;
			break;
		}
	}
	
	for ( ; counter <= maxCounter; ++counter )
	{
		if ( counter % 2 == 0 )
		{
			ui.items_table->setRowCount((counter / 2) + 1);
			ui.items_table->setRowHeight(counter / 2, 30);
		}
		
		QComboBox *tmpComboBox = new QComboBox(ui.items_table);
		QLineEdit *tmpTextBox = new QLineEdit(ui.items_table);
		tmpTextBox->setFixedHeight(20);
		tmpComboBox->setFixedSize(121, 20);
		tmpTextBox->setStyleSheet("margin: 0 5 0 2;");
		tmpComboBox->view()->setTextElideMode(Qt::ElideNone);
		tmpComboBox->setMaxVisibleItems(30);
		tmpComboBox->installEventFilter(this);
		
		for ( int i = 0; i < ITEM_NAMES_SIZE; ++i )
			tmpComboBox->addItem(QString::fromStdWString(itemNames[i]));
		
		if ( itemData->itemIDList[counter].bitmask == 0 )
			continue;
		
		if ( itemData->itemIDList[counter].itemID >= ITEM_NAMES_SIZE
			|| itemData->itemAmountList[counter] == 0 )
			tmpComboBox->setCurrentIndex(ITEM_NAMES_SIZE - 1);
		else
			tmpComboBox->setCurrentIndex(itemData->itemIDList[counter].itemID);
		tmpTextBox->setText(QString::number(itemData->itemAmountList[counter]));
		
		ui.items_table->setCellWidget(counter / 2, (counter * 2) % 4, tmpComboBox);
		ui.items_table->setCellWidget(counter / 2, ((counter * 2) % 4) + 1, tmpTextBox);
		
		
	}
	
	for ( int i = 0; i < KEY_ITEM_NAMES_SIZE; ++i )
	{
		bool tmp = itemData->isKeyItemSelect(i);
		ui.keyItems->item(i)->setCheckState((tmp == true) ? Qt::Checked : Qt::Unchecked);
	}
	
	return true;
}

bool ItemPanel::eventFilter( QObject *obj , QEvent *ev )
{
	if ( ev->type() == QEvent::Wheel )
	{
		ev->ignore();
		return true;
	}
	return false;
}

bool ItemPanel::checkData( int depth )
{
	int count = ui.items_table->rowCount() * 2;
	bool result = true;
	for ( int i = 0; i < count; ++i )
	{
		result &= checkEntry(dynamic_cast<QLineEdit*>(ui.items_table->cellWidget(i / 2, (i % 2) * 2 + 1)),
			&itemData->itemAmountList[i],
			DATA_ITEM);
		if ( result == false )
		{
			SendNotification("Some item variables are incorrect.");
			break;
		}
	}
	
	int selectedIndex = 0;
	for ( int i = 0; i < count; ++i )
	{
		selectedIndex = (dynamic_cast<QComboBox*>(ui.items_table->cellWidget(i / 2, (i % 2) * 2)))->currentIndex();
		if ( selectedIndex == ITEM_NAMES_SIZE - 1
			|| selectedIndex == -1 )
		{
			itemData->itemIDList[i].itemID = 0xFF;
			itemData->itemIDList[i].bitmask = 0;
		}else
		{
			itemData->itemIDList[i].itemID = (unsigned char)selectedIndex;
			itemData->itemIDList[i].bitmask = 0x20;
		}
	}
	
	itemData->cheackData();
	for ( unsigned char i = 0; i < KEY_ITEM_NAMES_SIZE; ++i )
	{
		itemData->selectKeyItem(i,
			ui.keyItems->item(i)->checkState() == Qt::Checked);
	}
	
	return result;
}

bool ItemPanel::writeData( int depth )
{
	bool result = true;
	
	result &= itemData->writeData();
	
	return result;
}

void ItemPanel::text_Click( )
{
	QObject *tmp = sender();
	if ( tmp == ui.keyItems_Text )
		SendNotificationID(INFO_KEY_ITEMS);
	else
		SendNotificationID(INFO_ITEMS);
}
