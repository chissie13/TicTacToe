#include "stdafx.h"
#include <string>
#include <list>
#include "Subject.h"
#include <iostream>

using namespace std;

Subject::Subject()
{
	board = Board();
}

void Subject::add_observer(Observer& _observer)
{
	observers.push_back(&_observer);
}

void Subject::notify()
{
	for (iterator it = observers.begin(); it != observers.end(); it++)
	{
		(*it)->update(*this);
	}
}

string * Subject::get_board()
{
	return board.get_board();
}

Board Subject::get_board_object()
{
	return board;
}

string Subject::getWinner()
{
	return board.winDetection();
}

void Subject::setPlayers(int players)
{
	board.setPlayers(players);
}

bool Subject::isWinner()
{
	return board.isWinner();
}

bool Subject::gameloop()
{
	
	printHeader();

	handleInput();
	board.switchTurn();
	system("cls");

	return !board.isWinner();
}

void Subject::printHeader()
{
	cout << string(10, '\n');
}

void Subject::handleInput()
{
	bool incorrect = true;
	string place;

	cout << endl << "Player " << board.get_turn() << " Where would you like to put your mark? " << endl;

	while (incorrect) {
		cin >> place;

		place[0] = toupper(place[0]);
		string input = place;

		incorrect = !board.inputCorrect(place);

		if (incorrect)
			cout << input << " - is not a valid location" << endl;
	}
	board.changeField(place);
}