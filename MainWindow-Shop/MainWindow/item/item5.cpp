#include "item5.h"

using namespace std;

item5::item5() { 
	setItemName("���ι�");
	setItemDesc("������ ����� �� ȹ���ϴ� ����� ���� �� ��� �ø���.");
	setItemID(5);
	setItemPrice(1000);
	setItemTime(0);
}

bool item5::itemGame(Board* board, int time) {
	if(time!=getItemTime())
		return 0;
	else {
		//To Do
	}
}
