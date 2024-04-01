#include <vector>
#include <iostream>
#include <string>
#define string std::string

std::vector <int> locs;
std::pair <int, int> h_ray;
std::pair <int, int> g_ray;
std::vector <std::pair<int, std::pair <int, int>>> cow_range;
std::vector <std::pair<int, std::pair <int, int>>> winners;
int dependent = 0;
int g_indep = 0;
int h_indep = 0;

int main()
{
	h_ray.first = 0;
	h_ray.second = 0;
	g_ray.first = 0;
	g_ray.second = 0;
	int h = 0;
	int g = 0;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{	
		int value = 0;
		char c;
		std::cin >> c;
		if (c == 'H')
		{
			value = 0;
			if (h == 0)
			{
				h_ray.first = i;
				h++;
			}
			else
			{
				h_ray.second = i;
			}
			
		}
		else
		{
			value = 1;
			if (g == 0)
			{
				g_ray.first = i;
				g++;
			}
			else
			{
				g_ray.second = i;
			}
		}
		locs.push_back(value);
		if (h_ray.second == 0)
		{
			h_ray.second = h_ray.first;
		}
		if (g_ray.second == 0)
		{
			g_ray.second = g_ray.first;
		}
	}
	for (int i = 0; i < n; i++)
	{
		int b;
		std::cin >> b;
		std::pair <int, std::pair<int, int>> x;
		x.first = locs[i];
		x.second.first = i;
		x.second.second = b-1;
		cow_range.push_back(x);
	}

	for (std::pair<int, std::pair<int, int>> range : cow_range)
	{
		std::pair <int, int> range_s = range.second;


		if (range.first == 0)
		{
			if (range_s.first <= h_ray.first && range_s.second >= h_ray.second)
			{
				winners.push_back(range);
				h_indep++;
			}
		}
		else
		{
			if (range_s.first <= g_ray.first && range_s.second >= g_ray.second)
			{
				winners.push_back(range);
				g_indep++;

			}
		}
	}

	for (std::pair<int, std::pair<int, int>> range : cow_range)
	{
		for (std::pair<int, std::pair<int, int>> winner : winners)
		{
			if (range.first != winner.first)
			{
				if (winner.second.first >= range.second.first && winner.second.first <= range.second.second)
				{
					dependent++;
				}
			}
		}
	}
			

	std::cout << (h_indep * g_indep) + dependent;
}