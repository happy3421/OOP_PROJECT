#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include "Login.h"
#include "global.h"
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qlayout.h>

#include "dialog.h"


class LoginWidget : public QWidget{
	Q_OBJECT
public:
	LoginWidget(QWidget* parent=0);
	~LoginWidget();
	Login* getLogin();
	void enterSuccess(TEAM);
	void enterComplete();
private slots:
	void enterA();
	void enterB();
	void signUp();
	void quit();
signals:
private:
	Login* login;
	QPushButton *AButton;
	QPushButton *BButton;
	QWidget* newwidget;
	QLineEdit *ALine;	//영어만 입력가능하게할필요
	QLineEdit *BLine;	//영어만 입력가능하게할필요
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