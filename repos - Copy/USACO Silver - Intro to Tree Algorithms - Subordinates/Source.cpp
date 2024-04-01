#include <iostream>
#include <vector>
std::vector <std::vector <int>> adj;
std::vector <int> subordinates;

void dfs(int s)
{
	for (auto u : adj[s])
	{
		dfs(u);
		subordinates[s] += subordinates[u];
	}
	
}

int main()
{
	int n;
	std::cin >> n;
	adj = std::vector<std::vector<int>>(n);
	subordinates = std::vector <int>(n);
	for (int i = 0; i < n-1; i++)
	{
		int a;
		std::cin >> a;
		adj[a-1].push_back(i);
	}
	dfs(0);
	for (int i = 0; i < n; i++)
		std::cout << subordinates[i] << " ";
}