#include "item1.h"

using namespace std;

Item1::Item1() { 
	name="������";
	desc="�ڽ��� ������ �̵��� ����Ѵ�.";
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
