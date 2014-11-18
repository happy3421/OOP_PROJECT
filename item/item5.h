#ifndef ITEM5_H
#define ITEM5_H

#include "item.h"

using namespace std;

class item5:public item {
public:
	item5();
	virtual bool itemGame(Board* board, int time);
};

#endif
