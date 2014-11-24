#include "loginwidget.h"
#include "mainwindow.h"

LoginWidget::LoginWidget(QWidget *parent)
 : QWidget(parent)
{	
	login=new Login;
	newwidget=new QWidget;
	success[0]=false;
	success[1]=false;

	QLabel *background;
	background=new QLabel(this);
	background->setPixmap(QPixmap(QString::fromUtf8("Resources/login.jpg")));
	background->setScaledContents(true);
	background->resize(800,600);

	QPushButton *exit;
	exit = new QPushButton(this); 
	exit->setStyleSheet("QPushButton:!pressed {border-image: url(Resources/exit.jpg)} QPushButton:pressed { border-image: url(Resources/exit_2.jpg)}");
	exit->setGeometry(QRect(740,10,50,50)); 
	QObject::connect(exit, SIGNAL(clicked()), this, SLOT(quit()));	

	AButton = new QPushButton(this);
	AButton->setStyleSheet("QPushButton:!pressed {border-image: url(Resources/loginA_3.jpg)} QPushButton:pressed { border-image: url(Resources/loginA_4.jpg)}");
	AButton->setGeometry(QRect(125,400,150,100));
	QObject::connect(AButton, SIGNAL(clicked()), this, SLOT(enterA()));

	BButton = new QPushButton(this); 
	BButton->setStyleSheet("QPushButton:!pressed {border-image: url(Resources/loginB_3.jpg)} QPushButton:pressed { border-image: url(Resources/loginB_4.jpg)}");
	BButton->setGeometry(QRect(325,400,150,100));
	QObject::connect(BButton, SIGNAL(clicked()), this, SLOT(enterB()));

	QPushButton *signup;
	signup = new QPushButton(this);
	signup->setStyleSheet("QPushButton:!pressed {border-image: url(Resources/signup.jpg)} QPushButton:pressed { border-image: url(Resources/signup_2.jpg)}");
	signup->setGeometry(QRect(525,400,150,100));
	
	QObject::connect(signup, SIGNAL(clicked()), this, SLOT(signUp()));

	ALine = new QLineEdit("  Go To LoginA",this);
	ALine->setGeometry(QRect(250,530,100,50));
	ALine->setReadOnly(true);
	ALine->setStyleSheet("color: white;" "background-color: black;" "selection-color: black;" "selection-background-color: black;");
	//ALine->setStyleSheet("QLineEdit { background-image: url(loginline.jpg)}");
	BLine = new QLineEdit("  Go To LoginB",this);
	BLine->setGeometry(QRect(450,530,100,50));
	BLine->setReadOnly(true);
	BLine->setStyleSheet("color: white;" "background-color: black;" "selection-color: black;" "selection-background-color: black;");
}

LoginWidget::~LoginWidget(){
	delete login;
}
void LoginWidget::quit(){
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setWidget(EXIT);
}
void LoginWidget::signUp(){
	delete newwidget;
	newwidget= new signupwidget(this,0);
}

void LoginWidget::enterA(){
	if(success[0]){
		MessageDialog* message=new MessageDialog(this);
		message->setText("already");
		message->exec();
	}
	else{
		delete newwidget;
		newwidget= new enterwidget(this, ATEAM,0);
	}
}
void LoginWidget::enterB(){
	if(success[1]){
		MessageDialog* message=new MessageDialog(this);
		message->setText("already");
		message->exec();
	}
	else{
		delete newwidget;
		newwidget= new enterwidget(this, BTEAM,0);
	}
}

void LoginWidget::enterSuccess(TEAM _team){
	int team=static_cast<int>(_team);
	success[team]=true;
	
	if(_team==ATEAM)
		ALine->setText("LoginA success");
	else if(_team==BTEAM)	
		BLine->setText("LoginB success");
	
	if(success[0] & success[1]){
		MessageDialog* message=new MessageDialog(this);
		message->setText("success!! press OK");
		message->exec();

		enterComplete();
	}
}
void LoginWidget::enterComplete(){
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->loginPlayer(this->login->getPlayer());	//로그인정보를 mainwindow에 옮김
	mainwindow->setWidget(SELECTWIDGET);
}

Login* LoginWidget::getLogin(){return login;}
///////////////////////////////////////////////////////////////////////////
signupwidget::signupwidget(LoginWidget* _loginwidget, QWidget *parent)
 : QWidget(parent)
{	
	this->setWindowModality(Qt::WindowModal);	//이거왜안되ㅡㅡ

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
	//QByteArray _id=IDLine->text().toLocal8Bit();
	//QByteArray _pwd=pwdLine->text().toLocal8Bit();
	//QByteArray _repwd=repwdLine->text().toLocal8Bit();
	//char* id=_id.data();
	//char* pwd=_pwd.data();
	//char* repwd=_repwd.data();
	string id=IDLine->text().toStdString();
	string pwd=pwdLine->text().toStdString();
	string repwd=repwdLine->text().toStdString();
	int signup = loginwidget->getLogin()->signUp(id,pwd,repwd);
	if(signup==EXISTING_ID){
		MessageDialog* message=new MessageDialog(this);	
		message->setText("existing_id");
		message->exec();			
	}
	else if(signup==NO_ID){
		MessageDialog* message=new MessageDialog(this);
		message->setText("please enter ID");
		message->exec();
	}
	else if(signup==DIFFERENT_REPWD){
		MessageDialog* message=new MessageDialog(this);
		message->setText("different repwd");
		message->exec();
	}
	else if(signup==SUCCESS_SIGNUP){
		MessageDialog* message=new MessageDialog(this);
		message->setText("success signup");
		message->exec();
		
		this->close();
	}
}
/////////////////////////////////////////////////////////////////////////////////////////

enterwidget::enterwidget(LoginWidget* _loginwidget, TEAM _team, QWidget *parent)
 : QWidget(parent)
{	
	this->setWindowModality(Qt::WindowModal);	//이거왜안되ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	
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
	string id=IDLine->text().toStdString();
	string pwd=pwdLine->text().toStdString();

	int enter = loginwidget->getLogin()->enter(id,pwd,team);
	if(enter==NOEXISTING_ID){
		MessageDialog* message=new MessageDialog(this);
		message->setText("noexisting_id");
		message->exec();
	}
	else if(enter==SAME_ID){
		MessageDialog* message=new MessageDialog(this);
		message->setText("same_id");
		message->exec();
	}
	else if(enter==DIFFERENT_PWD){
		MessageDialog* message=new MessageDialog(this);
		message->setText("diffrent_pwd");
		message->exec();
	}
	else if(enter==SUCCESS_ENTER){
		MessageDialog* message=new MessageDialog(this);
		message->setText("success enter");
		message->exec();
		
		loginwidget->enterSuccess(team);
		this->close();
	}
}