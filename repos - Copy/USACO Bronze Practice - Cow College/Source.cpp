#include <iostream>
#include <vector>
#include <algorithm>

#define int long long
signed main()
{
	int n;
	std::cin >> n;
	std::vector <int> locs(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> locs[i];
	}
	std::sort(locs.begin(), locs.end());
	int cost = 0;
	int tuition = 0;
	for (int i = 0; i < n; i++)
	{
		if (locs[i] * (n - i) > tuition)
		{
			cost = locs[i];
			tuition = locs[i] * (n - i);
		}
	}
	std::cout << tuition << " " << cost;
}