
#include <iostream>
#include <vector>

int main()
{
	int num;
	std::cin >> num;
	for (int i = 0; i < num; i++)
	{
		int N, M;
		std::cin >> N >> M;
		std::vector <std::vector<std::pair<int, int>>> test (M, std::vector <std::pair<int, int>> (N));
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < N; k++)
			{
				char a;
				std::pair<int, int> x;
				std::cin >> a;
				if (a == '0')
					x.first = 0;
				else
					x.first = 1;
				x.second = 0;
				test[j][k] = x;
			}
			int out;
			std::cin >> out;
			for (int k = 0; k < N; k++)
			{
				test[j][k].second = out;
			}
		}
		bool valid = true;
		for (int k = 0; k < N; k++)
		{
			std::pair <int, bool> zero;
			std::pair <int, bool> one;
			bool filled_zero = false;
			bool filled_one = false;

			for (int j = 0; j < M; j++)
			{

				if (test[j][k].first == 0)
				{
					if (!filled_zero)
					{
						zero.first = test[j][k].second;
						zero.second = true;
						filled_zero = true;
					}
					else
					{
						if (zero.second == true)
						{
							if (test[j][k].second != zero.first)
							{
								zero.second = false;
							}
						}
					}
				}
				if (test[j][k].first == 1)
				{
					if (!filled_one)
					{
						one.first = test[j][k].second;
						one.second = true;
						filled_one = true;
					}
					else
					{
						if (one.second == true)
						{
							if (test[j][k].second != one.first)
							{
								one.second = false;
							}
						}
					}
				}


			}
			if (zero.second)
			{
				for (int j = 0; j < M; j++)
				{
					if (test[j][k].first == 0)
					{
						test.erase(test.begin() + j);
						M--;
						j--;
					}
					
				}
			}
			if (one.second)
			{
				for (int j = 0; j < M; j++)
				{
					if (test[j][k].first == 1)
					{
						test.erase(test.begin() + j);
						M--;
						j--;
					}
					
				}
				
			}
			
		}
		if (test.size() > 1)
			std::cout << "LIE" << std::endl;
		else
			std::cout << "OK" << std::endl;
	}
}