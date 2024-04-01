#include <iostream>
#include <vector>

bool match(std::vector <std::vector <int>> answer, std::vector <std::vector <int>> rotation, int a, int b)
{
	for (int i = a; i < rotation.size() + a; i++)
	{
		for (int j = b; j < rotation.size() + b; j++)
		{
			if (rotation[i-a][j-b] == 1 && answer[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}
std::vector<std::vector <int>> stamper(std::vector<std::vector <int >> guess, std::vector <std::vector <int>> rotation, int a, int b)
{
	for (int i = a; i < rotation.size() + a; i++)
	{
		for (int j = b; j < rotation.size() + b; j++)
		{
			if (rotation[i-a][j-b] == 1)
				guess[i][j] = 1;
		}
	}
	return guess;
}


void solve()
{
	int n;
	std::cin >> n;
	std::vector <std::vector<int>> answer (n, std::vector <int> (n));
	for (int i = 0; i < n; i++)
	{
		std::string s;
		std::cin >> s;
		for (int j = 0; j < n; j++)
		{
			// THIS COULD BE THE ISSUE, YOU MIGHT HAVE TO SET TO 0
			if (s[j] == '*')
				answer[i][j] = 1;
		}
	}
	int l;
	std::cin >> l;
	std::vector <std::vector<int>> stamp(l, std::vector <int>(l));
	for (int i = 0; i < l; i++)
	{
		std::string s;
		std::cin >> s;
		for (int j = 0; j < l; j++)
		{
			// THIS COULD BE THE ISSUE, YOU MIGHT HAVE TO SET TO 0
			if (s[j] == '*')
				stamp[i][j] = 1;
		}
	}
	std::vector <std::vector<std::vector<int>>> rotations;
	rotations.push_back(stamp);
	for (int k = 0; k < 3; k++)
	{
		std::vector <std::vector<int>> rotate (l, std::vector <int> (l));
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < l; j++)
			{
				rotate[j][l-1-i] = stamp[i][j];
			}
		}
		stamp = rotate;
		rotations.push_back(rotate);
	}
	std::vector <std::vector<int>> blank(n, std::vector <int>(n));
	for (auto rotation : rotations)
	{
		for (int i = 0; i < n - l + 1; i++)
		{
			for (int j = 0; j < n - l + 1; j++)
			{
				if (match(answer, rotation, i, j))
				{
					blank = stamper(blank, rotation, i, j);
				}
			}
		}
	}
	if (answer == blank)
	{
		std::cout << "YES" << std::endl;
	}
	else
	{
		std::cout << "NO" << std::endl;
	}
}

int main()
{
	int n;
	std::cin >> n;
	while (n--)
	{
		solve();
	}
}