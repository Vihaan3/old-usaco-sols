#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

struct Mountain 
{
	int begin;
	int end;
};

bool operator < (const Mountain& m1, const Mountain& m2)
{
	if (m1.begin == m2.begin)
		return m1.end > m2.end;
	return m1.begin < m2.begin;
}

int main() {
	std::ifstream read("mountains.in");
	int mountain_num;
	read >> mountain_num;
	std::vector<Mountain> mountains (mountain_num);
	for (int i = 0; i < mountain_num; i++)
	{
		int x, y;
		read >> x >> y;
		mountains.push_back({ x - y, x + y });
	}

	std::sort(mountains.begin(), mountains.end());

	int rightmost = -1;
	int visible_num = 0;
	for (const Mountain& m : mountains) {
		if (m.end > rightmost) {
			visible_num++;
			rightmost = m.end;
		}
	}

	std::ofstream("mountains.out") << visible_num << std::endl;
}