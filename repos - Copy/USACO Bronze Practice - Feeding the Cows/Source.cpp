#include <iostream>
#include <vector>

#define string std::string

int main()
{
	int num;
	std::cin >> num;
	while (num--)
	{
		int n, k;
		string locs;
		std::cin >> n >> k >> locs;
		string out(n, '.');
		int h = 0;
		int g = 0;
		int patches = 0;
		for (int i = 0; i < n; i++)
		{
			if (locs[i] == 'H')
			{
				if (h + k < i || h == 0)
				{
					if (i + k < n)
					{
						h = i + k;
						if (out[h] == 'G')
						{
							h--;
						}
						out[h] = 'H';
					}
					else
					{
						h = i;
						if (out[h] == 'G')
							h--;
						out[h] = 'H';
					}
					patches++;
				}

			}
			else
			{
				if (g + k < i || g == 0)
				{
					if (i + k < n)
					{
						g = i + k;
						if (out[g] == 'H')
						{
							g--;
						}
						out[g] = 'G';
					}
					else
					{
						g = i;
						if (out[g] == 'H')
							g--;
						out[g] = 'G';
					}
					patches++;
				}
			}

		}
		std::cout << patches << std::endl << out << std::endl;
	}
}