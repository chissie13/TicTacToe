// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "list"

#include "Observer.h"
#include "Subject.h"

#include "WindowObserver.h"
#include "SoundObserver.h"

using namespace std;


Subject subject;

void changeField(string place);
void handleInput();
bool inputCorrect(string);

string * space = 0;

int main()
{
	space = subject.get_space();

	//subject.add_observer(*new SoundObserver);
	subject.add_observer(*new WindowObserver);

	subject.notify();

	while (true) {
		handleInput();
		subject.switchTurn();
	}

	system("pause");
    return 0;
}

void handleInput() {
	bool incorrect = true;
	string place;

	char turn = subject.get_turn();

	cout << endl << endl << "Player " << turn << " Where would you like to put your mark? " << endl;

	while (incorrect) {
		cin >> place;

		place[0] = toupper(place[0]);
		string input = place;

		incorrect = !inputCorrect(place);

		if (incorrect)
			cout << input << " - is not a valid location" << endl;
	}
	changeField(place);
}

void changeField(string place) {
	char turn = subject.get_turn();

	for (int i = 0; i < 64; i++)
		if (place == space[i])
			space[i] = turn;
	subject.notify();
}

bool inputCorrect(string place) {
	for (int i = 0; i < 64; i++)
		if (place == space[i])
			return true;
	return false;
}