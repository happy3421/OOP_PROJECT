#include "item4.h"

using namespace std;

Item4::Item4() { 
	name="�ð��ι�";
	desc="�� �� ���� �ڽ��� ���� �ð��� �� ��� �ø���.";
	ID=4;
	price=1000;
	time=1;
}

bool Item4::itemGame(Board* board, int _time) {
	if(time != _time)
		return 0;
	else {
		//To Do
	}
}