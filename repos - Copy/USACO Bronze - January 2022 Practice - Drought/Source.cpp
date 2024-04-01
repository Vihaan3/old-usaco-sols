#include <vector>
#include <iostream>
#include <algorithm>
#define int long long

signed main()
{
	int T;
	std::cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n;
		std::cin >> n;
		int count = 0;
		std::vector <int> locs;
		for (int i = 0; i < n; i++)
		{
			int x;
			std::cin >> x;
			locs.push_back(x);
		}
		int prev = 0;
		for (int i = 0; i < n; i++)
		{
			// Track the previous element.
			
			if (i == 0)
				prev = locs[i];
			if (prev < locs[i] && i != n-1)
			{
				count += 2 * (locs[i] - prev);
				locs[i + 1] -= (locs[i] - prev);
				locs[i] = prev;
				
			}
			prev = locs[i];
		}
		std::reverse(locs.begin(), locs.end());
		prev = 0;
		for (int i = 0; i < n; i++)
		{
			// Track the previous element.
			
			if (i == 0)
				prev = locs[i];
			if (prev < locs[i] && i != n-1)
			{
				locs[i + 1] -= (locs[i] - prev);
				// make this the new prev
				count += 2 * (locs[i] - prev);
				locs[i] = prev;
				
				prev = locs[i];
			}
			prev = locs[i];
		}
		prev = 0;
		for (int i = 0; i < n; i++)
		{
			
			if (i == 0)
				prev = locs[i];
			if (locs[i] < 0 || locs[i] != prev)
			{
				std::cout << -1 << std::endl;
				break;
			}
			prev = locs[i];
			if (i == n-1)
				std::cout << count << std::endl;
		}

	}
}