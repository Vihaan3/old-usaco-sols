#include <iostream>
#include <vector>
int main(void)
{
	long long n, k;
	std::cin >> n >> k;
	std::vector <long long> nums;
	for (long long i = 0; i < n; i++)
	{
		long long a;
		std::cin >> a;
		nums.push_back(a);

	}

	long long count = 0;
	bool group = false;
	std::vector <std::pair<long long, long long>> groups;
	std::pair <long long, long long> groupe;
	for (long long i = 0; i < n; i++)
	{
		if (i != nums.size() - 1)
		{
			if (nums[i + 1] - nums[i] <= k + 1)
			{
				if (group)
				{
					groupe.second = nums[i + 1];
				}
				else
				{
					group = true;
					groupe.first = nums[i];
					groupe.second = nums[i + 1];
				}
			}
			else
			{
				if (group)
				{
					group = false;
					groups.push_back(groupe);
				}
				count += k + 1;
			}
		}

		else
		{
			if (group)
			{
				groupe.second = nums[i];
				groups.push_back(groupe);
			}
			else
			{
				count += k + 1;
			}

		}

	}

	for (std::pair <long long, long long>groupes : groups)
	{
		count += groupes.second - groupes.first + 1 + k;
	}

	std::cout << count;
}
