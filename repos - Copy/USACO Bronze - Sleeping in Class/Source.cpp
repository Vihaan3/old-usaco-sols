#include <iostream>
#include <vector>
/*
*  Find the max of the array as you take in input
*  Loop thru the array once
*		for each element in the array
*			if it is less than the max, add it to the next index, and make the current index -1, and increment a counter
*			max = std::max (max, current);
*  int prev = -1;
*  Loop thru the array again
*		if the element is not -1
*			if prev == -1, prev = this element
			seperate counter variable++;
*			if the element is not equal to prev, valid = false
*  If !valid
*		first_counter += seperate counter -1;
*/
void solve()
{
	int n; 
	std::cin >> n;
	std::vector <int> pos(n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		std::cin >> pos[i];
		sum += pos[i];
	}
	int value = 0;
	for (int i = n; i > 0; i--)
	{
		if (sum % i == 0)
		{
			int curr_sum = 0;
			for (int j = 0; j < n; j++)
			{
				if (curr_sum < sum/i)
				{
					if (curr_sum + pos[j] > sum/i)
					{
						break;
					}
					else
						curr_sum += pos[j];
				}
				if (curr_sum == sum/i)
				{
					curr_sum = 0;

					if (j == n - 1)
					{
						value = std::max(value, i);
						break;
					}
				}

			}
		}
	}
	std::cout << n-value << std::endl;
}

int main()
{
	int T;
	std::cin >> T;
	while (T--)
	{
		solve();
	}
}