#include "item6.h"

using namespace std;

item6::item6() { 
	setItemName("�����ϱ�");
	setItemDesc("�������� �������� ù ������ ������ ����ڿ��� �Ѱ��ش�");
	setItemID(6);
	setItemPrice(1000);
	setItemTime(0);
}

bool item6::itemGame(Board* board, int time) {
	if(time!=getItemTime())
		return 0;
	else {
		//To Do
	}
}
