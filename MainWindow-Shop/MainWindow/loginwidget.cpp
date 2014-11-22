#include "loginwidget.h"
#include "mainwindow.h"

//signup위젯, enter위젯에서 QLineEdit 10글자이하로 설정하기!!!!
//질문??????? mainwindow에서 delete loginwidget을 하면 login도 delete될까?
LoginWidget::LoginWidget(QWidget *parent)
 : QWidget(parent)
{	
	login=new Login;
	success[0]=false;
	success[1]=false;

	QLabel *background;
	background=new QLabel(this);
	background->setPixmap(QPixmap(QString::fromUtf8("Resources/test.jpg")));
	background->setScaledContents(true);
	background->resize(850,600);

	QPushButton *exit;
	exit = new QPushButton("exit",this);
	exit->setGeometry(QRect(300,100,140,100));
	QObject::connect(exit, SIGNAL(clicked()), this, SLOT(quit()));	

	AButton = new QPushButton("loginA",this);
	AButton->setGeometry(QRect(300,200,140,100));
	QObject::connect(AButton, SIGNAL(clicked()), this, SLOT(enterA()));

	BButton = new QPushButton("loginB",this);
	BButton->setGeometry(QRect(300,300,140,100));
	QObject::connect(BButton, SIGNAL(clicked()), this, SLOT(enterB()));

	QPushButton *signup;
	signup = new QPushButton("signup",this);
	signup->setGeometry(QRect(300,400,140,100));
	QObject::connect(signup, SIGNAL(clicked()), this, SLOT(signUp()));

	ALine = new QLineEdit("GoToLoginA",this);
	ALine->setGeometry(QRect(200,10,150,50));
	ALine->setReadOnly(true);
	BLine = new QLineEdit("GoToLoginB",this);
	BLine->setGeometry(QRect(400,10,150,50));
	BLine->setReadOnly(true);

	QObject::connect(this,SIGNAL(Success()),this,SLOT(checkABSuccess()));
}

void LoginWidget::checkABSuccess(){
	if(success[0] & success[1]){
		QPushButton* success=new QPushButton("success!! press OK", 0);
		success->setWindowFlags(Qt::CustomizeWindowHint);
		success->setGeometry(500,300,300,50);
		QObject::connect(success, SIGNAL(clicked()), success, SLOT(close()));
		QObject::connect(success, SIGNAL(clicked()), this, SLOT(nextWidget()));
		success->show();
	}
}
void LoginWidget::nextWidget(){
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setPlayer(this->login->getPlayer());	//로그인정보를 mainwindow에 옮김
	mainwindow->setWidget(SELECTWIDGET);
}

void LoginWidget::quit(){
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setWidget(EXIT);
}
void LoginWidget::signUp(){
	newwidget= new signupwidget(this,0);	//close하면 자동으로 delete되는듯
}
void LoginWidget::enterA(){
	if(success[0]){
		QLabel* already=new QLabel("already",0);
		already->show();
	}
	else
		newwidget= new enterwidget(this, ATEAM,0);
}
void LoginWidget::enterB(){
	if(success[1]){
		QLabel* already=new QLabel("already",0);
		already->show();
	}
	else
		newwidget= new enterwidget(this, BTEAM,0);
}

void LoginWidget::enterASuccess(){
	success[0]=true;
	ALine->setText("LoginA completed");
	emit Success();
}
void LoginWidget::enterBSuccess(){
	success[1]=true;
	BLine->setText("LoginB completed");
	emit Success();
}
Login* LoginWidget::getLogin(){return login;}
///////////////////////////////////////////////////////////////////////////
signupwidget::signupwidget(LoginWidget* _loginwidget, QWidget *parent)
 : QWidget(parent)
{	
	loginwidget=_loginwidget;

	IDLine = new QLineEdit();
		IDLine->setEchoMode(QLineEdit::Normal);
	pwdLine = new QLineEdit();
		pwdLine->setEchoMode(QLineEdit::Password);
	repwdLine = new QLineEdit();
		repwdLine->setEchoMode(QLineEdit::Password);
		
	QHBoxLayout *IDBox= new QHBoxLayout;
		IDBox->addWidget(new QLabel("ID"));
		IDBox->addWidget(IDLine);
	QHBoxLayout *pwdBox= new QHBoxLayout;
		pwdBox->addWidget(new QLabel("pwd"));
		pwdBox->addWidget(pwdLine);
	QHBoxLayout *repwdBox= new QHBoxLayout;
		repwdBox->addWidget(new QLabel("repwd"));
		repwdBox->addWidget(repwdLine);
	QVBoxLayout *VBox=new QVBoxLayout;
		VBox->addLayout(IDBox);
		VBox->addLayout(pwdBox);
		VBox->addLayout(repwdBox);
	
	setLayout(VBox);
	this->resize(520,300);
	//addLayout; VBox <= IDBox, pwdBox, repwdBox
	//setLayout; this <= VBox
	//setLayout; this <= addwidgets
	
	QPushButton* okay=new QPushButton("okay",this);
	okay->setGeometry(100,250,50,50);
	QObject::connect(okay, SIGNAL(clicked()), this, SLOT(okay()));
	
	QPushButton* cancel=new QPushButton("cancel",this);
	cancel->setGeometry(300,250,50,50);
	QObject::connect(cancel, SIGNAL(clicked()), this, SLOT(close()));
	
	this->show();
}
void signupwidget::okay(){
	//QString->QByteArray->char*
	//바로 붙이면 안되더라... 졸헤맴.
	QByteArray _id=IDLine->text().toLocal8Bit();
	QByteArray _pwd=pwdLine->text().toLocal8Bit();
	QByteArray _repwd=repwdLine->text().toLocal8Bit();
	char* id=_id.data();
	char* pwd=_pwd.data();
	char* repwd=_repwd.data();

	int signup = loginwidget->getLogin()->signUp(id,pwd,repwd);
	if(signup==EXISTING_ID){
		QPushButton* message=new QPushButton("existing id",0);
		message->setWindowFlags(Qt::CustomizeWindowHint);
		message->setGeometry(500,300,300,50);
		QObject::connect(message, SIGNAL(clicked()), message, SLOT(close()));
		message->show();
	}
	else if(signup==DIFFERENT_REPWD){
		QPushButton* message=new QPushButton("different repwd",0);
		message->setWindowFlags(Qt::CustomizeWindowHint);
		message->setGeometry(500,300,300,50);
		QObject::connect(message, SIGNAL(clicked()), message, SLOT(close()));
		message->show();
	}
	else if(signup==SUCCESS_SIGNUP){
		QPushButton* message=new QPushButton("SUCCESS_SIGNUP!",0);
		message->setWindowFlags(Qt::CustomizeWindowHint);
		message->setGeometry(500,300,300,50);
		QObject::connect(message, SIGNAL(clicked()), message, SLOT(close()));
		QObject::connect(message, SIGNAL(clicked()), this, SLOT(close()));
		message->show();
	}
}

