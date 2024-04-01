#include <vector>
#include <iostream>
#include <algorithm>
int num_cows, num_interactions;
std::vector <bool> sick;
std::vector <std::pair<int, std::pair<int, int>>> interactions;
std::vector <std::pair<bool, int>> new_sick;


bool check(int cow, int turn, int k)
{
	cow--;

	if (new_sick[cow].first == true)
	{
		if (interactions[turn].first - new_sick[cow].second > k)
		{
			new_sick[cow].first = false;
			new_sick[cow].second = 0;
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

std::vector <bool> loop(int k, int patient_zero)
{

	new_sick[patient_zero].first = true;
	new_sick[patient_zero].second = 0;

	for (int i = 0; i < num_interactions; i++)
	{
		if (check(interactions[i].second.first, i, k) == true)
		{
			new_sick[(interactions[i].second.second)-1].first = true;
			new_sick[(interactions[i].second.second)-1].second = interactions[i].first;
		}
		else if (check(interactions[i].second.second, i, k) == true)
		{
			new_sick[(interactions[i].second.first)-1].first = true;
			new_sick[(interactions[i].second.first)-1].second = interactions[i].first;
		}
	}
	std::vector <bool> to_send;
	for (int i = 0; i < num_cows; i++)
	{
		to_send[i] = new_sick[i].first;
		new_sick[i].first = false;
		new_sick[i].second = 0;
	}

	return to_send;
	
}

int main()
{
	std::cin >> num_cows >> num_interactions;
	for (int i = 0; i < num_cows; i++)
	{
		char c;
		std::cin >> c;
		if (c == '0')
		{
			sick.push_back(false);
		}
		else
		{
			sick.push_back(true);
		}
	}

	for (int i = 0; i < num_interactions; i++)
	{
		int time, x, x1;
		std::cin >> time >> x >> x1;
		std::pair<int, std::pair <int, int>> b;
		std::pair <int, int> a;
		a.first = x;
		a.second = x1;
		b.first = time;
		b.second = a;
		interactions.push_back(b);
	}

	for (int i = 0; i < num_cows; i++)
	{
		std::pair<bool, int> x;
		x.first = false;
		x.second = 0;
		new_sick.push_back(x);
	}

	std::sort(interactions.begin(), interactions.end());
	int max = 0;
	int min = 1000000;
	int count = 0;
	for (int i = 0; i < num_interactions; i++)
	{
		for (int j = 0; j < num_cows; j++)
		{

			std::vector <bool> tmp = loop(i, j);
			if (tmp == sick)
			{
				count++;
				int max = std::max(max, i);
				int min = std::min(min, i);
			}
		}
	}

	if (count == num_interactions - 1)
	{
		std::cout << count << min << "Infinity";
	}
	else
	{
		std::cout << count << min << max;
	}
}