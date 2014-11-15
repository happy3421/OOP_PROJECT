#ifndef SHOP_H
#define SHOP_H

#include "item1.h"

using namespace std;

class Shop {
private:
	item1 i1;
	int qty[TOTALITEMS];
	int gold;
public:
	Shop(const int* qtyi, const int goldi);
	void buyItem(const int n);
	void sellItem(const int n);
};

#endif
