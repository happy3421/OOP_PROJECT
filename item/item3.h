#ifndef ITEM3_H
#define ITEM3_H

#include "item.h"

using namespace std;

class item3:public item {
public:
	item3();
	virtual bool itemGame(Board* board, int time);
};

#endif
