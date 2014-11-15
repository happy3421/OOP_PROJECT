#include "shop.h"

using namespace std;

Shop::Shop(const int* qtyi, const int goldi) {
	for(int i=0; i<TOTALITEMS; i++) 
		qty[i]=qtyi[i];
	gold=goldi;
}

void Shop::buyItem(int n) {
	int price=0;
	if(n==1)
		price=i1.getItemPrice();
	gold=gold-price;
	qty[n]++;
}
void Shop::sellItem(int n) {
	int price=0;
	if(n==1)
		price=i1.getItemPrice();
	gold=gold+price;
	qty[n]--;
}