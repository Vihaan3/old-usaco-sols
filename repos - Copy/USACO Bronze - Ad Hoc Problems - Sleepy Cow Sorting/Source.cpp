#include <iostream>
#include <vector>

int main ()
{
	int num;
	std::cin >> num;
	std::vector <int> cows;
	for (int i = 0; i < num; i++)
	{
		int n;
		std::cin >> n;
		cows.push_back(n);
	}
	int count = 1;
	int prev = 0;
	bool valid = true;
	for (int i = num-2; i >= 0 && valid == true; i--)
	{
		if (cows[i] > prev)
		{
			valid = false;
		}
		else
		{
			prev = cows[i];
			count++;
		}
	}
	std::cout << num - count;

}
