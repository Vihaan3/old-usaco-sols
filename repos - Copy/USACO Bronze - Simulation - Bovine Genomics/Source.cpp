#include <iostream>
#include <vector>
#include <unordered_map>
#define string std::string
#define umap std::unordered_map

int change(char s)
{
	std::unordered_map <char, int> saanchi;
	saanchi['A'] = 0;
	saanchi['C'] = 1;
	saanchi['G'] = 2;
	saanchi['T'] = 3;
	return saanchi[s];
}

int main()
{
	int num, trash;
	std::cin >> num >> trash;
	std::vector <std::vector <int>> spotty;
	std::vector <std::vector <int>> plain;
	
	for (int i = 0; i < num; i++)
	{
		std::vector <int> spott;
		for (int j = 0; j < trash; j++)
		{
			char s;
			std::cin >> s;
			spott.push_back(change(s));
		}
		spotty.push_back(spott);
	}
	for (int i = 0; i < num; i++)
	{
		std::vector <int> spott;
		for (int j = 0; j < trash; j++)
		{
			char s;
			std::cin >> s;
			spott.push_back(change(s));
		}
		plain.push_back(spott);
	}
	int count = 0;
	for (int i = 0; i < trash; i++)
	{
		for (int j = i + 1; j < trash; j++)
		{
			for (int k = j + 1; k < trash; k++)
			{
				umap  <int, int> all;
				int little_count = 0;

				for (int l = 0; l < num; l++)
				{
					all[(spotty[l][i] * 16) + (spotty[l][j] * 4) + (spotty[l][k] * 1)] = 1;

				}

				for (int l = 0; l < num; l++)
				{
					if (all[(plain[l][i] * 16) + (plain[l][j] * 4) + (plain[l][k] * 1)] == 1)
					{
						little_count++;
					}

				}
				if (little_count == 0)
				{
					count++;
				}
			}
		}
	}
	
	std::cout << count;
}