#include <vector>
#include <iostream>
#include <string>
#define string std::string

std::vector <std::pair <int, string>> valid;

int main()
{
	std::pair <int, string> a;
	a.first = 0;
	a.second = "MOO";
	valid.push_back(a);
	a.first = 1;
	a.second = "MOM";
	valid.push_back(a);
	a.first = 1;
	a.second = "OOO";
	valid.push_back(a);
	a.first = 2;
	a.second = "OOM";
	valid.push_back(a);


	int num;
	std::cin >> num;

	for (int i = 0; i < num; i++)
	{
		string initial;
		std::cin >> initial;
		int changes = 0;
		int position = 0;
		bool left = false;
		for (std::pair <int, string> curr : valid)
		{
			string s = curr.second;
			size_t pos = initial.find(s);
			if (pos != string::npos)
			{
				position = pos;
				left = true;
				changes = curr.first;
				break;
			}
		}
		if (left == false)
		{
			std::cout << -1 << std::endl;
		}

		else
		{
			std::cout << position + (initial.length() - (position + 3)) + changes << std::endl;
		}

	}
}