/////////////////////////////////////////////////////////////////////////////////////////

enterwidget::enterwidget(LoginWidget* _loginwidget, TEAM _team, QWidget *parent)
 : QWidget(parent)
{	
	loginwidget=_loginwidget;
	team=_team;

	IDLine = new QLineEdit();
		IDLine->setEchoMode(QLineEdit::Normal);
	pwdLine = new QLineEdit();
		pwdLine->setEchoMode(QLineEdit::Password);
		
	QHBoxLayout *IDBox= new QHBoxLayout;
		IDBox->addWidget(new QLabel("ID"));
		IDBox->addWidget(IDLine);
	QHBoxLayout *pwdBox= new QHBoxLayout;
		pwdBox->addWidget(new QLabel("pwd"));
		pwdBox->addWidget(pwdLine);
	QVBoxLayout *VBox=new QVBoxLayout;
		VBox->addLayout(IDBox);
		VBox->addLayout(pwdBox);
	
	setLayout(VBox);
	this->resize(520,300);

	QPushButton* okay=new QPushButton("okay",this);
	okay->setGeometry(100,250,50,50);
	QObject::connect(okay, SIGNAL(clicked()), this, SLOT(okay()));
	
	QPushButton* cancel=new QPushButton("cancel",this);
	cancel->setGeometry(400,250,50,50);
	QObject::connect(cancel, SIGNAL(clicked()), this, SLOT(close()));

	this->show();
}
void enterwidget::okay(){
	QByteArray _id=IDLine->text().toLocal8Bit();
	QByteArray _pwd=pwdLine->text().toLocal8Bit();
	char* id=_id.data();
	char* pwd=_pwd.data();
	
	int enter = loginwidget->getLogin()->enter(id,pwd,team);
	if(enter==NOEXISTING_ID){
		QPushButton* message=new QPushButton("noexisting id",0);
		message->setWindowFlags(Qt::CustomizeWindowHint);
		message->setGeometry(500,300,300,50);
		QObject::connect(message, SIGNAL(clicked()), message, SLOT(close()));
		message->show();
	}
	else if(enter==SAME_ID){
		QPushButton* message=new QPushButton("between players, same id",0);
		message->setWindowFlags(Qt::CustomizeWindowHint);
		message->setGeometry(500,300,300,50);
		QObject::connect(message, SIGNAL(clicked()), message, SLOT(close()));
		message->show();
	}
	else if(enter==DIFFERENT_PWD){
		QPushButton* message=new QPushButton("pwd false",0);
		message->setWindowFlags(Qt::CustomizeWindowHint);
		message->setGeometry(500,300,300,50);
		QObject::connect(message, SIGNAL(clicked()), message, SLOT(close()));
		message->show();
	}
	else if(enter==SUCCESS_ENTER){
		QPushButton* message=new QPushButton("SUCCESS!",0);
		message->setWindowFlags(Qt::CustomizeWindowHint);
		message->setGeometry(500,300,300,50);
		QObject::connect(message, SIGNAL(clicked()), message, SLOT(close()));
		QObject::connect(message, SIGNAL(clicked()), this, SLOT(close()));
		if(team==ATEAM)
			QObject::connect(message, SIGNAL(clicked()), loginwidget, SLOT(enterASuccess()));
		else if(team==BTEAM)
			QObject::connect(message, SIGNAL(clicked()), loginwidget, SLOT(enterBSuccess()));
		message->show();
	}
}