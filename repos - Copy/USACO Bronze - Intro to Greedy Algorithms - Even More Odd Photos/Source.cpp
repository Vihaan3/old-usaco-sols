#include <iostream>
#include <vector>

int main()
{
	int num;
	std::cin >> num;
	int even = 0;
	int odd = 0;
	for (int i = 0; i < num; i++)
	{
		int p;
		std::cin >> p;
		if (p % 2 ==  0)
		{
			even++;
		}
		else
		{
			odd++;
		}
	}
	
	while (odd > even)
	{
		odd-=2;
		even++;
	}
	while (even > odd + 1)
	{
		even--;
	}

	std::cout << even + odd;
}
