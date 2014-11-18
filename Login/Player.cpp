#include <fstream>
#include <iostream>
#include <string>
#include "Player.h"

void Player::setitem(int* item)
{
	 Player::Item[before]=item[0];
	 Player::Item[deleteitem]=item[1];
	 Player::Item[timehalf]=item[2];
	 Player::Item[timemul]=item[3];
	 Player::Item[goldmul]=item[4];
	 Player::Item[firstturn]=item[5];
	 Player::Item[change]=item[6];
}
void Player::setmoney(int money)
{
	Player::Money=money;
}
void Player::setID(string id, string pw,int win, int lose)
{
	 Player::ID=id;
	 Player::PW=pw;
	 Player::Win=win;
	 Player::Lose=lose;
}
string Player::getID()
{
	return ID;
}
void Player::exit()
{
	string filename=ID;
	ofstream outFile2;
	filename.append(".txt");
	outFile2.open(filename);


	outFile2 <<  Player::ID <<"\t";
	outFile2 <<  Player::PW<<"\t";
	outFile2 <<  Player::Money <<"\t";
	outFile2 <<  Player::Win <<"\t";
	outFile2 <<  Player::Lose <<"\t";
	for(int i=0; i<7; i++)
	{
		if(i<6)
			outFile2 <<  Player::Item[i] <<"\t";
		else
			outFile2 <<  Player::Item[i];
	}
};
void Player::changeWin()
{
		 Player::Win++;
};
void Player::chagelose()
{
		 Player::Lose++;
};
int* Player::getitem()
{
		return  Player::Item;
};
int Player::getmoney()
{
		return Player::Money;
};