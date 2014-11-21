#include "Login.h"
#include <fstream>
#include <iostream>
#include <string>
#include <io.h>
using namespace std;
//SAME_ID오류!!!!!!!!!!!!!!!!!!!!!!!!1
Login::Login(){
	player= new Player[2];
}
Login::~Login(){
	delete player;
}
SIGNUP Login::signUp(char* id, char* pwd, char* repwd)
{
	int win=0;
	int lose=0;
	int money=2000;
	int item[7]={0};
	
	string filename="Users/";
	filename.append(id);
	filename.append(".txt");
	
	if( access(filename.c_str(),0)==0 )
		return EXISTING_ID;
	else if(*pwd != *repwd)
		return DIFFERENT_REPWD;
	else{
		ofstream userfile(filename);
		
		userfile << id <<endl;
		userfile << pwd <<endl;
		userfile << win <<endl;
		userfile << lose<<endl;
		userfile << money <<endl;
		for(int i=0; i<7; i++)
			userfile << item[i] <<endl;
		
		userfile.close();
		return SUCCESS_SIGNUP;
	}
}
ENTER Login::enter(char* _id, char* _pwd, TEAM _team)
{
	char* id;
	char* pwd;
	int money;
	int win;
	int lose;
	int item[7];
	int team=static_cast<int>(_team);

	string filename="Users/";
	filename.append(_id);
	filename.append(".txt");

	ifstream userfile(filename);
	if(!userfile)
		return NOEXISTING_ID;
//	else if(*_id=="")
//		return NO_ID;
//	else if(*(player[(1-team)].getID())==*_id)
//		return SAME_ID;
	else{
		id=new char[10];	//10글자이하
		pwd=new char[10];	//10글자이하
		userfile>>id>>pwd>>win>>lose>>money;
		
		if(*pwd != *_pwd)
			return DIFFERENT_PWD;
		else{
			for(int i=0; i<7; i++)
				userfile>>item[i];
			player[team].setPlayer(id,pwd,win,lose,money,item);
			return SUCCESS_ENTER;
		}
		delete id;
		delete pwd;
	}
}

Player* Login::getPlayer(){
	return player;
}