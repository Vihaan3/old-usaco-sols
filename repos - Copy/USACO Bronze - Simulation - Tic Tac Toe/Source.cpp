#include <iostream>
#include <vector>
int individual = 0;
int team = 0;
std::vector<char> board;

void check(int i, int j, int k)
{
	i = i - 1;
	j = j - 1;
	k = k - 1;
	if (board[i] == board[j] == board[k])
	{
		individual++;
	}

	else 
	{
		if (board[i] == board[j] || board[i] == board[k] || board[j] == board[k])
		{
			team++;
		}
	}
}

int main()
{
	
	for (int i = 0; i < 9; i++)
	{
		char s;
		std::cin >> s;
		board.push_back(s);
	}
	check(1, 2, 3);
	check(4, 5, 6);
	check(7, 8, 9);
	check(1, 4, 7);
	check(2 , 5, 8);
	check(3, 6, 9);
	check(1, 5, 9);
	check(3, 5, 7);
	std::cout << individual <<std::endl;
	std::cout << team <<std::endl;

}