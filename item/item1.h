#ifndef ITEM1_H
#define ITEM1_H

#include "item.h"

using namespace std;

class item1:public item {
public:
	item1();
	virtual bool itemGame(int time);
};

#endif
