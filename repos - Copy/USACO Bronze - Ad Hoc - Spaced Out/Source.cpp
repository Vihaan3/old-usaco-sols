#include <iostream>
#include <vector>

int main(void)
{
	int n;
	std::cin >> n;
	std::vector <std::vector<int>> unp;
	std::vector <std::vector <int>> beauty(n);
	for (int i = 0; i < n; i++)
	{
		std::vector <int> x;
		for (int j = 0; j < n; j++)
		{
			int k;
			std::cin >> k;
			x.push_back(k);
		}
		unp.push_back(x);
	}
	// could be problems with this
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			beauty[i].push_back(unp[j][i]);
		}
	}
	int aest = 0;
	for (int i = 0; i < n; i++)
	{
		int max = 0;
		int zero_count = 0;
		int one_count = 0;
		for (int j = 0; j < n; j += 2)
		{
			zero_count += beauty[i][j];
		}
		for (int j = 1; j < n; j += 2)
		{
			one_count += beauty[i][j];
		}
		max = std::max(zero_count, one_count);
		aest += max;
	}
	std::cout << aest;
}