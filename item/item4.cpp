#include "item4.h"

using namespace std;

item4::item4() { 
	setItemName("�ð��ι�");
	setItemDesc("�� �� ���� �ڽ��� ���� �ð��� �� ��� �ø���.");
	setItemID(4);
	setItemPrice(1000);
	setItemTime(1);
}

bool item4::itemGame(Board* board, int time) {
	if(time!=getItemTime())
		return 0;
	else {
		//To Do
	}
}
