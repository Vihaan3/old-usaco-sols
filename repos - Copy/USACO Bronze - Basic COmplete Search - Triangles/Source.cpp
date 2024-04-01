#include <iostream>
#include <vector>

int main()
{
	int num;
	std::cin >> num;
	std::vector< std::vector<int>> vertices;
	for (int i = 0; i < num; i++)
	{
		std::vector<int> v;
		int a, b;
		std::cin >> a >> b;
		v.push_back(a);
		v.push_back(b);
		vertices.push_back(v);
	}
	int area = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			for (int k = 0; k < num; k++)
			{
				if (i != j != k)
				{
					if (vertices[i][0] == vertices[j][0] && vertices[i][1] == vertices[k][1])
					{
						int min_area = std::abs(((vertices[i][1] - vertices[j][1]) * (vertices[i][0] - vertices[k][0])));
						area = std::max(area, min_area);
					}
					 
					else if (vertices[i][1] == vertices[j][1] && vertices[i][0] == vertices[k][0])
					{
						int min_area = std::abs(((vertices[i][0] - vertices[j][0]) * (vertices[i][1] - vertices[k][1])));
						area = std::max(area, min_area);
					}
				}
			}
			
		}
	}
	std::cout << area;
}