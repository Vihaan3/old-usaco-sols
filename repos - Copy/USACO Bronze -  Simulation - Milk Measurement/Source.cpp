#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#define umap unordered_map 
#define string std::string
std::vector <string> victory;
std::vector <string> new_victor;

void victor(int i);


int num;
std::vector <int> numb;
std::map <int, std::pair <string, int>> log;
std::umap <string, int> cows;
std::vector <string> winners;


int main()
{
	
	std::cin >> num;
	cows["Mildred"] = 7;
	cows["Bessie"] = 7;
	cows["Elsie"] = 7;
	
	for (int i = 0; i < num; i++)
	{
		int p, q;
		string s;
		std::cin >> p >> s >> q;
		log[p].first = s;
		log[p].second = q;
		numb.push_back(p);
	}
	int change = 0;
	std::sort(numb.begin(), numb.end());
	for (int i = 0; i < num; i++)
	{
		cows[log[numb[i]].first] += log[numb[i]].second;
		victor(i);
		if (new_victor != victory)
		{
			victory = new_victor;
			change++;
		}
	}
	std::cout << change;
}

void victor()
{
	int max = 0;
	std::vector <string> news_victor;
	for (int i = 0; i < num; i++)
	{
		max = std::max(cows[log[numb[i]].first], max);
	}
	for (int i = 0; i < num; i++)
	{
		if (cows[log[numb[i]].first] == max)
		{
			news_victor.push_back(log[numb[i]].first);
		}
	}
	new_victor = news_victor;
}