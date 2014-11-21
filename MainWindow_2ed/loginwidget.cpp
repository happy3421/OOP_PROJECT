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
		MessageDialog* message=new MessageDialog(this);
		message->setText("already");
		message->exec();
	}
	else
		newwidget= new enterwidget(this, ATEAM,0);
}
void LoginWidget::enterB(){
	if(success[1]){
		MessageDialog* message=new MessageDialog(this);
		message->setText("already");
		message->exec();
	}
	else
		newwidget= new enterwidget(this, BTEAM,0);
}

void LoginWidget::enterSuccess(TEAM _team){
	int team=static_cast<int>(_team);
	success[team]=true;
	
	if(_team==ATEAM)
		ALine->setText("LoginB completed");
	else if(_team==BTEAM)	
		BLine->setText("LoginB completed");
	
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
	mainwindow->setPlayer(this->login->getPlayer());	//로그인정보를 mainwindow에 옮김
	mainwindow->setWidget(SELECTWIDGET);
}

Login* LoginWidget::getLogin(){return login;}
///////////////////////////////////////////////////////////////////////////
signupwidget::signupwidget(LoginWidget* _loginwidget, QWidget *parent)
 : QWidget(parent)
{	
	this->setWindowModality(Qt::WindowModal);	//이거왜안되ㅡㅡㅡㅡㅡㅡ
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
////////////////////////////////MessageDialog 설명부분////////////////////////////////
//		QPushButton* message=new QPushButton("existing id",0);
//		message->setWindowFlags(Qt::CustomizeWindowHint);
//		message->setGeometry(500,300,300,50);
//		QObject::connect(message, SIGNAL(clicked()), message, SLOT(close()));
//		message->show();
////////////위는 변경전. 아래는 변경후.
		MessageDialog* message=new MessageDialog(this);	//무조건 this로 넣어주셈.
		message->setText("existing_id");
	  //message->resize(300,50);		//default size로 300,50 이미 해둬서 필요없음
		message->exec();						//Existing_id 버튼을 누를때까지 여기서 멈춰있음. 다른거 다 비활성화. 버튼누르면 여기서 빠져나옴.
/////////////////////////////////////////////////////////////////////////////////////
////////////DecisionDialog 사용법
//if(decision->exec()==QDialog::Accepted){
//ok눌렀을떄의 함수}
//else{
//cancel눌렀을떄의함수}
////////////////////////////////////////////
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
	QByteArray _id=IDLine->text().toLocal8Bit();
	QByteArray _pwd=pwdLine->text().toLocal8Bit();
	char* id=_id.data();
	char* pwd=_pwd.data();
	
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