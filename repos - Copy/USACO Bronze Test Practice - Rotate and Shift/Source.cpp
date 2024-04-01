#include <iostream>
#include <vector>
//.first = k, .second = n
std::pair <std::vector <int>, std::vector <int>> solve(std::pair <std::vector <int>, std::vector <int>> track)
{
	std::vector <int> tracker = track.second;
	for (int i = track.first.size()-1; i >=0; i--)
	{
		if (i == track.first.size() - 1)
		{
			track.second[track.first[0]] = tracker[track.first[i]];
		}
		else
		{
			track.second[track.first[i + 1]] = tracker[track.first[i]];
		}
	}
	for (int i = 0; i < track.first.size(); i++)
	{
		if (track.first[i] == track.second.size() - 1)
		{
			track.first[i] = 0;
		}
		else
		{
			track.first[i]++;
		}
	}
	return track;
}

int main()
{ 
	int n, k, t;
	std::cin >> n >> k >> t;
	std::vector <std::vector<int>> repeats (2 * n);
	std::pair<std::vector <int>, std::vector <int>> track;
	for (int i = 0; i < k; i++)
	{
		int a;
		std::cin >> a;
		track.first.push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		track.second.push_back(i);
	}
	for (int i = 0; i < n * 2; i++)
	{
		track = solve(track);
		repeats[i] = track.second;
	}

	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
		{
			std::cout << repeats[((t - 1) % (2 * n))][i];
		}
		else
			std::cout << repeats[((t - 1) % (2*n))][i] << " ";
	}
}