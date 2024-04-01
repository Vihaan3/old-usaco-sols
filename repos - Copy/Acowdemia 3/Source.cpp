#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define string std::string

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::vector <std::vector <char>> locs(n, std::vector <char>(m));
	std::vector <std::pair <int, int>> grass;
	int num_count = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cin >> locs[i][j];
			if (locs[i][j] == 'G')
			{
				std::pair <int, int> x;
				x.first = i;
				x.second = j;
				grass.push_back(x);
			}
		}
	}
	std::set <std::pair<std::pair<int, int>, std::pair <int, int>>> friends;
	count = 0;
	for (int i = 0; i < grass.size(); i++)
	{
		int number = 0;
		std::vector <std::pair<int, int>> f;
		if (grass[i].first != 0 && locs[grass[i].first - 1][grass[i].second] == 'C')
		{
			number++;
			std::pair <int, int> x;
			x.first = grass[i].first - 1;
			x.second = grass[i].second;
			f.push_back(x);
		}
		if (grass[i].first + 1 < n && locs[grass[i].first + 1][grass[i].second] == 'C')
		{
			number++;
			std::pair <int, int> x;
			x.first = grass[i].first + 1;
			x.second = grass[i].second;
			f.push_back(x);
		}
		if (grass[i].second != 0 && locs[grass[i].first][grass[i].second - 1] == 'C')
		{
			number++;
			std::pair <int, int> x;
			x.first = grass[i].first;
			x.second = grass[i].second - 1;
			f.push_back(x);
		}
		if (grass[i].second + 1 < m && locs[grass[i].first][grass[i].second + 1] == 'C')
		{
			number++;
			std::pair <int, int> x;
			x.first = grass[i].first;
			x.second = grass[i].second + 1;
			f.push_back(x);
		}
		if (number > 2)
		{
			num_count++;
		}
		else if (number == 2)
		{
			std::sort(f.begin(), f.end());
			friends.insert(std::make_pair(f[0], f[1]));
			
		}
	}
	std::cout << num_count + friends.size();

}