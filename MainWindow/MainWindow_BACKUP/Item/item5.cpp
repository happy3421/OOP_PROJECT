#include "item5.h"

using namespace std;

Item5::Item5() { 
	name="���ι�";
	desc="������ ����� �� ȹ���ϴ� ����� ���� �� ��� �ø���";
	ID=5;
	price=1000;
	time=0;
}

bool Item5::itemGame(Board* board, int _time) {
	if(time != _time)
		return 0;
	else {
		//To Do
	}
}