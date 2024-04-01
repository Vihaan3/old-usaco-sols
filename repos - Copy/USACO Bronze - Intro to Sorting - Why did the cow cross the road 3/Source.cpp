#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int num;
	std::cin >> num;
	std::vector <std::pair <int, int>> cows;
	for (int i = 0; i < num; i++)
	{
		int p, q;
		std::cin >> p >> q;
		cows.push_back(std::make_pair(p, q));
	}
	std::sort(cows.begin(), cows.end());
	int time = 0;
	for (int i = 0; i < num; i++)
	{
		if (i == 0)
		{
			time = cows[0].first + cows[0].second;
		}
		else
		{
			if (cows[i].first > time)
			{
				time = cows[i].first;
				time += cows[i].second;
			}

			else
			{
				time += cows[i].second;
			}
		}
	}
	std::cout << time;
}
