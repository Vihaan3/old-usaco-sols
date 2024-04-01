#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#define string std::string

int main()
{
	std::unordered_map <string, int> years = { {"Ox",0 }, {"Tiger", 1},
	{"Rabbit", 2}, { "Dragon", 3 }, { "Snake", 4 }, { "Horse", 5 }, { "Goat", 6 },
	{"Monkey", 7 }, {"Rooster", 8}, {"Dog", 9}, {"Pig", 10}, {"Rat", 11}};

	int n;
	std::cin >> n;
	std::unordered_map <string, std::pair <string, int>> distances;
	distances["Bessie"].first = "Ox";
	distances["Bessie"].second = 0;
	for (int i = 0; i < n; i++)
	{
		string curr, dir, year, relation, trash;
		std::cin >> curr >> trash >> trash >> dir >> year >> trash >> trash >> relation;
		if (dir == "previous" && years[year] > years[distances[relation].first])
		{
			distances[curr].second = (- 1 * (12 - (years[year] - years[distances[relation].first]))) + distances[relation].second;
		}
		else if (dir == "previous" && years[year] <= years[distances[relation].first])
		{
			distances[curr].second = years[year] - years[distances[relation].first] + distances[relation].second;
		}
		else if (dir == "next" && years[year] < years[distances[relation].first])
		{
			distances[curr].second =  (12 + years[year] - years[distances[relation].first]) + distances[relation].second;
		}
		else if (dir == "next" && years[year] >= years[distances[relation].first])
		{
			distances[curr].second = years[year] - years[distances[relation].first] + distances[relation].second;
		}
		distances[curr].first = year;
	}
	std::cout << abs(distances["Elsie"].second);
	/*
	*
	while taking in the input, calculate the number of years (using negative to indicate before and positive to indicate after) from bessie by finding the occurence of the relation in the vector
	print the absolute value of the answer as soon as you know how far elsie and bessie are
     */

}