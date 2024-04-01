#include <vector>
#include <iostream>
// THIS COULD BE THE PROBLEM IF IT DOESN"T SET THE VALUES PROPERLY
std::vector <std::vector<std::vector <int>>> locs(1000, std::vector <std::vector <int>>(1000));
std::vector <std::vector<int>> pos(1000, std::vector <int>(1000));
int num_comfy = 0;
// THIS COULD BE THE PROBLEM IF IT DOESN"T PASS BY REF CORRECTLY !!!!!!!!!!!!
void adj(int i, int x, int y, std::vector <int>& adjacent)
{
	if (x < 999)
	{
		locs[x + 1][y].push_back(i);
		if (pos[x + 1][y] == 1)
			adjacent[i]++;
	}
	if (x > 0)
	{
		locs[x - 1][y].push_back(i);
		if (pos[x - 1][y] == 1)
			adjacent[i]++;
	}
	if (y < 999)
	{
		locs[x][y + 1].push_back(i);
		if (pos[x][y+1] == 1)
			adjacent[i]++;
	}
	if (y > 0)
	{
		locs[x][y - 1].push_back(i);
		if (pos[x][y-1] == 1)
			adjacent[i]++;
	}
	if (adjacent[i] == 3)
		num_comfy++;
}

int main()
{
	int n;
	std::cin >> n;  
	std::vector <int> adjacent (n);
	
	for (int i = 0; i < n; i++)
	{
		int x, y;
		std::cin >> x >> y;
		adj(i, x, y, adjacent);
		for (int j = 0; j < locs[x][y].size(); j++)
		{
			adjacent[locs[x][y][j]]++;
			if (adjacent[locs[x][y][j]] == 3)
				num_comfy++;
			else if (adjacent[locs[x][y][j]] == 4)
				num_comfy--;

		}
		pos[x][y] = 1;
		std::cout << num_comfy << std::endl;
	}
}