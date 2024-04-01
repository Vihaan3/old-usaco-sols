#include <iostream>
#include <vector>
#include <fstream>

int main()
{
	std::ifstream read("factory.in");
	int num;
	read >> num;
	std::vector <int> destination (num);
	for (int i = 0; i < num; i++)
	{
		destination.push_back(0);
	}
	for (int i = 0; i < num -1; i++)
	{
		int p, q;
		std::cin >> p >> q;
		destination[q - 1]++;
	}
	bool found = false;
	for (int i = 0; i < num; i++)
	{
		if (destination[i] == num - 1)
		{
			std::ofstream("factory.out") << num-1;
			found = true;
		}
	}

	if (found == false)
	{
		std::ofstream("factory.out") << -1;

	}
}
