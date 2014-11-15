#include "item5.h"

using namespace std;

item5::item5() { 
	setItemName("골드두배");
	setItemDesc("게임이 종료될 때 획득하는 골드의 양을 두 배로 늘린다.");
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
