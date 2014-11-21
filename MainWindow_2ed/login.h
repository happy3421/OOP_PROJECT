#include <global.h>
#include <iostream>
#include <fstream>
#include "Player.h"

#ifndef Login_h
#define Login_h

using namespace LOGIN;
class Login
{
public:
	Login();
	~Login();
	 SIGNUP signUp(char*, char*, char*);
	ENTER enter(char*, char*, TEAM);
	Player* getPlayer();
private:
	Player *player;
};

#endif
