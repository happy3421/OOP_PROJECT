#include "item1.h"

using namespace std;

Item1::Item1() { 
	name="무르기";
	desc="자신의 마지막 이동을 취소한다.";
	ID=1;
	price=1000;
	time=1;
}

bool Item1::itemGame(Board* board, int _time) {
	if(time != _time)
		return 0;
	else {
		//To Do
	}
}
