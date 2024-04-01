#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int num;
	std::cin >> num;
	std::vector<std::pair<std::pair<std::pair<int, int>, int>, std::pair<std::pair<int, int>, int>>> collisions;
	std::vector <std::pair<std::pair<int, int>, int>> n_locations;
	std::vector <std::pair<std::pair<int, int>, int>> e_locations;
	std::vector <int> moves(num);
	std::vector <int> alive(num);
	for (int i = 0; i < num; i++)
	{
		char direction;
		int x, y;
		std::pair <std::pair<int, int>, int> tmp;
		std::cin >> direction >> x >> y;
		tmp.first.first = x;
		tmp.first.second = y;
		tmp.second = i;

		if (direction == 'N')
		{
			n_locations.push_back(tmp);
		}
		else
		{
			e_locations.push_back(tmp);
		}
	}
	for (std::pair <std::pair<int, int>, int> tmp : n_locations)
	{
		int i = 0;
		for (std::pair <std::pair<int, int>, int> tmper : e_locations)
		{
			int j = 0;
			std::pair<std::pair<std::pair<int, int>, int>, std::pair<std::pair<int, int>, int>> x;
			x.first.first.first = tmp.first.first;
			x.first.first.second = tmp.first.second;
			x.first.second = tmp.second;

			x.second.first.first = tmper.first.first;
			x.second.first.second = tmper.first.second;
			x.second.second = tmper.second;

			collisions.push_back(x);
			
		}

		i++;
	}
	std::sort(collisions.begin(), collisions.end());
	/* Loop thru the alive vector and set all values to zero.
	Now go thru all of the collisions. For each collision, check if the two cows are still alive
	If so, simulate the collision. At the end, loop thru moves. Print out the number of moves,
	and print Infinity if the value is 0.
	*/
	for (int i = 0; i < num; i++)
	{
		alive[i] = 0;
		moves[i] = 0;
	}

	for (std::pair<std::pair<std::pair<int, int>, int>, std::pair<std::pair<int, int>, int>> collision : collisions)
	{
		if (alive[collision.first.second] == 0 && alive[collision.second.second] == 0)
		{
			std::pair<int, int> collision_location;
			collision_location.first = collision.first.first.first;
			collision_location.second = collision.second.first.second;
			int e_change = collision_location.first - collision.second.first.first;
			int n_change = collision_location.second - collision.first.first.second;

			if (e_change < n_change)
			{
				alive[collision.first.second] = 1;
				moves[collision.first.second] = n_change;
			}
			else if (n_change < e_change)
			{
				alive[collision.second.second] = 1;
				moves[collision.second.second] = e_change;
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		if (moves[i] == 0)
		{
			std::cout << "Infinity" << std::endl;
		}
		else
		{
			std::cout << moves[i] << std::endl;

		}
	}
}