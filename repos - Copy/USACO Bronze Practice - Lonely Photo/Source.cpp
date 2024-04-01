#include <iostream>
#include <vector>
/*
	For each element until n - 3 (might be n-3 + 1 or n-3 -1)
		loop thru to the end of the and have trackers for G and H,
			if g == 1 or h == 1, counter ++
	std::cout << counter;
*/
int main()
{
	int n;
	std::cin >> n;
	std::string input;
	std::cin >> input;
	int counter = 0;
	for (int i = 0; i < n - 2; i++)
	{
		int g = 0;
		int h = 0;
		int begin = i;
		for (int j = i; j < n; j++)
		{
			if (input[j] == 'H')
			{
				h++;
			}
			else
			{
				g++;
			}
			if (h == 1 && j - begin >= 2)
				counter++;
			if (g == 1 && j - begin >= 2)
				counter++;
		}
	}
	std::cout << counter;
}