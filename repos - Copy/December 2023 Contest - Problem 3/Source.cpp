#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

void solve()
{
	int n;
	std::cin >> n;
	std::vector <std::pair <int, std::pair <int, int>>> inp(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> inp[i].second.first;
	}
	for (int i = 0; i < n; i++)
	{
		std::cin >> inp[i].second.second;
	}
	for (int i = 0; i < n; i++)
	{
		std::cin >> inp[i].first;
	}
	std::sort(inp.begin(), inp.end());
	std::vector <std::pair <int, int>> locs (n);
	for (int i = 0; i < n; i++)
	{
		locs[i].first = inp[i].second.first;
		locs[i].second = inp[i].second.second;
	}
	bool valid = true;
	bool valid2 = true;
	int max = 0;
	for (int k = 0; k < n-1; k++)
	{
		int i = locs[k].first;
		int j = locs[k].second;
		int i2 = locs[k + 1].first;
		int j2 = locs[k + 1].second;

		if (j == j2)
		{
			if (i > i2)
			{
			}
			else
			{
				valid = false;
				break;
			}
		}
		else
		{
			int change = (i - i2)/(j2-j);
			max = std::max(max, change);
			if (change < 0 && j < j2)
			{
				valid = false;
				break;
			}
		}
	}

	for (int k = 0; k < n - 1; k++)
	{
		int i = locs[k].first;
		int j = locs[k].second;
		int i2 = locs[k + 1].first;
		int j2 = locs[k + 1].second;
		
		if (i2 >= i)
		{
			valid2 = false;
			break;
		}
	}

	if (valid2)
	{
		std::cout << 0 << std::endl;
	}
	else if (!valid)
		std::cout << -1 << std::endl;
	else if (n > 1)
		std::cout << max + 1 << std::endl;
	else if (n == 1)
		std::cout << max << std::endl;
}

signed main()
{
	int n;
	std::cin >> n;
	while (n--)
		solve();
}
