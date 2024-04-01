#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	long long num;
	std::cin >> num;
	std::vector <long long> tui;
	for (int i = 0; i < num; i++)
	{
		long long n;
		std::cin >> n;
		tui.push_back(n);
	}
	std::sort(tui.begin(), tui.end());

	long long max = 0;
	long long	price = 0;
	long long count = num;
	for (int i = 0; i < num; i++)
	{
		if (tui[i]  * count> max)
		{
			max = tui[i] * count;
			price = tui[i];
		}
		count--;
	}
	std::cout << max << " " << price;

}
