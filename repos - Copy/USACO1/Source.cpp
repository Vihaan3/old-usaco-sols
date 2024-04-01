#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>


int main()
{
	char q;
	int n=0, g_num=0, h_num=0, q2=0;
	std::cin >> n; 
	std::vector<std::string> cows;
	std::vector<int> nums;
	for (int i = 0; i < n; i++)
	{
		std::cin >> q;
		std::string str(1, q);
		if (str == "H")
			h_num++;
		else
			g_num++;
		cows.push_back(str);
	}

	for (int j = 0; j < n; j++)
	{
		std::cin >> q2;
		nums.push_back(q2);
	}

	std::vector<std::vector<std::string>> all;
	
	for (int k=0; k < n; k++)
	{
		std::vector <std::string> temp;
		std::copy(cows.begin() + k, cows.begin() + nums[k], std::back_inserter(temp));
		all.push_back(temp);
	}
	std::vector<int> g_leaders;
	std::vector <int> h_leaders;
	for (int l=0; l < n; l++)
	{
		int g_count = std::count(all[l].begin(), all[l].end(), "G");
		int h_count = std::count(all[l].begin(), all[l].end(), "H");
		if (all[l][0] == "G")
		{
			if (g_count == g_num)
				g_leaders.push_back(l);
		}
		else
		{
			if (h_count == h_num)
			{
				h_leaders.push_back(l);
			}
		}
	}

	for (int m=0; m < g_leaders.size(); m++)
		cows[g_leaders[m]] = "GL";

	for (int n=0; n < h_leaders.size(); n++)
		cows[h_leaders[n]] = "HL";


	std::vector<std::vector<std::string>> all2;

	for (int o=0; o < n; o++)
	{
		std::vector <std::string> temp;
		std::copy(cows.begin() + o, cows.begin() + nums[o], std::back_inserter(temp));
		all2.push_back(temp);
	}
	std::vector<int> g_leaders2;
	std::vector <int> h_leaders2;
	for (int p=0; p < n; p++)
	{
		int g_count = std::count(all2[p].begin(), all[p].end(), "GL");
		int h_count = std::count(all2[p].begin(), all[p].end(), "HL");
		if (h_count >= 1)
			g_leaders2.push_back(p);
		else if (g_count >= 1)
			h_leaders2.push_back(p);
	}

	int final_count=0;
	for (int r=0; r < g_leaders2.size(); r++)
	{
		final_count += h_leaders.size();
	}
	for (int s=0; s < h_leaders2.size(); s++)
	{
		final_count += g_leaders.size();
	}
	for (int t=0; t < g_leaders.size(); t++)
	{
		final_count += h_leaders.size();
	}
	for (int u=0; u < h_leaders.size(); u++)
	{
		final_count += g_leaders.size();
	}

	std::cout << final_count;
}