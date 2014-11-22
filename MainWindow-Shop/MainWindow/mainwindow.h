#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "global.h"
#include "player.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
	void setWidget(WIDGETTYPE);
	void show();
	void setPlayer(Player*);
	Player* getPlayer();
private slots:
	void widgetChange();
signals:
	void widgetChangedSignal();
private:
	Ui::MainWindowClass ui;
	const int width;
	const int height;
	WIDGETTYPE widgettype;
	QWidget* widget;
	Player* player;
};

#endif // MAINWINDOW_H
