#include <fstream>
#include <iostream>
#include <string>
#include "Player.h"
Player::Player(){
	id="";
	pwd="";
	win=0;
	lose=0;
	money=0;
	
	item=new int[ITEMTYPE_NUM];
	for(int i=0;i<ITEMTYPE_NUM;i++)
		item[i]=0;
}
Player::~Player(){
	delete[] item;
}

void Player::setPlayer(string _id, string _pwd,int _win, int _lose, int _money, int* _item)
{
	 id=_id;
	 pwd=_pwd;
	 win=_win;
	 lose=_lose;
	 money=_money;
	 setItem(_item);
}
Player& Player::operator=(Player& player){
	this->setPlayer(player.id, player.pwd, player.win, player.lose, player.money, player.item);
	return *this;
}
void Player::setItem(int* _item){	
	for(int i=0;i<ITEMTYPE_NUM;i++)
		item[i]=_item[i];
}
void Player::setMoney(int _money){money=_money;}
void Player::incWin(){win++;}
void Player::incLose(){lose++;}

string Player::getID(){return id;}
int* Player::getItem(){return item;}
int Player::getMoney(){return money;}

void Player::save()
{
	string filename="Users/";
	filename.append(id);
	filename.append(".txt");
	
	ofstream userfile(filename);
	userfile << id <<endl;
	userfile << pwd <<endl;
	userfile << win <<endl;
	userfile << lose<<endl;
	userfile << money <<endl;
	for(int i=0; i<ITEMTYPE_NUM; i++)
		userfile << item[i] <<endl;
	
	userfile.close();
}