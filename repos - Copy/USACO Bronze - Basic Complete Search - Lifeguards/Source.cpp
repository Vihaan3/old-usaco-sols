#include <iostream>
#include <vector>

int main()
{
	int num;
	std::cin >> num;
	std::vector <std::vector<int>> guards;
	for (int i = 0; i < num; i++)
	{
		std::vector <int> a;
		int p, q;
		std::cin >> p >> q;
		a.push_back(p);
		a.push_back(q);
		guards.push_back(a);
	}
	int time = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = i; j < num; j++)
		{
			if (i != j)
			{
				if (guards[i][0] )
				{

				}
			}
		}
	}

	std::cout << time;
}