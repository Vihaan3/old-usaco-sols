#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

void solve()
{
	int n;
	std::cin >> n;
	std::unordered_map<int, std::vector<int>> mapper;
	for (int i = 0; i < n; i++)
	{
		int a;
		std::cin >> a;
		mapper[a].push_back(i);
	}

	std::vector <int> out;
	for (auto mappe : mapper)
	{
		if (mappe.second.size() >(n / 2))
		{
			out.push_back(mappe.first);
		}
		else
		{
			for (int i = 0; i < mappe.second.size()-1; i++)
			{
				if (mappe.second[i + 1] - mappe.second[i] <= 2)
				{
					out.push_back(mappe.first);
					break;
				}
			}
		}
	}	
	std::sort(out.begin(), out.end());
	if (out.size() > 0)
	{
		for (int i = 0; i < out.size(); i++)
		{
			if (i != out.size() - 1)
			{
				std::cout << out[i] << " ";
			}
			else
			{
				std::cout << out[i] << std::endl;
			}
		}
	}
	else
	{
		std::cout << -1 << std::endl;
	}
}

int main()
{
	int t;
	std::cin >> t;
	while (t--)
	{
		solve();
	}
}