#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::pair <int, int> b;
	std::pair <int, int> r;
	std::pair <int, int> l;
	std::ifstream fin("buckets.in");
	std::ofstream fout("buckets.out");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			char c;
			fin >> c;
			if (c == 'B')
			{
				b.first = i;
				b.second = j;
			}
			if (c == 'R')
			{
				r.first = i;
				r.second = j;
			}
			if (c == 'L')
			{
				l.first = i;
				l.second = j;
			}
		}
	}
	if (l.first != b.first && l.second != b.second)
		fout << std::abs(l.first - b.first) + std::abs(l.second - b.second) - 1;
	else
		if ((r.second == l.second && l.second == b.second && ((r.first > b.first && r.first < l.first) || (r.first < b.first && r.first > l.first)))  || (r.first == l.first && l.first == b.first && ((r.second > b.second && r.second < l.second) || (r.second < b.second && r.second > l.second))))
			fout << std::abs(l.first - b.first) + std::abs(l.second - b.second) + 1;
		else
			fout << std::abs(l.first - b.first) + std::abs(l.second - b.second) - 1;
}
