#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define  umap std::unordered_map 

int main()
{
	umap <std::string, std::vector <int>> traits;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		std::cin >> k;
		for (int j = 0; j < k; j++)
		{
			std::string charac;
			std::cin >> charac;
			traits[charac].push_back(i);
		}
	}
	for (auto& pair : traits) {
		std::sort(pair.second.begin(), pair.second.end());
	}
	// if doesn't work, check if the populations are sorted
	bool valid = true;
	for (auto trait : traits)
	{
		for (auto trait1 : traits)
		{		
			int length = std::max(traits[trait.first].size(), traits[trait1.first].size());

			for (int k = 0; k < length; k++)
			{
				int sims = 0;
				int diff = 0;
				if (k == traits[trait.first].size() || traits[trait1.first].size())
				{
					break;
				}

				else
				{
					if (traits[trait.first][k] == traits[trait1.first][k])
					{
						sims++;
					}
					else
					{
						diff++;
					}

					if (diff > 1 && sims > 1)
					{
						valid = false;
						break;
					}
				}
			}
		}
		
	}
	if (valid)
	{
		std::cout << "yes";
	}
	else
	{
		std::cout << "no";
	}
		

}