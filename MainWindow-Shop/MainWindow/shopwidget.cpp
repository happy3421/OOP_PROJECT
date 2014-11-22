#include "shopwidget.h"
#include "mainwindow.h"

ShopWidget::ShopWidget(QWidget *parent)
 : QWidget(parent)
{	
	int i1[ITEMTYPE_NUM], i2[ITEMTYPE_NUM];
	for(int i=0; i<ITEMTYPE_NUM; i++) {
		i1[i]=0;
		i2[i]=0;
	}

	player1.setMoney(10000);
	player2.setMoney(10000);

	shop1=new Shop(player1);
	shop2=new Shop(player2);
	
	QLabel *background=new QLabel(this);
	background->setPixmap(QPixmap(QString::fromUtf8("Resources/test.jpg")));
	background->setScaledContents(true);
	background->resize(800,600);

	QLabel *p1=new QLabel("1P",this);
	p1->setGeometry(QRect(20,20,20,12));

	QLabel *p2=new QLabel("2P",this);
	p2->setGeometry(QRect(440,20,20,12));
	
	pg1=new QLabel(QString::number(player1.getMoney()),this);
	pg1->setGeometry(QRect(320,20,60,12));
	pg1->setAlignment(Qt::AlignRight);

	QLabel *g1=new QLabel(" Gold",this);
	g1->setGeometry(QRect(380,20,30,12));
	g1->setAlignment(Qt::AlignRight);
	
	pg2=new QLabel(QString::number(player2.getMoney()),this);
	pg2->setGeometry(QRect(740,20,60,12));
	pg2->setAlignment(Qt::AlignRight);

	QLabel *g2=new QLabel(" Gold",this);
	g2->setGeometry(QRect(800,20,30,12));
	g2->setAlignment(Qt::AlignRight);

	QLabel *q1=new QLabel("Quantity",this);
	q1->setGeometry(QRect(260,400,50,16));
	
	QLabel *q2=new QLabel("Quantity",this);
	q2->setGeometry(QRect(680,400,50,16));
	
	sb1=new QSpinBox(this);
	sb1->setGeometry(QRect(320,400,91,16));
	sb1->setAlignment(Qt::AlignRight);
		
	sb2=new QSpinBox(this);
	sb2->setGeometry(QRect(740,400,91,16));
	sb2->setAlignment(Qt::AlignRight);
		
	QScrollArea *list1=new QScrollArea(this);
	list1->setGeometry(QRect(20,50,390,320));	
	
	QLabel *ii11=new QLabel(list1);
	ii11->setPixmap(QPixmap(QString::fromUtf8("Resources/undo.png")));
	ii11->setGeometry(QRect(20,20,50,50));
	ii11->setScaledContents(true);

	QLabel *it11=new QLabel("Undo",list1);
	it11->setGeometry(QRect(20,70,50,12));
	it11->setAlignment(Qt::AlignHCenter);

	rb11=new QRadioButton(list1);
	rb11->setGeometry(QRect(90,30,16,21));

	QScrollArea *list2=new QScrollArea(this);
	list2->setGeometry(QRect(440,50,390,320));

	QPushButton *buy1;
	buy1 = new QPushButton("Buy",this);
	buy1->setGeometry(QRect(360,430,50,30));
	QObject::connect(buy1, SIGNAL(clicked()), this, SLOT(buy1()));	
	
	QPushButton *buy2;
	buy2 = new QPushButton("Buy",this);
	buy2->setGeometry(QRect(780,430,50,30));
	QObject::connect(buy2, SIGNAL(clicked()), this, SLOT(buy2()));	
	
	QPushButton *back;
	back = new QPushButton("Back",this);
	back->setGeometry(QRect(730,480,100,50));
	QObject::connect(back, SIGNAL(clicked()), this, SLOT(back()));	
}

void ShopWidget::back() {
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setWidget(SELECTWIDGET);
}

void ShopWidget::buy1() {
	int i=0;
	int n=sb1->value();
	if(rb11->isChecked())
		i=1;
	shop1->buyItem(i,n);
	pg1->setText(QString::number(player1.getMoney()));
}

void ShopWidget::buy2() {
	int i=1;
	int n=sb2->value();
	shop2->buyItem(i,n);
	pg2->setText(QString::number(player2.getMoney()));
}