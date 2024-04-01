#include <iostream>
#include <fstream>
#include <vector>
//#define fin std::cin 
//#define fout std::cout 


int main()
{
	std::ifstream fin("badmilk.in");
	std::ofstream fout("badmilk.out");
	int people, milk, d, s;
	std::cin >> people >> milk >> d >> s;
	std::vector <std::vector<std::pair <int, int>>> friends (people+1);
	std::vector <std::vector<std::pair <int, int>>> milks (milk + 1, std::vector<std::pair <int, int>> (people+1));
	std::vector <std::pair <int, int>> sick(people + 1);
	std::vector <int> general_sick;

	for (int i = 0; i < d; i++)
	{
		int person, type, time;
		fin >> person >> type >> time;
		friends[person].push_back(std::make_pair(type, time));
		milks[type][person].first = 1;
		milks[type][person].second = time;
	}
	for (int i = 0; i < s; i++)
	{
		int person, time;
		fin >> person >> time;
		sick[person].first = 1; 
		sick[person].second = time;
		general_sick.push_back(person);
	}
	int min_sick = friends[general_sick[0]].size();
	int least_person = general_sick[0];
	for (int i = 0; i < s; i++)
	{
		if (friends[general_sick[i]].size() < min_sick)
		{
			min_sick = friends[general_sick[i]].size();
			least_person = general_sick[i];
		}
	}
	int max = 0;
	for (int i = 0; i < friends[least_person].size(); i++)
	{
		int count = 0;
		for (int j = 0; j < general_sick.size(); j++)
		{
			if (milks[friends[least_person][i].first][general_sick[j]].first == 1 && friends[least_person][i].second < sick[least_person].second)
			{
				count++;
			}
		}
		if (count == s)
		{
			int maxer = milks[friends[least_person][i].first].size();
			max = std::max(max, maxer);
		}
	}
	fout << max-1;
}
