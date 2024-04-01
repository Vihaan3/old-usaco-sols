#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int num;
	std::vector <std::vector <int>> board (num, std::vector <int> (num));
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			char s;
			std::cin >> s;
			if (s == '.')
			{
				board[i][j] == 0;
			}
			else
			{
				board[i][j] == 1;
			}
		}
	}
	std::vector <int> queens = {0, 1, 2, 3, 4, 5, 6, 7};
	int count = 0;
	do
	{
		bool valid = true;
		for (int i = 0; i < 8; i++)
		{
			if (board[i][queens[i]] == 1)
			{
				valid = false;
				break;
			}
			// FIGURE OUT DIAGONALS

		}
		// IDK HOW CONTINUE WORKS FOR WHILE LOOPS 
		if (!valid)
			continue;

	} while (std::next_permutation(queens.begin(), queens.end()));

	std::cout << count;
}