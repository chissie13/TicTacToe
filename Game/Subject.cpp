#include "stdafx.h"
#include <string>
#include <list>
#include "Subject.h"
#include <iostream>

using namespace std;

Subject::Subject()																						//Constructor, makes a board
{
	board = Board();
}

void Subject::add_observer(Observer& _observer)															//Adds a observer to the stack
{
	observers.push_back(&_observer);
}

void Subject::notify()																					//Notifies the observers
{
	for (iterator it = observers.begin(); it != observers.end(); it++)
	{
		(*it)->update();
	}
}

string *Subject::get_board()																			//Returns the board
{
	return board.get_board();
}

Board Subject::get_board_object()																		//Returns the board
{
	return board;
}

string Subject::getWinner()																				//Returns which char the winner has
{
	return board.winDetection();
}

void Subject::setPlayers(int players)																	//Sets the amount of playeres
{
	board.setPlayers(players);
}

bool Subject::isWinner()																				//Getter if theres a winner
{
	return board.isWinner();
}

bool Subject::gameloop()																				//Goes through one turn
{

	handleInput();
	board.switchTurn();
	system("cls");

	return !board.isWinner();
}

void Subject::handleInput()																				//Handle the input
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