#include <iostream>
#include <vector>

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<char>> genome;
	std::vector <std::vector<char>> genome1;
	for (int i = 0; i < n*2; i++)
	{
		std::vector <char> q;
		for (int k = 0; k < m; k++)
		{
			char s;
			std::cin >> s;
			q.push_back(s);
			
		}
		if (i < n)
		{
			genome.push_back(q);
		}
		else
		{
			genome1.push_back(q);
		}
	}
	int nor = 0;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			int nah = 0;
			for (int l = n; l < n*2; l++)
			{
				if (genome[i][k] == genome1[l-n][k])
				{
					nah++;
				}
			}
			if (nah > 0)
			{
				nor++;
			}
		}
	}

	std::cout << m-nor;
}