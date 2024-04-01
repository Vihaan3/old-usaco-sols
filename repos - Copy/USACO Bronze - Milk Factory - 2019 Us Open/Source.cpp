#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::ifstream fin("factory.in");
	std::ofstream fout("factory.out");
	int n; 
	fin >> n;
	std::vector <int> grap (n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		fin >> a >> b;
		grap[a-1]++;
	}
	int count = 0;
	int loc = 0;
	for (int i = 0; i < n; i++)
	{
		if (grap[i] == 0)
		{
			loc = i+1;
			count++;
		}
	}
	if (count > 1)
		fout << -1;
	else if (count == 0)
		fout << 1;
	else if (count == 1)
		fout << loc;
}