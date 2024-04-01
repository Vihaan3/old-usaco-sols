#include <vector>
#include <iostream>
#include <algorithm>

int n;
std::vector <int> bales;

int next(int i, int direction)
{
	int radius = 1;
	int track = i;
	int counter = 0;
	while (true)
	{
		int loc = bales[track] + radius * direction;
		int cache = 0;
		if (direction > 0)
		{
			for (int j = i; j < n; j++)
			{


				if (!(bales[j] <= loc))
				{
					cache = j - 1;
					break;
				}


			}
		}
		else
		{
			for (int j = i; j > -1; j--)
			{

				if (!(bales[j] >= loc))
				{
					cache = j + 1;
					break;
				}


			}
		}
		if (cache == track)
		{
			break;
		}
		track = cache;
		counter++;
		radius++;
	}
	return counter;
}

int main(void)
{

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		std::cin >> a;
		bales.push_back(a);
	}
	std::sort(bales.begin(), bales.end());
	int max = 0;
	for (int i = 0; i < n; i++)
		max = std::max(max, next(i, 1) + next(i, -1) + 1);
	std::cout << max;
}
