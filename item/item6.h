#ifndef ITEM6_H
#define ITEM6_H

#include "item.h"

using namespace std;

class item6:public item {
public:
	item6();
	virtual bool itemGame(Board* board, int time);
};

#endif
