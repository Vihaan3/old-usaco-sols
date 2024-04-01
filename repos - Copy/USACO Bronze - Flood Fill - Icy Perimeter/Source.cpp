#include <iostream>
#include <vector>
#include <fstream>


const int MAX_N = 1000;
int grid[MAX_N][MAX_N];  
int row_num;
int col_num;

bool visited[MAX_N][MAX_N];  
int curr_size = 0;      
int perim_size = 0;

void floodfill(int r, int c, int color) 
{
	if ((r < 0 || r >= row_num || c < 0 || c >= col_num) || grid[r][c] != color)
	{
		perim_size++;
		return;
	}
	if (visited[r][c])
	{
		return;
	}
	visited[r][c] = true;  
	curr_size++;           

	floodfill(r, c + 1, color);
	floodfill(r, c - 1, color);
	floodfill(r - 1, c, color);
	floodfill(r + 1, c, color);

}

int main() 
{	
	std::ifstream fin ("perimeter.in");
	int n;
	fin >> n;
	row_num = n;
	col_num = n;
	for (int i = 0; i < row_num; i++) 
	{
		std::string s;
		fin >> s;
		for (int j = 0; j < col_num; j++) 
		{
			if (s[j] == '#')
				grid[i][j] = 1;
			else
				grid[i][j] = 0;
		}
	}
	std::vector<std::pair<int, int>> ap;
	for (int i = 0; i < row_num; i++) 
	{
		for (int j = 0; j < col_num; j++) 
		{
			if (!visited[i][j] && grid[i][j] == 1)
			{
				curr_size = 0;
				perim_size = 0;
				floodfill(i, j, grid[i][j]);
				ap.push_back(std::make_pair(curr_size, perim_size));
			}
		}
	}
	std::pair<int, int> max = std::make_pair(0, 0);
	for (auto a : ap) 
	{
		if (a.first > max.first)
			max = a;
		else if ((a.first == max.first) && (a.second < max.second))
		{
			max = a;
		}
	}
	std::ofstream fout("perimeter.out");
	fout << max.first << " " << max.second;
}
