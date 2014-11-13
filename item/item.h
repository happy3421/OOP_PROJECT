#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

class item {
private:
	string itemName;
	string itemDesc;
	int itemID;
	int itemPrice;
	int itemTime; //0=Before Game, 1=In Your Turn
public:
	void setItemName(string name);
	string getItemname();
	void setItemDesc(string desc);
	string getItemDesc();
	void setItemID(int ID) ;
	int getItemID();
	void setItemPrice(int price);
	int getItemPrice();
	void setItemTime(int time);
	int getItemTime();
	virtual bool itemGame(int time)=0; //Get time, run command, then return 1 if succeed
}

#endif
