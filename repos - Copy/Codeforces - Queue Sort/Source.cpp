#include <iostream>
#include <vector>
#include <algorithm>

void solve()
{
	int num;
	std::cin >> num;
	std::vector <int> locs (num);
	for (int i = 0; i < num; i++)
		std::cin >> locs[i];
	int min = 2147483647;
	for (int i = 0; i < num; i++)
		min = std::min(min, locs[i]);
	int changes = 0;
	bool valid = true;
	for (int i = 0; i < num; i++)
	{
		if (locs[i] == min)
		{
			int prev = min;
			for (int j = i + 1; j < num; j++)
			{
				if (locs[j] < prev)
				{
					changes = -1;
					valid = false;
					break;
				}
				prev = locs[j];
			}
			if (valid)
			{
				changes = i;
			}
			break;
		}
	}
	std::cout << changes << std::endl;
}

int main()
{
	int n;
	std::cin >> n;
	while (n--)
		solve();
}