#include "item3.h"

using namespace std;

item3::item3() { 
	setItemName("�ð�����");
	setItemDesc("�� �� ���� ������ ���� �ð��� ������ ���δ�.");
	setItemID(3);
	setItemPrice(1000);
	setItemTime(1);
}

bool item3::itemGame(Board* board, int time) {
	if(time!=getItemTime())
		return 0;
	else {
		//To Do
	}
}
