#include <iostream>
#include <stdlib.h>
#include <string>

char board[3][3] = { {'1', '2', '3'}, {'4','5','6'}, {'7','8','9'} };
int row;
int column;
bool game_over = false;
bool draw = false;
char symbol = 'X';
std::string name1, name2;

void display()
{
	
	std::cout << "    |   |   \n";
	std::cout << "  " << board[0][0]<<" | " << board[0][1] << " | " << board[0][2] << " \n";
	std::cout << " ___|___|___ \n";
	std::cout << "    |   |   \n";
	std::cout << "  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " \n";
	std::cout << " ___|___|___ \n";
	std::cout << "    |   |   \n";
	std::cout << "  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " \n";
	std::cout << "    |   |   \n";

}

void update()
{
	int input;
	if (symbol == 'X')
	{
		std::cout << name1 << " enter a digit \n";
	}

	else
	{
		std::cout << name2 << " enter a digit \n";
	}
	std::cin >> input;

	switch (input)
	{
	case 1: row = 0; column = 0; break;
	case 2: row = 0; column = 1; break;
	case 3: row = 0; column = 2; break;
	case 4: row = 1; column = 0; break;
	case 5: row = 1; column = 1; break;
	case 6: row = 1; column = 2; break;
	case 7: row = 2; column = 0; break;
	case 8: row = 2; column = 1; break;
	case 9: row = 2; column = 2; break;
	default:
		std::cout << "Invalid Move\n";
	}

	if (symbol == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
	{
		board[row][column] = 'X';
	}

	else if (symbol == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
	{
		board[row][column] = 'O';
	}

	else
	{
		std::cout << "This spot has already been filled. Please enter again.";
		update();
	}

	if (symbol == 'X')
	{
		symbol = 'O';
	}
	else
	{
		symbol = 'X';
	}
	
}

bool game_check()
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
		{
			return true;
		}
	}


	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
	{
		return true;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != 'X' && board[i][j] != 'O')
			{
				return false;
			}

		}
	}
	
	draw = true;
	return true;
	
}

int main()
{
	
	std::cout << "Player 1: Enter your name:";
	std::cin >> name1;
	std::cout << "Player 2: Enter your name:";
	std::cin >> name2;

	while (game_check()==false)
	{
		display();
		update();
		game_check();
	}
	display();
	if (draw == true)
	{
		std::cout << "There was a draw!" << std::endl;
	}

	else
	{
		if (symbol == 'O')
		{
			std::cout << "Player " << name1 << " won!" << std::endl;
		}

		else
		{
			std::cout << "Player " << name2 << " won!" << std::endl;
		}
	}
}