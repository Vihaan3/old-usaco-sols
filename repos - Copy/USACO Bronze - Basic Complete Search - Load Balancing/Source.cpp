#include <iostream>
#include <vector>
std::vector <std::pair<int, int>> inter_pos;
std::vector <std::pair<int, int>> real_pos;
int num, b;
int q1, q2, q3, q4 = 0;

void locate(std::pair <int, int> inner, std::pair <int, int> pos)
{
	if (inner.first > pos.first && inner.second > pos.second)
	{
		q1++;
	}
	if (inner.first < pos.first && inner.second > pos.second)
	{
		q2++;
	}
	if (inner.first < pos.first && inner.second < pos.second)
	{
		q3++;
	}
	if (inner.first > pos.first && inner.second < pos.second)
	{
		q4++;
	}

}

int main()
{
	
	std::cin >> num >> b;
	for (int i = 0; i < num; i++)
	{
		int n, q;
		std::cin >> n >> q;
		std::pair <int, int> chicken, quack;
		chicken.first = n+1;
		chicken.second = q+1;
		quack.first = n;
		quack.second = q;
		real_pos.push_back(quack);
		inter_pos.push_back(chicken);
	}
	int min = 1000000000;
	
	for (std::pair <int, int> pos : inter_pos)
	{

		for (std::pair <int, int> sub_pos : real_pos)
		{
			locate(sub_pos, pos);
		}
		int max1 = std::max(q1, q2);
		int max2 = std::max(q3, q4);
		int max = std::max(max1,max2);
		min = std::min(min, max);
		q1 = 0;
		q2 = 0;
		q3 = 0;
		q4 = 0;
	}
	std::cout << min;
}
