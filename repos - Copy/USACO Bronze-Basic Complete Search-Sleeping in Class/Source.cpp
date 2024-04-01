#include <iostream>
#include <vector>
#include <set>

int main()
{
	int num;
	std::cin >> num;
	for (int i = 0; i < num; i++)
	{
		int num1;
		std::cin >> num1;
		int sum = 0;
		std::vector <int> test;
		for (int j = 0; j < num1; j++)
		{
			int h;
			std::cin >> h;
			sum += h;
			test.push_back(h);
		}

		for (int j = 0; j < sum; j++)
		{
			if (j != 0 && sum % j == 0)
			{
				int curr = 0;
				bool val = true;
				for (int k = 0; k < num1; k++)
				{
					if (curr < j)
					{
						curr += test[k];
					}
					else if (curr == j)
					{
						curr = 0;
					}
					else 
					{
						val = false;
					}

				}
				if (val)
				{
					std::cout << j << std::endl;
				}
			}
		}
	}
}
