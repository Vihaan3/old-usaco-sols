#include <iostream>
#include <string>
#include <vector>

int main() {
	int cow_num;
	std::string str;
	std::cin >> cow_num >> str;

	std::vector <int> pairs;
	int count = 0;
	for (int i = 0; i < cow_num; i+=2)
	{
		
		if (str.substr(i, 2) == "GH")
		{
			if (pairs.size() > 0)
			{
				if (pairs[count - 1] != 1)
				{
					pairs.push_back(1);
					count++;
				}
			}
			else
			{
				pairs.push_back(1);
				count++;
			}
		}
		else if (str.substr(i, 2) == "HG")
		{
			if (pairs.size() > 0)
			{
				if (pairs[count - 1] != 0)
				{
					pairs.push_back(0);
					count++;
				}
			}
			
			else
			{
				pairs.push_back(0);
				count++;
			}
			
		}
	}
	int final = 0;
	if (pairs[pairs.size()-1] == 0)
	{
		final -= 1;
	}

	std::cout << final + pairs.size();
}