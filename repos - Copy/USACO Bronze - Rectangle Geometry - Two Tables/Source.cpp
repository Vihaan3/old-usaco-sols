#include <iostream>
#include <vector>

int main()
{
	std::pair <int, int> room;
	std::pair<int, int> rect1d;
	std::pair<int, int> rect2d;
	std::pair<std::pair<int, int>, std::pair<int, int>> rect1;
	std::vector <std::string> directions = {"U", "D", "L", "R"};

	int roomx, roomy, rectx1, recty1, rectx2, recty2;

	std::cin >> room.first >> room.second >> rect1.first.first >> rect1.first.second >> rect1.second.first >> rect1.second.second>> rect2d.first >> rect2d.second;
	rect1d.first = rect1.second.first - rect1.first.first;
	rect1d.second = rect1.second.second - rect1.first.second;
	bool found = false;
	int min = 100000;
	for (std::string direction : directions)
	{

		if (direction == "U")
		{
			if (rect1d.second + rect2d.second <= room.second)
			{
				found = true;
				int change = (room.second - rect2d.second) - rect1.second.second;
				if (change < 0)
				{
					change *= -1;
				}
				else
				{
					change = 0;
				}

				min = std::min(change, min);
			}
		}
		else if (direction == "D")
		{
			if (rect1d.second + rect2d.second <= room.second)
			{	
				found = true;
				int change = rect2d.second - rect1.first.second;
				if (change < 0)
				{
					change = 0;
				}

				min = std::min(change, min);
			}
		}
		else if (direction == "L")
		{
			if (rect1d.first + rect2d.first <= room.first)
			{
				found = true;
				int change = rect2d.first - rect1.first.first;
				if (change < 0)
				{
					change = 0;
				}

				min = std::min(change, min);
			}
		}
		else if (direction == "R")
		{
			if (rect1d.first + rect2d.first <= room.first)
			{
				found = true;
				int change = (room.first - rect2d.first) - rect1.second.first;
				if (change < 0)
				{
					change *= -1;
				}
				else
				{
					change = 0;
				}

				min = std::min(change, min);
			}
		}
	}

	if (found)
	{
		std::cout << min;
	}
	else
	{
		std::cout << -1;
	}
}
