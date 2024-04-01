#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <fstream>
#define set std::unordered_set
//#define fin std::cin 
//#define fout std::cout

int main()
{
	// LOGICAL ISSUES MIGHT BE THE ISSUE
	set<int> pos_set;
	int n;
	std::ifstream fin("art.in");
	std::ofstream fout("art.out");
	fin >> n;
	std::vector <std::vector <int>> grid(n, std::vector <int>(n));
	for (int i = 0; i < n; i++)
	{
		std::string s;
		fin >> s;
		for (int j = 0; j < n; j++)
		{

			grid[i][j] = s[j] - '0';
			if (grid[i][j] != 0)
				pos_set.insert(grid[i][j]);
		}
	}
	
	std::vector <int> available(pos_set.size());
	std::copy(pos_set.begin(), pos_set.end(), available.begin());
	std::vector<int> left (available.size());
	std::vector<int> right(available.size());
	std::vector<int> up(available.size());
	std::vector<int> down(available.size());

	for (int k = 0; k < available.size(); k++)
	{
		bool first = true;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == available[k])
				{
					if (first)
					{
						left[k] = j;
						right[k] = j;
						up[k] = i;
						down[k] = i;
						first = false;
					}
					else
					{
						// THIS COULD BE THE ISSUE, accidental mistakes
						left[k] = std::min(left[k], j);
						right[k] = std::max(right[k], j);
						up[k] = std::min(up[k], i);
						down[k] = std::max(down[k], i);
					}
				}
			}
		}
	}
	set<int> second;

	for (int k = 0; k < available.size(); k++)
	{
		// MIGHT HAVE TO SWITCH THESE TWO LOOPS
		for (int i = up[k]; i <= down[k]; i++)
		{
			for (int j = left[k]; j <= right[k]; j++)
			{
				if (grid[i][j] != available[k])
				{
					second.insert(grid[i][j]);
				}
			}
		}
	}
	fout << available.size() - second.size();
}