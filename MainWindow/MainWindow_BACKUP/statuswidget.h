#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include "Replay/replay.h"
#include "global.h"


//전적저장파일이름 변경필요.
class StatusWidget : public QWidget{
	Q_OBJECT
public:
	StatusWidget(Player**, QWidget* parent=0);
	~StatusWidget();	//delete record
private slots:
	void goToSelect();
	void replay();
private:
	Record *record;	//delete 가능하게 멤버로 선언.
	string TEAMAWIN;
	string TEAMBWIN;
	QLabel* AWIN;
	QLabel* BWIN;
};
