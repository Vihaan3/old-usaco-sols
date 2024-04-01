#include <iostream>
#include <vector>

int num;
std::vector <std::vector<int>> x;
void flip(int i, int j)
{
	for (int k = 0; k <= i; k++)
	{
		for (int l = 0; l <= j; l++)
		{
			if (x[k][l] == 1)
			{
				x[k][l] = 0;
			}
			else
			{
				x[k][l] = 1;
			}
		}
	}

}


int main()
{
	
	std::cin >> num;
	
	for (int i = 0; i < num; i++)
	{
		std::vector <int> a;
		
		for (int j = 0; j < num; j++)
		{
			int p;
			std::cin >> p;
			a.push_back(p);
		}
		
		x.push_back(a);
	}
	int count = 0;
	for (int k = num; k >= 0; k--)
	{
		for (int l = num; l >= 0; l--)
		{
			if (x[k][l] == 1)
			{
				flip(k, l);
				count++;
			}
		}
	}
	std::cout << count;


}
