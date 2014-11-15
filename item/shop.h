#ifndef SHOP_H
#define SHOP_H

#include "item1.h"
#include "item2.h"
#include "item3.h"
#include "item4.h"
#include "item5.h"
#include "item6.h"
#include "../Global.h"

using namespace std;

class Shop {
private:
	item1 i1;
	item2 i2;
	item3 i3;
	item4 i4;
	item5 i5;
	item6 i6;
	int qty[TOTALITEMS];
	int gold;
	item* ip(const int n);
public:
	Shop(const int* qtyi, const int goldi);
	void buyItem(const int n);
	void sellItem(const int n);
};

#endif
