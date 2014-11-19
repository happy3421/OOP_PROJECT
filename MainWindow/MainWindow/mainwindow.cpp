#include "mainwindow.h"
#include "logowidget.h"
#include "loginwidget.h"
#include "selectwidget.h"
#include "tutorialwidget.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, width(850), height(600)
{
	ui.setupUi(this);
	setWindowTitle("LaserChess");
	setFixedSize(width,height);
	widget=NULL;

	QObject::connect(this, SIGNAL(widgetChangedSignal()),this,SLOT(widgetChange()));
}
void MainWindow::show(){
	QMainWindow::show();
	this->setWidget(LOGOWIDGET);
}

MainWindow::~MainWindow()
{

}
void MainWindow::setWidget(WIDGETTYPE _widgettype){
	widgettype=_widgettype;
	emit widgetChangedSignal();
}

void MainWindow::widgetChange(){
	if(widget)
		delete widget;

	switch(widgettype){
	case EXIT:
			this->close();
			break;
	case LOGOWIDGET:
		widget= new LogoWidget(this);
		this->setCentralWidget(widget);
		break;
	case LOGINWIDGET:
		widget= new LoginWidget(this);
		this->setCentralWidget(widget);
		break;
	case SELECTWIDGET:
		widget= new SelectWidget(this);
		this->setCentralWidget(widget);
		break;
	case TUTORIALWIDGET:
		widget= new TutorialWidget(this);
		this->setCentralWidget(widget);
		break;
	}
}
void MainWindow::setPlayer(Player* _player){
	player=_player;
}
Player* MainWindow::getPlayer(){
	return player;
}