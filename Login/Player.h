#include <iostream>
using namespace std;
#ifndef Player_h
#define Player_h

enum{before,deleteitem,timehalf,timemul,goldmul,firstturn,change};

class Player
{
private:
	string ID;
	string PW;
	int Item[7];
	int Win;
	int Lose;
	int Money;
public:
	void setitem(int* item);
	void setmoney(int money);

	void setID(string id, string pw, int win, int lose);

	string getID();

	void changeWin();
	void chagelose();

	int* getitem();
	int getmoney();

	void exit();
};

#endif