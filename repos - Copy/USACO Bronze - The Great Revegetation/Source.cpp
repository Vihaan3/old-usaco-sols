#include <iostream>
#include <fstream>
#include <vector>
#define fin std::cin 
#define fout std::cout

int main()
{
	//std::ifstream fin("revegetate.in");
	//std::ofstream fout("revegetate.out");
	int n, m;
	fin >> n >> m;
	std::vector <std::vector <int>> relationships(n+1);
	std::vector <std::vector <int>> available(n + 1, std::vector <int> (5));
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			available[i][j] = j;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		fin >> a >> b;
		relationships[a].push_back(b);
		relationships[b].push_back(a);
	}
	std::vector<int> output;

	for (int i = 1; i < n+1; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			if (available[i][j] != 0)
			{
				output.push_back(available[i][j]);
				for (int k = 0; k < relationships[i].size(); k++)
				{
					available[relationships[i][k]][j] = 0;
				}
				break;
			}
		}
	}
	for (int i = 0; i < output.size(); i++)
		fout << output[i];
}