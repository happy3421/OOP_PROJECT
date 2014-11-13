#include "Login.h"
#include <fstream>
#include <iostream>
#include <string>
#include <io.h>

using namespace std;

#define OK 1;

void Login::signup()
{
	string item[7];
	string id;
	string pwd;
	string repwd;
	string money="2000";
	string win="0";
	string lose="0";

	for(int i=0; i<7; i++)
		item[i]="0";

	ofstream outFile;
	outFile.open("information.txt",std::ios_base::out | std::ios_base::app);

	while(1)
	{
		cout<<"Sign up your ID\n";
		cin>>id;

		cout<<"Sign up your Password\n";
		cin>>pwd;

		cout<<"Retype your Password\n";
		cin>>repwd;

		if(pwd.compare(repwd)==0)
			break;
	}

	outFile << id <<"\t";
	outFile << pwd <<"\t";

	string filename=id;
	ofstream outFile2;
	filename.append(".txt");
	outFile2.open(filename);

	outFile2 << id <<"\t";
	outFile2 << pwd <<"\t";
	outFile2 << money <<"\t";
	outFile2 << win <<"\t";
	outFile2 <<lose <<"\t";
	for(int i=0; i<7; i++)
	{
		if(i<6)
			outFile2 << item[i] <<"\t";
		else
			outFile2 << item[i];
	}

};
void Login::login(Player* player)
{
	int item[7];
	string id;
	string myid;
	string pwd;
	string mypwd;
	int money;
	int win;
	int lose;

	cout<<"Type your ID\n";
	cin>>myid;
	cout<<"Type your Password\n";
	cin>>mypwd;

	ifstream inFile;
	inFile.open("information.txt");

	while(!inFile.eof())
	{
		getline(inFile,id,'\t');
		getline(inFile,pwd,'\t');

		if(myid.compare(id)==0)
		{
			if(mypwd.compare(pwd)==0)
			{
				string filename=id;
				filename.append(".txt");
				ifstream inFile2;
				inFile2.open(filename);
				getline(inFile2,id,'\t');
				getline(inFile2,pwd,'\t');
				inFile2 >> money;
				inFile2 >> win;
				inFile2 >> lose;
				for(int i=0; i<7; i++)
					inFile2 >> item[i];

				cout<<id<<" "<<pwd<<" "<<money<<" "<<win<<" "<<lose<<" ";
				for(int i=0; i<7; i++)
					cout<< item[i]<<" ";
				cout<<"\n";
				player->setID(id,pwd,win,lose);
				player->setitem(item);
				player->setmoney(money);
			}
		}
	}
};

