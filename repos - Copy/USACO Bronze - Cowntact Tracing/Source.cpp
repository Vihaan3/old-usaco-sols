#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#define string std::string
#define fin std::cin 
#define fout std::cout

bool simulate(string s, std::vector <std::pair <int, int>> interactions, int index, int k)
{
	std::vector <int> turns (s.size());
	string simul = s;
	for (int i = 0; i < s.size(); i++)
	{
		if (i == index)
		{
			turns[i] = k;
		}

		if (i != index)
		{
			simul[i] = '0';
		}
	}
	
	for (auto interaction : interactions)
	{
		if (turns[interaction.first] > 0)
		{
			turns[interaction.first]--;
			if (simul[interaction.second] == '0')
			{
				simul[interaction.second] = '1';
				turns[interaction.second] = k;
			}
		}
		else if (turns[interaction.second] > 0)
		{
			turns[interaction.second]--;
			if (simul[interaction.first] == '0')
			{
				simul[interaction.first] = '1';
				turns[interaction.first] = k;
			}
		}
	}
	
	return s == simul;
}




int main()
{
	int n, t;
	string s;
	//std::ifstream fin("tracing.in");
	//std::ofstream fout("tracing.out");

	fin >> n >> t >> s;
	std::vector <int> sick;
	std::vector <std::pair<int, std::pair<int, int>>> interact (t);

	for (int i = 0; i < t; i++)
	{
		fin >> interact[i].first >> interact[i].second.first >> interact[i].second.second;
		interact[i].second.first--;
		interact[i].second.second--;
	}
	std::sort(interact.begin(), interact.end());

	std::vector <std::pair <int, int>> interactions (t);

	for (int i = 0; i < t; i++)
	{
		interactions[i].first = interact[i].second.first;
		interactions[i].second = interact[i].second.second;
	}

	// ERROR COULD BE THIS!!!!!!
	int min = 251;
	int max = 0;
	std::unordered_set<int> valid;

	for (int i = 0; i < n; i++)
	{
		if (s[i] == '1')
		{
			for (int k = 0; k <= t; k++)
			{
				bool check = simulate(s, interactions, i, k);
				if (check)
				{
					// THIS MIGHT BE THE PROBLEM, YOU HAVE TO DO SOMETHING ELSE FOR MIN AND MAX

					valid.insert(i);
					min = std::min(min, k);
					max = std::max(max, k);
				}
			}
		
		}
	}
	string s_max = "";

	fout << valid.size() << " " << min << " ";
	if (max == t)
	{
		fout <<  "Infinity";
	}
	else
	{
		fout << max;
	}

	
	//ERROR COULD BE BECAUSE OF EDGE CASE WHERE K IS 0
}