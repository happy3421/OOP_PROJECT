#include "item1.h"

using namespace std;

item1::item1() { 
	setItemName("무르기");
	setItemDesc("자신의 마지막 이동을 취소한다.");
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
