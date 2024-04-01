#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

signed main()
{
	int n;
	std::cin >> n;
	std::vector <int> cows(n);
	std::vector <int> stalls(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> cows[i];
	}
	for (int i = 0; i < n; i++)
	{
		std::cin >> stalls[i];
	}
	
	std::sort(cows.begin(), cows.end());
	std::sort(stalls.begin(), stalls.end());
	std::vector <int> num(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (cows[j] <= stalls[i])
			{
				num[j]++;
			}
		}
	}
	int score = 1;
	for (int i = 0; i < n; i++)
	{
		score *= num[i] - (n - i - 1);
	}
	std::cout << score;
}