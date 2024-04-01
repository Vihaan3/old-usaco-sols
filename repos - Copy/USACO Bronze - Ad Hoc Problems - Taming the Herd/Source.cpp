#include <iostream>
#include <vector>

int main()
{
	int num;
	std::cin >> num;
	std::vector <int> bales;
	for (int i = 0; i < num; i++)
	{
		int n = 0;
		std::cin >> n;
		bales.push_back(n);
	}
	bales[0] = 0;
	bool valid = true;
	for (int i = 0; i < num; i++)
	{
		if (bales[i] > -1)
		{
			if (bales[i - bales[i]] != -1 && bales[i - bales[i]] != bales[i])
			{
				valid = false;
			}
			bales[i - bales[i]] = bales[i];
		}
	}
	int count = 0;
	int breakout = 0;
	for (int i = 0; i < num; i++)
	{
		if (bales[i] == -1)
		{
			count++;
		}
		if (bales[i] == 0)
		{
			breakout++;
		}
	}
	if (!valid)
	{
		std::cout << -1;
	}
	else
	{
		std::cout << breakout << " " << breakout + (num-breakout - count);
	}

}