#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define umap std::unordered_map
// this declaration might be the problem
int solver(umap<int, std::pair<int, char>> tree, std::string s, int x)
{
	int count = 0; 
	while (tree.count(x) != 0)
	{
		int prev = x;
		x = tree[x].first;
		if (s[x - 1] != tree[prev].second)
		{
			count++;
		}
	}
	return count;
}

void solve()
{
	int n;
	std::cin >> n;
	umap<int, std::pair <int, char>> tree;
	std::vector <int> leaves;
	std::string s;
	for (int i = 0; i < n; i++)
	{
		char c;
		std::cin >> c;
		s.push_back(c);
	}

	for (int i = 1; i < n+1; i++)
	{
		int l, r;
		std::cin >> l >> r;
		if (l != 0)
		{
			// THIS MIGHT THE PROBLEM
			tree[l] = std::make_pair(i, 'L');
		}
		if (r != 0)
		{
			tree[r] = std::make_pair(i, 'R');
		}
		if (l == 0 && r == 0)
		{
			leaves.push_back(i);
		}


	}

	int min = 1e8;
	// THIS MIGHT BE THE ERROR
	for (int x : leaves)
	{
		min = std::min(min, solver(tree, s, x));
	}
	std::cout << min << std::endl;
}


int main()
{
	int n;
	std::cin >> n;
	while (n--)
	{
		solve();
	}
}