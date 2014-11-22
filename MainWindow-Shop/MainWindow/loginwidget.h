#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include "Login.h"
#include "global.h"
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qlayout.h>

class LoginWidget : public QWidget{
	Q_OBJECT
public:
	LoginWidget(QWidget* parent=0);
	Login* getLogin();
private slots:
	void enterA();
	void enterB();
	void signUp();
	void enterASuccess();
	void enterBSuccess();
	void checkABSuccess();
	void nextWidget();
	void quit();
signals:
	void Success();
private:
	Login* login;
	QPushButton *AButton;
	QPushButton *BButton;
	QWidget* newwidget;
	QLineEdit *ALine;
	QLineEdit *BLine;
	bool success[2];
};

class signupwidget : public QWidget{
	Q_OBJECT
public:
	signupwidget(LoginWidget*, QWidget* parent=0);
private slots:
	void okay();
private:
	LoginWidget *loginwidget;
	QLineEdit* IDLine;
	QLineEdit* pwdLine;
	QLineEdit* repwdLine;
};

class enterwidget : public QWidget{
	Q_OBJECT
public:
	enterwidget(LoginWidget*, TEAM, QWidget* parent=0);
private slots:
	void okay();
private:
	LoginWidget *loginwidget;
	TEAM team;
	QLineEdit* IDLine;
	QLineEdit* pwdLine;
};