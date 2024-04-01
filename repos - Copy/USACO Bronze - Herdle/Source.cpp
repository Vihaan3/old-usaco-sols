#include <iostream>
#include <vector>

int main()
{
	std::vector <std::vector <std::pair<int, int>>> answer(26);
	std::vector <std::vector <std::pair<int, int>>> guess(26);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			char c;
			std::cin >> c;
			answer[c - 'A'].push_back(std::make_pair(i, j));
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			char c;
			std::cin >> c;
			guess[c - 'A'].push_back(std::make_pair(i, j));
		}
	}
	int green = 0;
	int yellow = 0;
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < guess[i].size(); j++)
		{
			for (int k = 0; k < answer[i].size(); k++)
			{
				if (guess[i][j] == answer[i][k])
				{
					green++;
					guess[i].erase(guess[i].begin() + j);
					answer[i].erase(answer[i].begin() + k);
					j--;
					k--;
				}
			}
		}
		yellow += std::min(answer[i].size(), guess[i].size());
	}
	std::cout << green << std::endl << yellow;
}