#include <iostream>
int main ()
{
	int K, n;
	std::cin >> K >> n;
	for (int i = 0; i < n; i++)
	{
		int limit;
		std::cin >> limit;
		int loc = 1;
		int count = 0;
		int speed = 1;
		while (true)
		{
			if ((((speed + 2) * (speed + 1)) / 2) - ((limit + 1) * (limit) / 2) <= K - loc + 1)
			{
				speed++;

			}
			else if (((speed + 1) * (speed)) / 2 - ((limit + 1) * (limit) / 2) <= K - loc + 1)
			{
			}
			else
			{
				speed--;
			}
			loc += speed;
			count++;
			if (loc >= K)
				break;
		}

		std::cout << count + 1;
	}
}