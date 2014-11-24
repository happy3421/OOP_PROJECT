#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qspinbox.h>
#include <QtWidgets/qscrollarea.h>
#include <qsignalmapper.h>
#include "player.h"
#include "item/shop.h"
#include "global.h"
class ShopWidget : public QWidget{
	Q_OBJECT
public:
	ShopWidget(Player**, QWidget* parent=0);
	Shop* getShop(int i);
	Player* getPlayer(int i);
	QLabel* getGold(int i);
private slots:
	void buy0(int iid);
	void buy1(int iid);
	void back();
private:
	QWidget* newWidget;
	QLabel* pg[2];
	Player** player;
	Shop *shop[2];
};

class BuyWidget:public QWidget{
	Q_OBJECT
public:
	BuyWidget(ShopWidget* swi, int pid, int iid, QWidget* parent=0);
private slots:
	void buy();
private:
	int pid;
	int iid;
	ShopWidget* sw;
	QSpinBox* isb;
};