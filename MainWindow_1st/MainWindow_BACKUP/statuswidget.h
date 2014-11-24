#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include "Replay/replay.h"
#include "global.h"


//�������������̸� �����ʿ�.
class StatusWidget : public QWidget{
	Q_OBJECT
public:
	StatusWidget(Player**, QWidget* parent=0);
	~StatusWidget();	//delete record
private slots:
	void goToSelect();
	void replay();
private:
	Record *record;	//delete �����ϰ� ����� ����.
	string TEAMAWIN;
	string TEAMBWIN;
	QLabel* AWIN;
	QLabel* BWIN;
};
