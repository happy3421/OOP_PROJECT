#include "statuswidget.h"
#include "mainwindow.h"

StatusWidget::StatusWidget(Player** player, QWidget* parent)
	: QWidget(parent)
{
	record = new Record;
	record->showRecord(player[0], player[1]);
	QLabel* AID = new QLabel(player[0]->getID().c_str(), this);
	AID->setGeometry(QRect(160, 90, 141, 81));

	QLabel* BID = new QLabel(player[1]->getID().c_str(), this);
	BID->setGeometry(QRect(480, 90, 141, 81));
	if(record->getfileExist() == 0){
		if(player[0]->getID().compare(player[1]->getID())<0){
			TEAMAWIN = record->getP1Win();
			TEAMAWIN+= "Win";
			TEAMAWIN+= record->getP2Win();
			TEAMAWIN+= "Lose";
			TEAMBWIN = record->getP2Win();
			TEAMBWIN+= "Win";
			TEAMBWIN+= record->getP1Win();
			TEAMBWIN+= "Lose";
		
		}
		else{
			TEAMBWIN = record->getP1Win();
			TEAMBWIN+= "Win";
			TEAMBWIN+= record->getP2Win();
			TEAMBWIN+= "Lose";
			TEAMAWIN = record->getP2Win();
			TEAMAWIN+= "Win";
			TEAMAWIN+= record->getP1Win();
			TEAMAWIN+= "Lose";
		}

		AWIN = new QLabel(TEAMAWIN.c_str(), this);
		AWIN->setGeometry(QRect(160, 230, 141, 81));

		BWIN = new QLabel(TEAMBWIN.c_str(), this);
		BWIN->setGeometry(QRect(480, 230, 141, 81));

		QPushButton *replay;
		replay = new QPushButton("Show Replay",this);
		replay->setGeometry(QRect(270, 370, 191, 71));
		QObject::connect(replay, SIGNAL(clicked()), this, SLOT(replay()));
	}
	else{
		QLabel* nogame = new QLabel("There is no game between two players!!", this);
		nogame->setGeometry(QRect(320, 230, 360, 81));
	}
	QPushButton *back;
	back = new QPushButton("Back",this);
	back->setGeometry(QRect(600, 500, 141, 51));
	QObject::connect(back, SIGNAL(clicked()), this, SLOT(goToSelect()));

}
StatusWidget::~StatusWidget(){
	delete record;
}
void StatusWidget::goToSelect(){
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setWidget(SELECTWIDGET);
}
void StatusWidget::replay(){
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setWidget(REPLAYWIDGET);
}
