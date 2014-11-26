#include "selectwidget.h"
#include "mainwindow.h"

SelectWidget::SelectWidget(QWidget *parent)
 : QWidget(parent)
{	
	QLabel *background=new QLabel(this);
	background->setPixmap(QPixmap(QString::fromUtf8("Resources/test.jpg")));
	background->setScaledContents(true);
	background->resize(850,600);

	QPushButton *gamestart= new QPushButton("gamestart",this);
	gamestart->setGeometry(QRect(425,100,200,50));
	QObject::connect(gamestart, SIGNAL(clicked()), this, SLOT(goToGame()));

	QPushButton *tutorial= new QPushButton("tutorial",this);
	tutorial->setGeometry(QRect(425,200,200,50));
	QObject::connect(tutorial, SIGNAL(clicked()), this, SLOT(goToTutorial()));	

	QPushButton *shop= new QPushButton("shop",this);
	shop->setGeometry(QRect(425,300,200,50));
	QObject::connect(shop, SIGNAL(clicked()), this, SLOT(goToShop()));	

	QPushButton *status= new QPushButton("status",this);
	status->setGeometry(QRect(425,400,200,50));
	QObject::connect(status, SIGNAL(clicked()), this, SLOT(goToStatus()));	

	QPushButton *exit= new QPushButton("exit",this);
	exit->setGeometry(QRect(425,500,200,50));
	QObject::connect(exit, SIGNAL(clicked()), this, SLOT(quit()));	
}
void SelectWidget::goToGame(){
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setWidget(ITEMLISTWIDGET);
}
void SelectWidget::goToTutorial(){
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setWidget(TUTORIALWIDGET);
}
void SelectWidget::goToShop(){
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setWidget(SHOPWIDGET);
}
void SelectWidget::goToStatus(){
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setWidget(STATUSWIDGET);
}
void SelectWidget::quit(){
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setWidget(EXIT);
}