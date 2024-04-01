#include <iostream>
#include <vector>
#define c char
void solve()
{
	int n;
	int m;
	std::cin >> n >> m;
	std::vector <std::vector <c>> locs(n, std::vector <c>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			std::cin >> locs[i][j];
	}
	for (int i = 0; i < n; i++)
	{
		bool white = true;
		for (int j = 0; j < m; j++)
		{
			if (locs[i][j] == 'U')
			{
				if (white)
				{
					locs[i][j] = 'W';
					locs[i+1][j] = 'B';
					white = false;
				}
				else
				{
					locs[i][j] = 'B';
					locs[i + 1][j] = 'W';
					white = true;
				}
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		bool white = true;
		for (int j = 0; j < n; j++)
		{
			if (locs[i][j] == 'L')
			{
				if (white)
				{
					locs[j][i + 1] = 'W';
					locs[j][i] = 'B';
					white = false;
				}
				else
				{
					locs[j][i] = 'B';
					locs[j][i+1] = 'W';
					white = true;
				}
			}
		}
	}
	// RUN A CHECK ON WHETHER THIS ONE IS POSSIBLE
}


int main()
{
	int num; 
	std::cin >> num;
	while (num--)
		solve();
}