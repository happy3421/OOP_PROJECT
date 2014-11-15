#include "item3.h"

using namespace std;

item3::item3() { 
	setItemName("시간절반");
	setItemDesc("한 턴 동안 상대방의 제한 시간을 반으로 줄인다.");
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
