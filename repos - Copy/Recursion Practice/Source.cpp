#include <iostream>
#include <vector>

std::vector<int> flip(std::vector<int> coins, int n, int count)
{
	if (count > n)
		return coins;

	else
		for (int i = 0; i < count; i++)
		{
			if (coins[i] == 0)  
				coins[i] = 1;
			else
				coins[1] = 0;
		}

		return flip(coins, n, count++);
}

int main()
{
	std::vector<int> coins = {1,1,1,1,1};
	int n = coins.size();
	coins = flip(coins, n, 1);
	for (int i = 0; i < coins.size(); i++)
		std::cout << coins[1] << ",";
}