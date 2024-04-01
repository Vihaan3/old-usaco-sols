#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define string std::string

std::vector <std::vector <string>> solve(std::vector <std::vector <string>> rand, std::unordered_map <string, int> og)
{
	std::vector <string> paper (rand.size());
	for (int i = 0; i < rand.size(); i++)
	{
		std::cin >> paper[i];
	}
	std::vector <int> points(rand.size());
	int point = 1;
	for (int i = 0; i < rand.size()-1; i++)
	{
		// ERRORS MIGHT HAVE TO DO WITH THE FACT THAT THIS DOESN"T COMPARE CORRECTLY
		if (paper[i] > paper[i + 1])
		{
			points[i] = point;
			point++;
			points[i + 1] = point;
		}
		else
		{
			points[i] = point;
			points[i + 1] = point;
		}
	}
	for (int i = 0; i < rand.size(); i++)
	{
		for (int j = 0; j < rand.size(); j++)
		{
			if (i != j)
			{
				if (points[i] < points[j])
				{
					if (rand[og[paper[i]]][og[paper[j]]] == "?" || rand[og[paper[i]]][og[paper[j]]] == "")
					{
						rand[og[paper[i]]][og[paper[j]]] = "0";
					}
				}
				else if (points[i] > points[j])
				{
					if (rand[og[paper[i]]][og[paper[j]]] == "?" || rand[og[paper[i]]][og[paper[j]]] == "")
					{
						rand[og[paper[i]]][og[paper[j]]] = "1";
					}
				}
				else
				{
					if (rand[og[paper[i]]][og[paper[j]]] == "?" || rand[og[paper[i]]][og[paper[j]]] == "")
					{
						rand[og[paper[i]]][og[paper[j]]] = "?";
					}
				}
			}
			else
			{
				rand[og[paper[i]]][og[paper[j]]] = "B";
			}
		}
	}
	return rand;
}

int main()
{
	int n, k;
	std::cin >> k >> n;
	std::unordered_map <string, int> og;
	for (int i = 0; i < n; i++)
	{
		string s;
		std::cin >> s;
		og[s] = i;
	}
	std::vector <std::vector <string>> back (n, std::vector<string> (n));
	while (k--)
	{ 
		 back = solve(back, og);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << back[i][j];
		}
		std::cout << std::endl;
	}
}