#include "stdafx.h"
#include "Board.h"
#include "iostream"


Board::Board()																							//Constructor
{
	fillBoard();
}

void Board::fillBoard()																					//Fills the array for the board
{
	string letter[] = { "A", "B", "C", "D", "E", "F", "G", "H" };

	for (int i = 0; i < 64; i++)
	{
		int y = i / 8;
		board[i] = letter[(i / 8)] + to_string(i - (y * 8));
	}
}

bool Board::inputCorrect(string place)																	//Checks if the input is correct
{
	if (place.length() != 2)
		return false;
	for (int i = 0; i < 64; i++)
		if (place == board[i])
			return true;
	return false;
}

bool Board::changeField(string place)																	//Changes a field on the board
{
	for (int i = 0; i < 64; i++)
		if (place == board[i])
		{
			board[i] = players[turn];
			return true;
		}
	return false;
}

void Board::switchTurn()																				//Switches the turn to the next player
{
	turn += 1;
	if (turn >= amountOfPlayers)
		turn = 0;

}

string Board::winDetection()																			//Checks who has won
{
	for (int l = 0; l < 64; l += 4)
	{
		if (board[l] == board[l + 1] && board[l] == board[l + 2] && board[l] == board[l + 3])			//horizontal from front view
		{
			return board[l];
		}

		if (l == 0 || l == 16 || l == 32 || l == 48)													//crosses from front view
		{
			if ((board[l] == board[l + 5] && board[l] == board[l + 10] && board[l] == board[l + 15]) ||
				(board[l + 3] == board[l + 6] && board[l] == board[l + 9] && board[l] == board[l + 12]))
			{
				return board[l];
			}
		}
	}
	for (int j = 0; j < 64; j++)
	{
		if (board[j] == board[j + 16] && board[j] == board[j + 32] && board[j] == board[j + 48])		//depth from front view
		{
			return board[j];
		}

		if (j>-1 && j<4 || j>15 && j<20 || j>31 && j<36 || j>47 && j<52)								//vertical from front view
		{
			if( (board[j] == board[j + 4] && board[j] == board[j + 8] && board[j] == board[j + 12])||
				(board[j] == board[j + 20] && board[j] == board[j + 40] && board[j] == board[j + 60]))	//diagnal from side view
			{
				return board[j];
			}
		}

		if (j == 0 || j == 4 || j == 8 || j == 12)
		{
			if (board[j] == board[j + 17] && board[j] == board[j + 34] && board[j] == board[j + 51])	//diagnal from above view
			{
				return board[j];
			}
		}

		if (j == 3 || j == 7 || j == 11 || j == 15)
		{
			if (board[j] == board[j + 15] && board[j] == board[j + 30] && board[j] == board[j + 45])	//other diagnal from above view
			{
				return board[j];
			}
		}
		if ((board[0] == board[21] && board[0] == board[42] && board[0] == board[63]) ||				//crosses through the cube
			(board[3] == board[22] && board[3] == board[41] && board[3] == board[60]) ||
			(board[12] == board[25] && board[12] == board[38] && board[12] == board[51]) ||
			(board[15] == board[26] && board[15] == board[37] && board[15] == board[48])
			)
		{
			return board[j];
		}

		if (j == 12 || j == 13 || j == 14 || j == 15)													//other diagnal from side view
		{
			if (board[j] == board[j + 12] && board[j] == board[j + 24] && board[j] == board[j + 36])
			{
				return board[j];
			}
		}
	}
	return "";
}

void Board::setPlayers(int players)																		//Sets the amount of players
{
	amountOfPlayers = players;
}

string * Board::get_board()																				//Returns the array board
{
	return board;
}

char Board::get_turn()																					//Return which players turn it is
{
	return players[turn];
}

bool Board::isWinner()																					//Returns if theres a winner
{
	return winDetection().length() != 0;
}

int Board::get_turn_int()																				//return the turn
{
	return turn;
}