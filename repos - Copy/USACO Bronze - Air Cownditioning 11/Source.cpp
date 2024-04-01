#include <vector>
#include <iostream>
#include <algorithm>
std::vector<int> temps(101);
std::vector <int> money(10);
std::vector <std::pair<int, int>> ranges(10);
std::vector <int> cool (10);

int n, m;
int min = 1000000;
void check(std::vector <int> select)
{
	std::vector <int> test(101);
	int cost = 0;
	for (int i = 0; i < m; i++)
	{
		if (select[i] == 1)
		{
			for (int j = ranges[i].first; j < ranges[i].second + 1; j++)
			{
				test[j] += cool[i];
			}
			cost += money[i];
		}
	}
	bool valid = true;
	for (int i = 1; i < 101; i++)
	{
		if (test[i] < temps[i])
		{
			valid = false;
			break;
		}
	}
	if (valid)
		min = std::min(min, cost);

}

void build(std::vector <int> select)
{
	if (select.size() == m)
	{
		check(select);
	}
	else
	{
		select.push_back(1);
		build(select);
		select.pop_back();
		select.push_back(0);
		build(select);

	}
}
int main()
{
	
	std::cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int a, b, t;
		std::cin >> a >> b >> t;
		for (int j = a; j < b+1; j++)
		{
			temps[j] = t;
		}
	}
	for (int i = 0; i < m; i++)
	{
		std::cin >> ranges[i].first >> ranges[i].second >> cool[i] >> money[i];
	}
	std::vector<int> select;
	build(select);
	std::cout << min;
}