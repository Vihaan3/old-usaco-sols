#include <iostream>
#include <fstream>
#include <vector>
//#define fin std::cin 
//#define fout std::cout 

int main()
{
	std::ifstream fin("blist.in");
	std::ofstream fout("blist.out");
	int n;
	fin >> n;
	std::vector <int> pos(1005);
	std::vector <std::pair <std::pair <int, int>, int>> cows (n);
	for (int i = 0; i < n; i++)
	{
		fin >> cows[i].first.first >> cows[i].first.second >> cows[i].second;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = cows[i].first.first; j <= cows[i].first.second; j++)
		{
			pos[j] += cows[i].second;
		}
	}

	int max = 0;
	for (int i = 0; i < pos.size(); i++)
	{
		max = std::max(pos[i], max);
	}
	fout << max;
}
