//Maybe include iostream
#include <fstream>
#include <iostream>
#include <vector>
//#define fin std::cin 
//#define fout std::cout
std::pair <int, int> center = std::make_pair(0, 0);

int solve(std::vector <std::pair <int, int>> posses)
{
	int quad1 = 0;
	int quad2 = 0;
	int quad3 = 0;
	int quad4 = 0;

	for (auto pos : posses)
	{
		if (pos.first > center.first && pos.second > center.second)
			quad1++;
		else if (pos.first > center.first && pos.second < center.second)
			quad2++;
		else if (pos.first < center.first && pos.second > center.second)
			quad3++;
		else if (pos.first < center.first && pos.second < center.second)
			quad4++;
	}
	return std::max (std::max (quad1, quad2), std::max(quad3, quad4));
}

int main()
{
	std::ifstream fin("balancing.in");
	int n, b;
	fin >> n >> b;
	std::vector <std::pair <int, int>> posses(n);

	for (int i = 0; i < n; i++)
	{
		fin >> posses[i].first >> posses[i].second;
	}

	int min = 110;
	for (auto pos : posses)
	{
		for (auto pos2 : posses)
		{
			center.first = pos.first +1;
			center.second = pos2.second + 1;
			min = std::min(min, solve(posses));
		}
	}


	std::ofstream fout("balancing.out");
	fout << min;
}

