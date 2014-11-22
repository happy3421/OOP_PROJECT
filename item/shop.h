#ifndef SHOP_H
#define SHOP_H

#include "item1.h"
#include "item2.h"
#include "item3.h"
#include "item4.h"
#include "item5.h"
#include "item6.h"
#include "../global.h"
#include "../player.h"

using namespace std;

class Shop {
private:
	item1 i1;
	item2 i2;
	item3 i3;
	item4 i4;
	item5 i5;
	item6 i6;
	Player *player;
	item* ip(const int i);
public:
	Shop(Player &pi);
	void buyItem(const int i, const int n);
	void sellItem(const int i, const int n);
};

#endif
