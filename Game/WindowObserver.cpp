#include "stdafx.h"
#include "WindowObserver.h"
#include "iostream"
#include "Subject.h"
#include "ConsoleLogger.h"


using namespace std;

void WindowObserver::update(Subject &s)
{
	//cout << "WindowObserver update! " << endl;
	print(s);
}

WindowObserver::WindowObserver()
{
	console.Create("WindowObserver");
	console.printf("WindowObserver is waiting for data! \n");
}

WindowObserver::WindowObserver(enum CConsoleLoggerEx::enumColors col)
{
	console.Create("WindowObserver");
	console.printf("WindowObserver is waiting for data! \n");
	color = col;
}

void WindowObserver::print(Subject &s)
{
	if (color != NULL)
		console.cls(color);
	else
		console.cls();
	
	string * board = 0;
	board = s.get_board();

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
					console.printf(xyz.c_str());
					//cout << "   " << line << " ";
				}
				else {
					string xyz = "|  " + line + " ";
					console.printf(xyz.c_str());
					//cout << "|  " << line << " ";
				}

			}
		}
		if (o != 3)
			console.printf("\n  ______________________   _____________________   _____________________   _____________________\n");
			//cout << "\n" << "  ______________________   _____________________   _____________________   _____________________" << "\n";
	}
	console.printf("\n");
}