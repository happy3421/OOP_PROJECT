#include "shop.h"

using namespace std;

Shop::Shop(const int* qtyi, const int goldi) {
	for(int i=0; i<TOTALITEMS; i++) 
		qty[i]=qtyi[i];
	gold=goldi;
}

item* Shop::ip(const int n) {
	if(n==1)
		return &i1;
	else if(n==2)
		return &i2;
	else if(n==3)
		return &i3;
	else if(n==4)
		return &i4;
	else if(n==5)
		return &i5;
	else if(n==6)
		return &i6;
	else
		return NULL;
}

void Shop::buyItem(int n) {
	int price=0;
	price=ip(n)->getItemPrice();
	gold=gold-price;
	qty[n]++;
}

void Shop::sellItem(int n) {
	int price=0;
	ip(n)->getItemPrice();
	gold=gold+price;
	qty[n]--;
}

