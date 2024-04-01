#include <iostream>
#include <vector>

int main()
{
	int num;
	std::cin >> num;
	std::vector <std::string> type;
	std::vector <int> start, stop;
	for (int i = 0; i < num; i++)
	{
		std::string a;
		int b, c;
		std::cin >> a >> b >> c;
		type.push_back(a);
		start.push_back(b);
		stop.push_back(c);
	}
	const int upper = 900000000;
	const int lower = -900000000;
	int up = upper;
	int low = lower;
	for (int i = num - 1; i > -1; i--)
	{
		if (type[i] == "none")
		{
			up = std::min(stop[i], up);
			low = std::max(start[i], low);
		}

		else if (type[i] == "on")
		{
			up -= stop[i];
			low -= start[i];
		}
		else
		{
			up += stop[i];
			low += start[i];
		}

	}

	std::cout << low << " " << up << std::endl;
	up = upper;
	low = lower;
	
	for (int i = 0; i < num; i++)
	{
		if (type[i] == "none")
		{
			up = std::min(stop[i], up);
			low = std::max(start[i], low);
		}

		else if (type[i] == "on")
		{
			up += stop[i];
			low += start[i];
		}
		else
		{
			up -= stop[i];
			low -= start[i];
		}

	}
	std::cout << low << " " << up << std::endl;
}
