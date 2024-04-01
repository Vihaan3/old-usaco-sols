#include <iostream>
#include <vector>

int main()
{
	int pasture_num, num;
	std::cin >> pasture_num >> num;
	std::vector <std::vector<int>> nots (pasture_num);
	std::vector <std::vector<int>> options (pasture_num);
	for (int i = 0; i < pasture_num; i++)
	{

		std::vector <int> v = { 1, 2, 3, 4 };
		options[i] = v;
	}
		
	for (int i = 0; i < num; i++)
	{
		
		int uno, dos;
		std::cin >> uno >> dos;
		nots[uno - 1].push_back(dos);
		nots[dos - 1].push_back(uno);
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (options[i][j] != 0)
			{
				std::cout << options[i][j];
				for (int k = 0; k < nots[i].size(); k++)
				{
					options[nots[i][k] - 1][options[i][j] - 1] = 0;
				}
			}
		}
	}
}