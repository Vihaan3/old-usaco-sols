#include <iostream>
#include <vector>
#define int long long

/*
	Take in input of the candy canes as a vector of pairs with the first value
	being the starting value and the second value being the ending value. 
	Take in input of the cows
	For each candy cane
		For each cow
			if the cow is greater than or equal to candy[i].first 
				if cow is > .second, add to cow and candy[i].first the different of the cow and the first
			else
				add the second - first to it and break out of the loop
	print out the heights of each on a new line
*/

signed main()
{
	int n, c;
	std::cin >> n >> c;
	std::vector <int> cows;
	std::vector <std::pair<int, int>> candy (c);
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		int q;
		std::cin >> q;
		if (q > max)
			cows.push_back(q);
	}
	for (int i = 0; i < c; i++)
	{
		std::cin >> candy[i].second;
		candy[i].first = 0;
	}
	/*For each candy cane
		For each cow
		if the cow is greater than or equal to candy[i].first
			if cow is > .second, add to cowand candy[i].first the different of the cowand the first
			else
				add the second - first to it and break out of the loop
				print out the heights of each on a new line
	*/
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < cows.size(); j++)
		{
			if (cows[j] > candy[i].first)
			{
				if (cows[j] < candy[i].second)
				{
					int diff = cows[j] - candy[i].first;
					cows[j] += diff;
					candy[i].first += diff;
				}
				else
				{
					cows[j] += candy[i].second - candy[i].first;
					break;
				}
			}
		}
	}
	for (int i = 0; i < cows.size(); i++)
	{
		std::cout << cows[i] << std::endl;
	}
}