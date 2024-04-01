#include <iostream>
#include <vector>

int main()
{
	int n, k;
	std::cin >> n >> k;

	std::vector <std::vector <int>> grid (1000, std::vector<int> (1001));
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		for (int j = a; j < c; j++)
		{
			grid[j][b]++;
			grid[j][d]--;
		}
	}
	int counter = 0;
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			grid[i][j+1] += grid[i][j];
			if (grid[i][j] == k)
			{
				counter++;
			}
		}
	}

	std::cout << counter;
}