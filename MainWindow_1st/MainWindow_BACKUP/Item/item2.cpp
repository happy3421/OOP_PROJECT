#include "item2.h"

using namespace std;

Item2::Item2() { 
	name="������ ����";
	desc="������ ������ ������ �� �ϳ��� �������� ������Ų��.";
	ID=2;
	price=1000;
	time=0;
}

bool Item2::itemGame(Board* board, int _time) {
	if(time != _time)
		return 0;
	else {
		//To Do
	}
}

