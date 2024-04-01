#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

void solve()
{
	int num;
	std::cin >> num;
	std::vector <int> nums (num);
	for (int i = 0; i < num; i++)
	{
		std::cin >> nums[i];
	}
	int max = -1e18;
	// THIS COULD BE THE PROBLEM!!! TRY NUM/2 +1!!!!! 
	for (int i = 1; i < num/2 + 1; i++)
	{
		if (num % i == 0)
		{
			std::vector <int> sum1;
			std::vector <int> sum2;
			int count = 0;
			int counter = 0;
			for (int j = 0; j < num; j++)
			{
				count += nums[j];
				if ((j + 1) % i == 0)
				{
					sum1.push_back(count);
					count = 0;
				}
			}

			for (int j = 0; j < num; j++)
			{
				counter += nums[j];
				if ((j + 1) % (num / i) == 0)
				{
					sum2.push_back(counter);
					counter = 0;
				}

			}
			std::sort(sum1.begin(), sum1.end());
			std::sort(sum2.begin(), sum2.end());
			max = std::max(max, sum1[sum1.size()-1] - sum1[0]);
			max = std::max (max, sum2[sum2.size() - 1] - sum2[0]);
		}
	}
	int test = 0;
	max = std::max(max, test);
	std::cout << max << std::endl;
}

signed main()
{
	int num;
	std::cin >> num;
	while (num--)
	{
		solve();
	}
}