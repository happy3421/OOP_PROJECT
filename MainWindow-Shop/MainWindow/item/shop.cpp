#include "shop.h"

using namespace std;

Shop::Shop(Player &pi) {
	player=&pi;
}

item* Shop::ip(const int i) {
	if(i==1)
		return &i1;
	else if(i==2)
		return &i2;
	else if(i==3)
		return &i3;
	else if(i==4)
		return &i4;
	else if(i==5)
		return &i5;
	else if(i==6)
		return &i6;
	else
		return NULL;
}

void Shop::buyItem(const int i, const int n) {
	if(i<=0 || i>ITEMTYPE_NUM)
		return;
	int price=0;
	price=ip(i)->getItemPrice();
	int money=player->getMoney()-price*n;
	if(money>=0) {
		player->setMoney(money);
		player->getItem()[i]+=n;
	}
}

void Shop::sellItem(const int i, const int n) {
	int price=0;
	if(i<0 || i>ITEMTYPE_NUM)
		return;
	price=ip(i)->getItemPrice();
	int money=player->getMoney()+price*n;
	if(money>=0) {
		player->setMoney(money);
		player->getItem()[i]-=n;
	}
}

