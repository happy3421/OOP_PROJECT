#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qspinbox.h>
#include <QtWidgets/qscrollarea.h>
#include <QtWidgets/qradiobutton.h>
#include "player.h"
#include "item/shop.h"
#include "global.h"
class ShopWidget : public QWidget{
	Q_OBJECT
public:
	ShopWidget(QWidget* parent=0);
private slots:
	void buy1();
	void buy2();
	void back();
private:
	QLabel* pg1;
	QLabel* pg2;
	QSpinBox* sb1;
	QSpinBox* sb2;
	QRadioButton* rb11;
	QRadioButton* rb12;
	QRadioButton* rb13;
	QRadioButton* rb14;
	QRadioButton* rb15;
	QRadioButton* rb16;
	QRadioButton* rb21;
	QRadioButton* rb22;
	QRadioButton* rb23;
	QRadioButton* rb24;
	QRadioButton* rb25;
	QRadioButton* rb26;
	Player player1;
	Player player2;
	Shop* shop1;
	Shop* shop2;
};