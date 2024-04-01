#include <iostream>

int counter = 0;

void solver(int a, int b)
{
	if (a == b)
		return;
	if (a > b)
	{
		if (a % 2 == 0)
			a /= 2;
		else
			a++;
	}

	if (a < b)
	{
		if (b % 2 == 0)
			b /= 2;
		else
			b--;
	}

	counter++;
	solver(a, b);
}

void solve()
{
	int a;
	int b;
	std::cin >> a >> b;
	solver(a, b);
	std::cout << counter << std::endl;
	counter = 0;

}

int main()
{
	int n;
	std::cin >> n;
	while (n--)
	{
		solve();
	}
}