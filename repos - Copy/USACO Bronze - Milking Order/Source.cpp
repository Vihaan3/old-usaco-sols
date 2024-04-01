#include <iostream>
#include <vector>


int main()
{
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector <int> pos(n);

	std::vector <int> groups(m);
	for (int i = 0; i < m; i++)
	{
		std::cin >> groups[i];
	}
	for (int i = 0; i < k; i++)
	{
		int num, loc;
		std::cin >> num >> loc;
		pos[loc - 1] = num;
	}
	int place = -1;
	bool valid = true;
	while (valid)
	{
		std::vector <int> fake = pos;
		// PLACE??????????
		for (int i = place + 1; i < n; i++)
		{
			// THIS COULD BE THE PROBLEM
			if (fake[i] == 0)
			{
				fake[i] = 1;
				place = i + 1;
				break;
			}
		}
		for (int i = 0; i < m; i++)
		{

			bool val = true;
			for (int k = 0; k < n; k++)
			{
				if (fake[k] == groups[i])
				{
					// CHECK IF THIS BREAKS THRU THE WHOLE THING
					val = false;
					break;
				}
			}
			if (val)
			{
				for (int j = 0; j < n; j++)
				{
					if (fake[j] == 0)
					{
						// CHECK IF THIS BREAKS THRU THE WHOLE THING
						fake[j] = groups[i];
						break;
					}
				}
			}

		}
		int count = 0;
		for (int i = 0; i < m - 1; i++)
		{
			int first = 0;
			int second = 0;
			for (int j = 0; j < n; j++)
			{
				if (fake[j] == groups[i])
				{
					first = j;
				}

			}
			for (int j = 0; j < n; j++)
			{
				if (fake[j] == groups[i + 1])
				{
					second = j;
				}

			}
			
			if (second > first)
			{
				count++;
			}
			if (count == m - 1)
			{
				valid = false;
			}
		}
	}
	std::cout << place;
}