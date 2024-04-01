#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#define string std::string
std::unordered_map <char, std::unordered_set <int>> pos;
void solve()
{
	string s;
	std::cin >> s;
	std::vector <int> nums (4);
	bool valid = true;
	for (char c : s)
	{
		if (pos.count(c) == 0)
		{
			valid = false;
		}
		for (int value : pos[c])
		{
			nums[value]++;
		}
		
	}
	int count = 0;
	for (int i = 0; i < 4 && valid; i++)
	{
		if (nums[i] > 0)
			count++;
	}
	if (count >= s.length())
	{
		std::cout << "YES" << std::endl;
	}
	else
		std::cout << "NO" << std::endl;
}

int main()
{
	int n; 
	std::cin >> n;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
            char a;
			std::cin >> a;
			pos[a].insert(i);
		}
	}
	while (n--)
	{
		solve();
	}

}