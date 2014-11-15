#include "item2.h"

using namespace std;

item2::item2() { 
	setItemName("아이템 삭제");
	setItemDesc("상대방이 보유한 아이템 중 하나를 무작위로 삭제시킨다.");
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
