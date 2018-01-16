#include "stdafx.h"
#include "WindowObserver.h"
#include "iostream"
#include "Subject.h"


using namespace std;

void WindowObserver::update(Subject &s)
{
	system("cls");

	print(s);
}

WindowObserver::WindowObserver()
{
	setupConsole();
}

void WindowObserver::setupConsole()
{

}

WindowObserver::~WindowObserver()
{

}

void WindowObserver::print(Subject &s)
{
	string * board = s.get_board();

	int k, l, p;

	for (int o = 0; o < 4; o++)
	{
		p = o * 4;
		for (int j = 0; j < 4; j++)
		{
			k = j * 16;
			for (int i = 0; i < 4; i++)
			{
				int kip = k + i + p;
				string line = board[kip];
				if (line.size() == 1)
					line += " ";

				if (i == 0) {
					string xyz = "   " + line + " ";
					//console.printf(xyz.c_str());
					cout << xyz.c_str();
				}
				else {
					string xyz = "|  " + line + " ";
					//console.printf(xyz.c_str());
					cout << xyz.c_str();
				}

			}
		}
		if (o != 3)
			//console.printf("\n  ______________________   _____________________   _____________________   _____________________\n");
			cout << "\n  ______________________   _____________________   _____________________   _____________________\n";
	}
	//console.printf("\n");
	cout << "\n";
}