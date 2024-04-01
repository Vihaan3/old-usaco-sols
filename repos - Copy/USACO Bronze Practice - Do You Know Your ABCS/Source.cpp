#include <vector>
#include <iostream>
#include <algorithm>

int main(void)
{
	std::vector <int> nums(7);
	for (int i = 0; i < 7; i++)
		std::cin >> nums[i];
	std::sort(nums.begin(), nums.end());
	int num = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = i; j < 7; j++)
		{
			for (int k = j; k < 7; k++)
			{
				if (nums[i] + nums[j] + nums[k] == nums[6])
				{
					a = nums[i];
					b = nums[j];
					c = nums[k];
				}
			}
		}
	}
	std::cout << a << " " << b << " " << c;
}