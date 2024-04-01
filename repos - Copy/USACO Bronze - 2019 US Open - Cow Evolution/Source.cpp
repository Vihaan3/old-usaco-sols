#include <iostream>
#include <fstream>
#include <vector>
#define string std::string

int main()
{
	int n;
	std::ifstream fin("evolution.in");
	std::ofstream fout("evolution.out");
	fin >> n;
	std::vector <std::vector<string>> leaves (n);
	std::vector <std::vector<int>> available(n);
	for (int i = 0; i < n; i++)
	{
		int k;
		fin >> k;
		available[i] = std::vector <int>(k);
		for (int j = 0; j < k; j++)
		{
			string s;
			fin >> s;
			leaves[i].push_back(s);
		}
	}
	
	bool valid = true;
	for (int i = 0; i < n; i++)
	{
		if (leaves[i].size() != 0)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (leaves[j].size() != 0)
				{
					bool valid3 = true;
					for (int k = 0; k < available[i].size(); k++)
					{
						bool valid2 = false;
						for (int l = 0; l < available[j].size(); l++)
						{
							if (leaves[i][k] == leaves[j][l])
								valid2 = true;
						}
						if (!valid2)
						{
							valid3 = false;
							break;
						}
						
					}
					if (valid3)
					{
						available[j][available[i].size() - 1]++;
					}
					
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < available[i].size(); j++)
		{
			if (available[i][j] > 1)
			{
				valid = false;
			}
		}
	}

	if (valid)
		fout << "yes";
	else
		fout << "no";
}