#include "item3.h"

using namespace std;

Item3::Item3() { 
	name="�ð�����";
	desc="�� �� ���� ������ ���� �ð��� ������ ���δ�.";
	ID=3;
	price=1000;
	time=1;
}

bool Item3::itemGame(Board* board, int _time) {
	if(time != _time)
		return 0;
	else {
		//To Do
	}
}
