#include <iostream>
#include <vector>

void solve()
{
	int n, k;
	std::cin >> n >> k;
	std::vector<std::vector<char>> pos (n, std::vector <char> (n));
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> pos[i][j];
		}
	}
	int count = 0;
	if (k >= 1)
	{
		bool valid1 = true;
		bool valid2 = true;

		for (int i = 0; i < n; i++)
		{
			if (pos[0][i] == 'H' || pos[i][n - 1] == 'H')
			{
				valid1 = false;
			}
			if (pos[i][0] == 'H' || pos[n - 1][i] == 'H')
			{
				valid2 = false;
			}
		}
		if (valid1)
			count++;
		if (valid2)
			count++;
	}
	if (k >= 2)
	{
		// COULD BE AN ERROR DUE TO BEING TO SMALL TO BE ABLE TO DO n-2
		for (int i = 1; i < n - 1; i++)
		{
			if (pos[0][i] != 'H')
			{
				bool valid = true;
				for (int j = 0; j < n; j++)
				{
					if (pos[j][i] == 'H')
					{
						valid = false;
						break;
					}
				}
				for (int k = i; k < n && valid; k++)
				{
					if (pos[n - 1][k] == 'H')
					{
						break;
					}
					if (k == n - 1)
					{
						count++;
					}
				}
				
			}
			if (pos[i][0] != 'H')
			{
				bool valid = true;
				for (int j = 0; j < n; j++)
				{
					if (pos[i][j] == 'H')
					{
						valid = false;
						break;
					}
				}
				for (int k = i; k < n && valid; k++)
				{
					if (pos[k][n-1] == 'H')
					{
						break;
					}
					if (k == n - 1)
					{
						count++;
					}
				}
				
			}
		}
	}
	if (k == 3)
	{
	
	}
	std::cout << count;
}


int main()
{
	int n;
	std::cin >> n;
	while (n--)
		solve();
}