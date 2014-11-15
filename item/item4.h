#ifndef ITEM4_H
#define ITEM4_H

#include "item.h"

using namespace std;

class item4:public item {
public:
	item4();
	virtual bool itemGame(Board* board, int time);
};

#endif
