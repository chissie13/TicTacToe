// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "Observer.h"
#include "Subject.h"
#include "WindowObserver.h"
#include "SoundObserver.h"

using namespace std;

Subject subject;


void askAndSetPlayerCount();
bool inputCorrect(string);
int endGame();

int main()
{

	askAndSetPlayerCount();

	subject.add_observer(*new SoundObserver);
	subject.add_observer(*new WindowObserver());


	while (!subject.isWinner())
	{
		subject.notify();
		subject.gameloop();
	}

	subject.notify();

	cout << "\n\n" << "congratiolations " << subject.getWinner() << " You have vaporized your opponent" << endl;
	return endGame();
}

void askAndSetPlayerCount()
{
	int players = 0;

	cout << "How many players are playing?" << endl;

	while (players < 2 || players > 5)
	{
		cin >> players;

		if (cin.fail())
			cout << "Sorry, that's an invalid input!" << endl;
		else if (players > 5)
			cout << "Sorry, playing with more than 5 players makes no sense!" << endl;
		else if (players < 2)
			cout << "Sorry, playing with less than 2 players makes no sense!" << endl;
		else if (players < 2 || players > 5) {
			cout << "Sorry I didn't get that - please try again" << endl;
			players = 0;
		}
		cin.clear();
		cin.ignore();
	}

	subject.setPlayers(players);
	cout << "You're playing with" << players << "players" << endl;
}

int endGame() {
	system("pause");
	return 0;
}