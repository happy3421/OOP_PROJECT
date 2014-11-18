#include "item6.h"

using namespace std;

item6::item6() { 
	setItemName("먼저하기");
	setItemDesc("랜덤으로 정해지는 첫 순서를 아이템 사용자에게 넘겨준다");
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
