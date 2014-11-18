#ifndef ITEM2_H
#define ITEM2_H

#include "item.h"

using namespace std;

class item2:public item {
public:
	item2();
	virtual bool itemGame(Board* board, int time);
};

#endif
