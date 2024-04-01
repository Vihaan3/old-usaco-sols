#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n, l;
	std::cin >> n >> l;
	std::vector <int> num(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> num[i];
	}
	std::sort(num.begin(), num.end());
	int max = 0;
	int pos = 0;
	for (int i = 0; i < n; i++)
	{
		if (n - i >= num[i])
		{
			int prev = max;
			max = std::max(max, num[i]);
			if (prev != max)
			{
				pos = i;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (num[i] == max)
		{
			if (l == 0)
				break;
			l--;
			num[i]++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (num[i] == max + 1 && n - i >= num[i])
		{
			max++;
		}
	}
	std::cout << max;
}