#pragma once
#include <qdialog.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlayout.h>
class MessageDialog : public QDialog
{
	Q_OBJECT
public:
	MessageDialog(QWidget* parent=0);
//	MessageDialog(const QString&, QWidget* parent=0);	�̰žȵǳ�..�������ƾ���
	void setText(const QString&);
	void resize(int,int);
	//void setGeometry Ȥ�� â ��ġ�� �ٲٰ���� �� ����߰��ϸ� ��.
private:
	QPushButton *messageButton;
};

class DecisionDialog : public QDialog
{
	Q_OBJECT
public:
	DecisionDialog(QWidget* parent=0);
	void setText(const QString&);
private:
	QLabel *messageLabel;
	QPushButton *acceptButton;
	QPushButton *rejectButton;
};
////////////DecisionDialog ����
//if(decision->exec()==QDialog::Accepted){
//ok���������� �Լ�}
//else{
//cancel�����������Լ�}
////////////////////////////////////////////