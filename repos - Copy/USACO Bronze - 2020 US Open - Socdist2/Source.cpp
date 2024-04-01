#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	std::ifstream fin("socdist2.in");
	std::ofstream fout("socdist2.out");
	fin >> n;
	std::vector <std::pair<int, int>> cows (n);
	for (int i = 0; i < n; i++)
	{
		fin >> cows[i].first >> cows[i].second;
	}
	std::sort(cows.begin(), cows.end());
	std::vector <int> sick;
	int min = 10000000;
	for (int i = 0; i < n; i++)
	{
		if (cows[i].second == 0 && i > 0 && cows[i-1].second == 1)
		{
			min = std::min(min, (cows[i].first - cows[i-1].first));
		}
		else if (cows[i].second == 1 && i > 0 && cows[i-1].second == 0)
		{
			min = std::min(min, (cows[i].first - cows[i - 1].first));
		}

		if (cows[i].second == 1)
		{
			sick.push_back(cows[i].first);
		}
	}
	int r = min - 1;
	int ans = 1;
	for (int i = 0; i < sick.size()-1; i++)
	{
		if (sick[i + 1] - sick[i] > r)
			ans++;
	}
	fout << ans;
}