#include <iostream>
#include "global.h"
using namespace std;
#ifndef Player_h
#define Player_h

//enum{before,deleteitem,timehalf,timemul,goldmul,firstturn,change};

class Player
{
private:
	char* id;
	char* pwd;
	int win;
	int lose;
	int money;
	int* item;
public:
	Player();
	~Player();
	void setPlayer(char*,char*,int,int,int,int*);
	void setItem(int*);
	void setMoney(int);
	void incWin();
	void incLose();

	char* getID();
	int* getItem();
	int getMoney();

	void exit();
};

#endif