#include <iostream>
#include <vector>

int main()
{
	int num, num1;
	std::cin >> num >> num1;
	std::vector<std::vector<int>> potential;
	std::vector<std::vector<int>> rank;

	for (int i = 0; i < num; i++)
	{
		std::vector<int> r;
		for (int j = 0; j < num1; j++)
		{
			int k;
			std::cin >> k;
			r.push_back(k);
		}
		rank.push_back(r);
	}
	
	for (int j = 0; j < num1; j++)
	{
		for (int k = 0; k < num1; k++)
		{

			if (j != k)
			{
				std::vector <int> q;
				
				q.push_back(rank[0][j]);
				q.push_back(rank[0][k]);
				if (j > k)
				{
					q.push_back(1);
				}
				else
				{
					q.push_back(0);
				}
				potential.push_back(q);
			}
		}
	}

	for (int i = 1; i < num; i++)
	{
		for (int k = 0; k < num1; k++)
		{
			for (int j = 0; j < num1; j++)
			{
				if (i != j)
				{
					if (potential[((i-1)*num1)+j][2] != -1)
					{
						if (potential[((i - 1) * num1) + j][2] == 0)
						{

						}
						else
						{

						}

					}
				}
			
			}
		}
	}

	
}



