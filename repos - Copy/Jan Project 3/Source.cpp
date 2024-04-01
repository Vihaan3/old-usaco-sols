#include <vector>
#include <iostream>
#define int long long

signed main()
{
	//THE MISTAKE MIGHT BE THE LOGICAL ERROR THAT YOU SHOULD FOLLOW THE FIRST INDEX INSTEAD OF WHATEVER THERE"S MORE OF
	int n;
	std::cin >> n;
	std::vector <int> pos(n);
	std::vector <int> be(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> pos[i];
		be[i] = i;
	}
	if (pos[0] < 0)
	{
		int thing = -1;
		for (int i = 0; i < n; i++)
		{
			be[i] = thing;
			thing--;
		}
	}
	if (pos[0] > 0)
	{
		int thing = 1;
		for (int i = 0; i < n; i++)
		{
			be[i] = thing;
			thing++;
		}
	}
	int update = 0;
	for (int i = 0; i < n; i++)
	{
		int difference = 0;
		if (pos[i] > be[i])
		{
			difference = -1;
		}
		else
		{
			difference = 1;
		}
		update += std::abs(pos[i] - be[i]);
		//LOGICAL ERROR COULD BE THAT DISTANCE SHOULD NOT = 2
		int distance = 2;
		for (int j = i + 1; j < n; j++)
		{
			// LOGICAL ERROR HERE COULD BE THE ISSUE
			pos[j] += distance * (difference * std::abs(pos[i] - be[i]));
			distance++;
		}
	}
	std::cout << update + 1;
}