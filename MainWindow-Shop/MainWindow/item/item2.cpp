#include "item2.h"

using namespace std;

item2::item2() { 
	setItemName("������ ����");
	setItemDesc("������ ������ ������ �� �ϳ��� �������� ������Ų��.");
	setItemID(2);
	setItemPrice(1000);
	setItemTime(0);
}

bool item2::itemGame(Board* board, int time) {
	if(time!=getItemTime())
		return 0;
	else {
		//To Do
	}
}
