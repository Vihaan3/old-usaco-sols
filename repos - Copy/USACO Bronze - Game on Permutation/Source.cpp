#include <iostream>
#include <vector>

void solve()
{
	int n; 
	std::cin >> n;
	int min = 10000000;
	int minWin = 10000000;
	int win = 0;
	while (n--)
	{
		int a;
		std::cin >> a;
		if (min > a)
		{
			min = a;
		}
		// MIGHT HAVE TO BE ELSE IF
		else
		{
			if (a < minWin)
			{
				minWin = a;
				win++;
			}
		}
	}
	std::cout << win << std::endl;
}

int main()
{
	int n; 
	std::cin >> n;
	while (n--)
		solve();
}