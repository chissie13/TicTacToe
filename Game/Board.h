#pragma once
#include "string"

using namespace std;

class Board
{
public:
	Board();
	string * get_board();
	bool changeField(string place);
	void setPlayers(int players);
	bool isWinner();
	bool inputCorrect(string place);
	void switchTurn();
	char get_turn();
	string winDetection();
	int get_turn_int();
	bool is_tie();


private:
	char players[5] = { 'X', 'O' , 'Y', 'H', 'I' };
	int amountOfPlayers;
	string board[64];
	void fillBoard();
	int turn = 0;
};

