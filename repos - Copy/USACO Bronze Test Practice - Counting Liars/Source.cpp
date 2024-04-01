#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int num;
	std::cin >> num;
	std::vector <std::pair <int, int>> all;

	for (int i = 0; i < num; i++)
	{
		std::pair <int, int> x;
		char op;
		int n;
		std::cin >> op >> n;
		int first = 0;
		int second = n;
		if (op == 'G')
			first = 1;
		else
			first = 0;
		x.first = first;
		x.second = second;
		all.push_back(x);
	}
	std::vector <std::vector<int>> liars(num, std::vector <int>(num));
	std::vector <int> counter(num);

	for (int i = 0; i < num; i++)
	{

		for (int j = i; j < num; j++)
		{
			if (all[i].first != all[j].first)
			{
				if (all[i].first == 0 && !(all[i].second > all[j].second + 1))
				{
					liars[i][j] = 1;
					liars[j][i] = 1;
					counter[i]++;
					counter[j]++;
				}
				if (all[j].first == 0 && !(all[j].second > all[i].second + 1))
				{
					liars[i][j] = 1;
					liars[j][i] = 1;
					counter[i]++;
					counter[j]++;
				}
			}
		}
	}
	int good = false;
	int count = 0;
	while (!good)
	{
		int max = 0;
		int num_zeros = 0;
		for (int i = 0; i < num; i++)
		{
			max = std::max(max, counter[i]);
			if (counter[i] == 0)
			{
				num_zeros++;
			}
		}

		if (num_zeros == num)
		{
			good = true;
			break;
		}

		for (int i = 0; i < num; i++)
		{
			// THIS COULD BE THE PROBLEM!!! IT MIGHT ONLY BE ONE AT A TIME INSTEAD OF ALL THE ONES AT MAX!!!!
			if (counter[i] == max)
			{
				count++;
				counter[i] = 0;
				for (int j = 0; j < num; j++)
				{
					if (liars[i][j] == 1)
					{
						liars[j][i] = 0;
						counter[j]--;
					}
				}
			}
		}


	}

	std::cout << count;
}