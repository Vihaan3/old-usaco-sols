#include <iostream>
#include <vector>
std::vector <int> available;
bool solve(int element, std::vector <std::vector <int>> posses)
{
	bool valid = true;
	int number = 0;
	for (int i = 0; i < posses[element - 1].size(); i++)
	{
		
		if (available[posses[element - 1][i]] > 0)
		{
			number++;
			available[posses[element - 1][i]]--;
		}
		else
		{
			valid = solve(posses[element - 1][i], posses);
			if (!valid)
				break;
			else
				number++;
		}
		if (!valid)
			break;
	}
	return valid;
}

int main()
{
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		std::cin >> x;
		available.push_back(x);
	}

	std::vector <std::vector <int>> posses(n);
	int k;
	std::cin >> k;
	for (int i = 0; i < k; i++)
	{
		int a;
		std::cin >> a;
		int x;
		std::cin >> x;
		for (int j = 0; j < x; j++)
		{
			int b;
			std::cin >> b;
			posses[a - 1].push_back(b - 1);
		}
	}
	int count = 0;
	bool valid = true;
	int number = 0;
	while (valid)
	{
		for (int i = 0; i < posses[n - 1].size(); i++)
		{

			if (available[posses[n - 1][i]] > 0)
			{
				available[posses[n - 1][i]]--;
				number++;
			}
			else
			{
				valid = solve(posses[n - 1][i], posses);

				if (valid == false)
					break;
				else
					number++;
			}
			if (!valid)
				break;
			if (number == posses[n - 1].size())
			{
				count++;
			}
		}
		if (!valid)
			break;
	}

	std::cout << count + available[n - 1];
}