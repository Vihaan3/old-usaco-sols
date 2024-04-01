#include <iostream>
#include <vector>
#define int long long
signed main()
{
	int n, t;
	std::cin >> n >> t;
	int eaten = 0;
	int remaining;
	int last_delivery;
	std::cin >> last_delivery >> remaining;
	for (int i = 1; i < n; i++)
	{
		int day, num;
		std::cin >> day >> num;
		eaten += std::min(remaining, day - last_delivery);
		remaining -= std::min (remaining, day - last_delivery);
		last_delivery = day;
		remaining += num;
	}
	eaten += std::min(remaining, t + 1 - last_delivery);
	std::cout << eaten;
}