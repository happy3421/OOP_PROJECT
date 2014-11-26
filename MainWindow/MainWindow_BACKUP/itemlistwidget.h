#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qscrollarea.h>
#include <qsignalmapper.h>
#include "player.h"
#include "item/shop.h"
#include "global.h"

class ItemListWidget : public QWidget{
	Q_OBJECT
public:
	ItemListWidget(Player**, QWidget* parent=0);
private slots:
	void equip0(int iid);
	void equip1(int iid);
	void next();
	void back();
private:
	QLabel* ei[2][3];
	QWidget* newWidget;
	QLabel* pg[2];
	Player** player;
	Shop *shop[2];
};