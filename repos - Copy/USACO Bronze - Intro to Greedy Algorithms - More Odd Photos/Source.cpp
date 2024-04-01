#include <iostream>
#include <vector>


int main()
{
	int groups = 0;
	int num;
	std::cin >> num;
	std::vector <int> photos;
	int odd = 0;
	int even = 0;
	for (int i = 0; i < num; i++)
	{
		int p;
		std::cin >> p;
		photos.push_back(p);
		if (p % 2 == 0)
		{
			even++;
		}
		else
		{
			odd++;
		}
	}
	groups += (even + (odd/3)*2);
	
	std::cout << groups;
}
