#include <iostream>
#include <vector>
#include <map>
#define map std::map
#define string std::string

int main()
{
	int num;
	std::cin >> num;
	map<int, string> numbers;
	std::vector<int> v;
	for (int i = 0; i < num; i++)
	{
		string s;
		int q;
		std::cin >> s >> q;
		numbers[q] = s;
		v.push_back(q);
	}
	int liars = 100;
	int count = 0;
	for (auto x : v)
	{
		for (auto y : v)
		{
			int liar = 0;
			if (x != y)
			{
				if (numbers[x] == "G")
				{
					if (numbers[y] == "L")
					{
						if (y < x)
						{
							liar++;
						}
					}
				}
				else
				{
					if (numbers[y] == "G")
					{
						if (x < y)
						{
							liar++;
						}
					}
				}
			}
			liars = std::min(liars, liar);
		}
	}
	std::cout << liars;
}