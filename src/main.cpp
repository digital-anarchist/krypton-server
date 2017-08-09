#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

string com;
string sendto;
char message[255];
char messagestr;
string current;
string sender;
string uname;
string previous;

int main(){
	cin >> com;
	if (com == "send")
	{
		cin >> sendto;
		cin.clear();
		cin.ignore();
		cin.get(message, 255);
		ofstream broadcast;
		broadcast.open(sendto);
		broadcast << message << endl;
		broadcast.close();
		ofstream prev;
		prev.open(sendto + "prev");
		prev << 1 << endl;
		prev.close();
		return 0;
	}
	else if (com == "listen")
	{
			cin >> uname;
			ifstream msgread;
			msgread.open(uname);
			msgread >> messagestr;
			cout << messagestr;
			while(msgread.get (messagestr) ){
				cout << messagestr;
			}
			msgread.close();
			ofstream prev;
			prev.open(uname + "prev");
			prev << "0" << endl;
			prev.close();
		
	}
	else if (com == "ismessage")
	{
		cin >> uname;
		ifstream isprev;
		isprev.open(uname + "prev");
		isprev >> previous;
		isprev.close();
		ifstream curmsg;
		curmsg.open(uname);
		curmsg >> current;
		curmsg.close();
		if (previous == "0")
		{
			cout << "0" << endl;
		}
		else
		{
			cout << "1" << endl;
			previous = (current);
		}
	}
}
