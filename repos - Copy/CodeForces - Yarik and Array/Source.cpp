#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
void solve()
{
	int num;
	std::cin >> num;
	std::vector <int> locs (num);
	int max = -10000000;
	for (int i = 0; i < num; i++)
	{
		std::cin >> locs[i];
		max = std::max(max, locs[i]);
	}
	for (int i = 0; i < num-1; i++)
	{
		int final = locs[i];
		int j = i + 1;
		int prev = abs(locs[i] % 2);
		while (j < num)
		{
			int a = abs(locs[j] % 2);
			if (a == prev)
				break;
			prev = a;
			final += locs[j];
			j++;
			max = std::max(max, final);
		}
		max = std::max(max, final);
	}
	std::cout << max << std::endl;
}

int main()
{
	int num;
	std::cin >> num;
	while (num--)
	{
		solve();
	}
}