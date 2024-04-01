#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	int n, cap;
	std::ifstream fin("word.in");
	fin >> n >> cap;
	std::vector<std::string> essay (n);
	for (int i = 0; i < n; i++)
	{
		fin >> essay[i];
	}
	int line = cap;
	std::string out = "";
	for (int i = 0; i < n; i++)
	{
		if (essay[i].size() <= line)
		{
			line -= essay[i].size();
			out += essay[i];
		}
		else
		{
			line = cap;
			out += "\n" + essay[i];
			line -= essay[i].size();
		}
		if (line == 0)
		{
			line = cap;
			out += "\n";
		}
		
	}
	std::ofstream fout("word.out");
	fout << out;
}