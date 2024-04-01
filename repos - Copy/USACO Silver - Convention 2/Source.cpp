#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
//#define fin std::cin 
//#define fout std::cout 

int main()
{
	std::ifstream fin ("convention2.in");
	int n;
	fin >> n;
	std::vector <std::pair<std::pair<int, int>, int>> store (n);
	for (int i = 0; i < n; i++)
	{
		fin >> store[i].first.first >> store[i].first.second;
		store[i].second = i;
	}

	std::sort(store.begin(), store.end());
	std::vector <std::pair<std::pair<int, int>, int>> que;
	int max = 0;
	int current = 0;
	que.push_back(store[0]);
	store.erase(store.begin());
	while (true)
	{
		if (store.size() == 0 && que.size() == 0)
			break;
		if (store.size() > 0 && current == store[0].first.first)
		{
			auto temp = store[0];
			store.erase(store.begin());
			bool valid = false;
			for (int i = 0; i < que.size(); i++)
			{
				if (temp.second < que[i].second && i != 0)
				{
					que.insert(que.begin() + i, temp);
					valid = true;
					break;
				}
			}
			if (!valid)
				que.push_back(temp);
		}

		if (que.size() > 0 && que[0].first.first + que[0].first.second == current)
		{
			que.erase(que.begin());
			if (que.size() > 0)
			{
				max = std::max(max, current - que[0].first.first);
				que[0].first.first = current;
			}
		}

		current++;
	}
	std::ofstream fout("convention2.out");
	fout << max;
}