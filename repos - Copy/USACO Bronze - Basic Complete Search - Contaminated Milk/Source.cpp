#include <iostream>
#include <vector>

int main()
{
	int num_people, num_milk, num_transcript, num_sick;
	std::cin >> num_people >> num_milk >> num_transcript >> num_sick;
	std::vector <std::vector<std::pair<int, int>>> drink (num_people);
	std::vector <std::pair<int, int>> sick;
	std::vector<int> contaminated (num_milk);
	for (int i = 0; i < num_transcript; i++)
	{
		std::vector <int> a;
		int person, milk, time;
		std::cin >> person >> milk >> time;
		std::pair <int, int>x;
		x.first = milk;
		x.second = time;
		drink[person-1].push_back(x);
	}
	for (int i = 0; i < num_sick; i++)
	{
		std::pair <int, int> x;
		int person, time;
		std::cin >> person >> time;
		x.first = person;
		x.second = time;
		sick.push_back(x);
	}
	for (int i = 0; i < num_sick; i++)
	{
		int person = sick[i].first;
		for (int j = 0; j < drink[person - 1].size(); j++)
		{
			if (drink[person - 1][j].second < sick[i].second)
			{
				contaminated[(drink[person - 1][j].first)-1]++;
			}
		}
	}
	/*Then, for each of those, calculate the number of people who have drunk that 
	milk and print the maximum of all of those results.*/
	std::vector <int> actual;
	for (int i = 0; i < num_milk; i++)
	{
		if (contaminated[i] == num_sick)
		{
			actual.push_back(i + 1);
		}
	}
	int max = 0;
	for (int i = 0; i < actual.size(); i++)
	{
		int max2 = 0;
		for (int j = 0; j < num_people; j++)
		{
			for (int k = 0; k < drink[j].size(); k++)
			{
				if (drink[j][k].first == actual[i])
				{ 
					max2 += 1;
				}
			}
		}
		max = std::max(max, max2);
	}
	std::cout << max;
}

