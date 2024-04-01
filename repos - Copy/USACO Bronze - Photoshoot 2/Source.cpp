#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
	int n;
	std::cin >> n;
	std::vector <int> a (n);
	std::vector <int> b(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		std::cin >> b[i];
	}
	std::unordered_map <int, int> replace(n);
	for (int i = 0; i < n; i++)
	{
		replace[b[i]] = i;
		b[i] = i;
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = replace[a[i]];
	}

	int max = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (max > a[i])
		{
			count++;
		}
		else
		{
			max = a[i];
		}
	}
	std::cout << count;
	
}