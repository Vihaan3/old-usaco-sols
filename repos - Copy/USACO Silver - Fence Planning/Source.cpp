#include <iostream>
#include <fstream>
#include <vector>

std::vector <std::pair<int, int>> locs;
std::vector <std::vector<int>> adj;
std::vector <bool> visited;
int right = INT8_MIN;
int left = INT8_MAX;
int down = INT8_MIN;
int up = INT8_MAX;
int min = INT8_MAX;

void dfs(int s)
{
	if (visited[s])
	{
		min = std::min(min, 2 * (std::abs(right - left) + std::abs(down - up)));
		right = INT8_MIN;
		left = INT8_MAX;
		down = INT8_MIN;
		up = INT8_MAX;
		min = INT8_MAX;
		return;
	}
	visited[s] = true;
	//process node s
	left = std::min(left, locs[s].first);
	right = std::max(right, locs[s].first);
	up = std::min(up, locs[s].second);
	down = std::max(down, locs[s].second);
	//process all the nodes s is linked to
	for (auto u : adj[s])
	{
		dfs(u);
	}
}

int main()
{
	int n, m;
	std::ifstream fin("fenceplan.in");
	fin >> n >> m;
	locs = std::vector <std::pair<int, int>> (n);
	adj = std::vector <std::vector<int>>(n);
	visited = std::vector <bool>(n);
	for (int i = 0; i < n; i++)
	{
		fin >> locs[i].first >> locs[i].second;
	}
	for (int i = 0; i < n; i++)
	{
		int a;
		int b;
		fin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		if (!visited[n])
			dfs(i);
	}
	std::ofstream fout("fenceplan.out");
	fout << min;
}