#include <iostream>
#include <vector>

int main()
{
	int n, q;
	std::cin >> n >> q;
	std::vector <std::vector<int>> v(n, std::vector <int> (n));
	std::vector <std::pair <std::pair<int, int>, std::pair<int, int>>> queries(q);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c;
			std::cin >> c;
			if (c == '*')
				v[i][j] = 1;
			else
				v[i][j] = 0;
		}
	}
	std::vector <std::vector<int>> prefix(n+1, std::vector <int> (n+1));
	for (int i = 1; i < n+1; i++)
	{
		for (int j = 1; j < n+1; j++)
		{
			prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + v[i-1][j-1];
		}
	}
	for (int i = 0; i < q; i++)
	{
		std::cin >> queries[i].first.second >> queries[i].first.first >> queries[i].second.second >> queries[i].second.first;
	}
	for (int i = 0; i < q; i++)
	{
		int A = queries[i].first.first;
		int B = queries[i].first.second;
		int a = queries[i].second.first;
		int b = queries[i].second.second;
		std::cout << prefix[A][B] - prefix[a - 1][B] - prefix[A][b - 1] + prefix[a - 1][b - 1] << std::endl;
	}
	
}