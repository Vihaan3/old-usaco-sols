#include <iostream>
#include <vector>
#define string std::string
#include <algorithm>
int main()
{
	int num;
	std::cin >> num;
	std::vector <std::vector<int>> block_alpha;
	
	for (int j = 0; j < num; j++)
	{
		std::vector <int> trash;
		for (int i = 0; i < 26; i++)
		{
			trash.push_back(0);
		}
		block_alpha.push_back(trash);
	}
	for (int i = 0; i < num; i++)
	{
		string p, q;
		std::cin >> p;

		
		for (char c : p)
		{
			block_alpha[i][c - 'a']++;
		}

		std::cin >> q;
		std::vector <int> extras;
		for (char c : q)
		{
			if (block_alpha[i][c - 'a'] == 0)
			{
				block_alpha[i][c - 'a']++;
			}
			else
			{
				block_alpha[i][c - 'a'] = std::max(block_alpha[i][c - 'a'], std::count(q.begin(), q.end(), c));
			}
		}

	}
	

}
