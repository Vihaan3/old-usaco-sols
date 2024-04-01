#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
	int num;
	std::cin >> num;
	std::unordered_map <std::string, int> cycle;
	cycle["Ox"] = 0;
	cycle["Tiger"] = 1;
	cycle["Rabbit"] = 2;
	cycle["Dragon"] = 3;
	cycle["Snake"] = 4;
	cycle["Horse"] = 5;
	cycle["Goat"] = 6;
	cycle["Monkey"] = 7;
	cycle["Rooster"] = 8;
	cycle["Dog"] = 9;
	cycle["Pig"] = 10;
	cycle["Rat"] = 11;
	std::unordered_map <int, int> cows;
	std::vector<std::string> names;
	int name_counter = 0;
	for (int i = 0; i < num; i++)
	{
		std::string name, trash, time, year, name1;
		std::cin >> name >> trash >> trash >> time >> year >> trash >> trash >> name1;
		// use map to store cow name to some value, preproccess statement within this for loop to find number of years to bessie, store all cows in map of number of years to bessie, watch out for elsie call and figure out number of years for elsie
		names.push_back(name);
		name_counter++;
		if (time == "previous")
		{
			cows[name_counter] = 12 - cycle[name];
		}
		else
		{
			cows[name_counter] = cycle[name];
		}
	}
}
