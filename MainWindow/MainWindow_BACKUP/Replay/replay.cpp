#include "Replay.h"
#include <io.h>
using namespace std;

Replay::Replay(){
	winOne = 0;
	winTwo = 0;
	firstTurn = ATEAM;
}

string Record::getP1Win(){
	return P1Win;
}

string Record::getP2Win(){
	return P2Win;
}

int Record::getfileExist(){
	return fileExist;
}

void Record::showRecord(Player* playerOne, Player* playerTwo){
	string filename;
	filename = "Users/";
	if(playerOne->getID().compare(playerTwo->getID())<0){
		filename += playerOne->getID();
		filename += playerTwo->getID();
	}
	else{
		filename += playerTwo->getID();
		filename += playerOne->getID();
	}
	filename += ".txt";
	fileExist = access(filename.c_str(), 0);
	if(fileExist == 0){
		ifstream playing(filename);
		if(playerOne->getID().compare(playerTwo->getID())<0){
			getline(playing, P1Win);
			getline(playing, P2Win);
		}
		else{
			getline(playing, P2Win);
			getline(playing, P1Win);
		}
		P1Lose = P2Win;
		P2Lose = P1Win;
	}
}
void Replay::showReplay(Player* playerOne, Player* playerTwo){
	string filename;
	int cellStr[9][9];
	string P1Win, P1Lose, P2Win, P2Lose, firstTeam;
	if(playerOne->getID().compare(playerTwo->getID())<0){
		filename = playerOne->getID();
		filename += playerTwo->getID();
	}
	else{
		filename = playerTwo->getID();
		filename += playerOne->getID();
	}
	filename += ".txt";
	ifstream playing(filename);
	if(playerOne->getID().compare(playerTwo->getID())<0){
		getline(playing, P1Win);
		getline(playing, P2Win);
	}
	else{
		getline(playing, P2Win);
		getline(playing, P1Win);
	}
	getline(playing, firstTeam);
	if(firstTeam == "0")
		firstTurn = ATEAM;
	else
		firstTurn = BTEAM;
	while(!playing.eof()){
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				playing>>cellStr[i][j];
			}
		}
		//cell을 띄워주는 함수 제작
	}
	playing.close();
}
void Replay::saveRecord(Player* playerOne, Player* playerTwo){
	string filename;
	char removefile[100];
	string P1Win, P2Win;
	int P1Winnum, P2Winnum;
	if(playerOne->getID().compare(playerTwo->getID())<0){
		filename = playerOne->getID();
		filename += playerTwo->getID();
	}
	else{
		filename = playerTwo->getID();
		filename += playerOne->getID();
	}
	filename += ".txt";
	ifstream playing(filename);
	getline(playing, P1Win);
	getline(playing, P2Win);
	playing.close();
	string func = "erase ";
	string command;
	command = func + filename;
	system(command.c_str());
	ofstream saveCell(filename);
	saveCell << P1Win<<"\n";
	saveCell << P2Win<<"\n";
	saveCell << firstTurn<<"\n";
}/*
void Replay::saveBoard(Cell** replay_board, Player* playerOne, Player* playerTwo){
	string filename;
	char P1Win, P2Win, firstTeam;
	firstTeam = (char) firstTurn;
	if(playerOne->getID().compare(playerTwo->getID())<0){
		filename = playerOne->getID();
		filename += playerTwo->getID();
	}
	else{
		filename = playerTwo->getID();
		filename += playerOne->getID();
	}
	filename += ".txt";
	fstream saveCell;
	saveCell.open(filename, ios::app);
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			saveCell << replay_board[i][j].getCharNum()<<" ";	//cell이 본인의 말을 나타내는 숫자를 갖게
		}
		saveCell<<"\n";
	}
	saveCell.close();
}*/