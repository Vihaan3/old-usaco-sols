#include <iostream>
#include <vector>

int main()
{
	int num, s;
	std::cin >> num >> s;
	std::vector <std::pair <int, int>> x(num);
	int num_targets = 0;
	for (int i = 0; i < num; i++)
	{
		std::cin >> x[i].first >> x[i].second;
		if (x[i].first == 1)
		{
			num_targets++;
		}
	}
	int power = 1;
	int direction = 1;
	int location = s - 1;
	int targets = 0;
	int track = 0;
	std::vector <int> them(num);
	while (true)
	{
		if (track > 1e6)
		{
			break;
		}
		if (location > num - 1 || location < 0)
		{
			break;
		}
		if (targets == num_targets)
			break;
		if (x[location].first == 1)
		{
			if (x[location].second <= power && them[location] != 1)
			{
				targets++;
				them[location] = 1;
			}
			if (direction == 1)
				location += power;
			else
				location -= power;
		}
		else
		{
			// THIS MIGHT BE THE LOGICAL ERROR
			direction = -1 * direction;
			power += x[location].second;
			if (direction == 1)
				location += power;
			else
				location -= power;
		}
		track++;
	}
	std::cout << targets;
}