#include "item1.h"

using namespace std;

item1::item1() { 
	setItemName("������");
	setItemDesc("�ڽ��� ������ �̵��� ����Ѵ�.");
	setItemID(1);
	setItemPrice(1000);
	setItemTime(1);
}

bool item1::itemGame(int time) {
	if(time!=getItemTime())
		return 0;
	else {
		//To Do
	}
}
