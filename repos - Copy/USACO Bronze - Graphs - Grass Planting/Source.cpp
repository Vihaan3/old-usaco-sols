#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
	int num;
	std::cin >> num;
	std::unordered_map <int, int> field (num);
	for (int i = 0; i < num - 1; i++)
	{
		int p, q;
		std::cin >> p >> q;
		field[p]++;
		field[q]++;
	}
	int abs = 0;
	for (int i = 0; i < num; i++)
	{
		abs = std::max(field[i], abs);
	}
	std::cout << abs + 1;
}
