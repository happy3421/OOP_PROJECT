#include "item4.h"

using namespace std;

item4::item4() { 
	setItemName("시간두배");
	setItemDesc("한 턴 동안 자신의 제한 시간을 두 배로 늘린다.");
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
