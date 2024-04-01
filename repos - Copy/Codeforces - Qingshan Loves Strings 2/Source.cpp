#include <iostream>
#include <vector>
#define string std::string

int main()
{
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		std::cin >> num;
		std::vector <int> build(num);
		for (int j = 0; j < num; j++)
		{
			int x;
			std::cin >> build[j];
		}
		int count = 0;
		int remove = 0;
		std::vector <int> out;
		for (int j = 0; j < build.size() && count < 300; j++)
		{
			if (build[j] != build[build.size() - 1])
			{
				build.pop_back();
				build.erase(build.begin());
				remove +=2;
			}
			else
			{
				count++;
				if (build[j] == 0)
				{
					build.push_back(0);
					build.push_back(1);
					out.push_back(build.size() + remove);
				}
				else
				{
					build.insert(build.begin(), 1);
					build.insert(build.begin(), 0);
					out.push_back(remove);
				}
			}

		}
		if (count == 300)
			std::cout << -1 << std::endl;
		else
		{
			std::cout << out.size() << std::endl;
			for (int j = 0; j < out.size(); j++)
			{
				if (j == out.size() - 1)
				{
					std::cout << out[j] << std::endl;
					break;
				}
				std::cout << out[j] << " ";
			}
		}
	}

}