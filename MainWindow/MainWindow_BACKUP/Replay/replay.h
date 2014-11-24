#include <cstdlib>
#include <fstream>
#include <string>
#include "player.h"

class Record{
private:
	Player* record_playerone;
	Player* record_playertwo;
	string P1Win;;
	string P1Lose;
	string P2Win;
	string P2Lose;
	int fileExist;
public:
	void showRecord(Player*, Player*);
	string getP1Win();
	string getP2Win();
	int getfileExist();
};

class Replay: public Record{
private:	
	int winOne;
	int winTwo;
	TEAM ongoingTeam;
	TEAM firstTurn;
public:
	Replay();
	void showReplay(Player*, Player*);
//	void saveBoard(Cell**, Player*, Player*);
	void saveRecord(Player*, Player*);
};