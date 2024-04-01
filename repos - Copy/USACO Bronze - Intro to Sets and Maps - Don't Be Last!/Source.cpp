#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#define umap std::unordered_map

int main()
{
	int num;
	std::cin >> num;
	umap <std::string, int> cows;
	std::vector<std::string> names{"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
	std::vector<int> ints{0, 0, 0, 0, 0, 0, 0};
	cows["Bessie"] = 0;
	cows["Elsie"] = 1;
	cows["Daisy"] = 2;
	cows["Gertie"] = 3;
	cows["Annabelle"] = 4;
	cows["Maggie"] = 5;
	cows["Henrietta"] = 6;
	for (int i = 0; i < num; i++)
	{
		std::string s;
		int v;
		std::cin >> s >> v;
		ints[cows[s]] += v;
	}
	std::sort(cows);
	std::string min_cow;
	int min = 10000000000;
	for (std::string name : names)
	{
		
	}
}