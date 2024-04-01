#include <iostream>
#include <vector>
/*
	Can find the minimum number of days needed, just can't find how to convert that into minimum 
	in general. Also remember to account for edge cases in finding min in general. 
*/
int main()
{
	int n;
	std::string s;
	std::cin >> n >> s;
	bool section = false;
	int min = 1e8;
	int count = 0;
	std::vector <int> sects;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '0' && count > 0)
		{
			sects.push_back(count);
			count = 0;
		}
		if (s[i] == '1')
			count++;
	}
	if (count > 0)
		sects.push_back(count);
	if (sects.size() == 0)
	{
		std::cout << 0;
		return 1;
	}
	bool leftzero = s[0] == '0';
	bool rightzero = s[n - 1] == '0';
	int max_days = std::min(sects[0], sects[sects.size()-1])-1;
	if (leftzero)
		max_days = std::min(max_days, (sects[0] - 1) / 2);
	if (rightzero)
		max_days = std::min(max_days, (sects[sects.size() - 1] - 1) / 2);
	int sick = 0;
	for (int day: sects)
	{
		max_days = std::min(max_days, (day-1)/2);
	}

	for (int day : sects)
	{
		sick += day/(2 * max_days + 1);
		if (day % (2 * max_days + 1) != 0)
		{
			sick++;
		}
	}
	std::cout << sick;
}