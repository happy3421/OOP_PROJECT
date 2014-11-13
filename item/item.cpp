#include "item.h"
using namespace std;

void item::setItemName(string name) { itemName=name; }
string item::getItemname() { return itemName; }
void item::setItemDesc(string desc) { itemDesc=desc; }
string item::getItemDesc() { return itemDesc; }
void item::setItemID(int ID) { itemID=ID; }
int item::getItemID() { return itemID; }
void item::setItemPrice(int price) { itemPrice=price; }
int item::getItemPrice() { return itemPrice; }
void item::setItemTime(int time) { itemTime=time; }
int item::getItemTime() { return itemTime; }