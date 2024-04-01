#include <iostream>
#include <fstream>
#include <vector>
#define fin std::cin 
#define fout std::cout

int main()
{
	int n;
	fin >> n;
	std::vector <int> hoof (n+1);
	std::vector <int> paper(n + 1);
	std::vector <int> scissors(n + 1);

	for (int i = 1; i < n + 1; i++)
	{
		char c;
		std::cin >> c;
		if (c == 'S')
		{
			scissors[i] += scissors[i - 1] + 1;
			hoof[i] += hoof[i-1];
			paper[i] += paper[i - 1];
		}
		else if (c == 'H')
		{
			scissors[i] += scissors[i - 1];
			hoof[i] += hoof[i - 1] + 1;
			paper[i] += paper[i - 1];
		}
		else
		{
			scissors[i] += scissors[i - 1];
			hoof[i] += hoof[i - 1];
			paper[i] += paper[i - 1] + 1;
		}
	}

	int max = std::max(hoof[n], paper[n], scissors[n]);

	for (int i = 1; i < n + 1; i++)
	{
		max = std::max(paper[n - 1] + hoof[n] - hoof[i - 1], 
			  std::max(scissors[n - 1] + hoof[n] - hoof[i - 1],
					   paper[n - 1] + scissors[n] - scissors[i - 1],
					   hoof[n - 1] + paper[n] - paper[i - 1]),
		      std::max(hoof[n - 1] + scissors[n] - scissors[i - 1],
					   scissors[n - 1] + paper[n] - paper[i - 1]));
	}

	fout << max;
}