#include <iostream>
#include <vector>

int check(std::vector <int> a, std::vector <int> b)
{
	int a_count = 0;
	int b_count = 0;

	for (int i = 0; i < 4; i++)
	{
		int count = 0;
		for (int j = 0; j < 4; j++)
		{
			if (a[i] > b[j])
				count++;
		}
		a_count += count;
	}

	for (int i = 0; i < 4; i++)
	{
		int count = 0;
		for (int j = 0; j < 4; j++)
		{
			if (b[i] > a[j])
				count++;
		}
		b_count += count;
	}
	if (a_count == b_count)
		return 0;
	else if (a_count > b_count)
		return 1;
	else if (b_count > a_count)
		return 2;
}


void solve()
{
	std::vector <int> a(4);
	std::vector <int> b(4);
	std::cin >> a[0] >> a[1] >> a[2] >> a[3];
	std::cin >> b[0] >> b[1] >> b[2] >> b[3];
	int checker = check(a, b);
	if (checker == 0)
	{
		std::cout << "no" << std::endl;
	}
	else
	{
		bool valid = false;
		for (int i = 1; i < 11; i++)
		{
			for (int j = 1; j < 11; j++)
			{
				for (int k = 1; k < 11; k++)
				{
					for (int l = 1; l < 11; l++)
					{
						std::vector <int> c;
						c.push_back(i);
						c.push_back(j);
						c.push_back(k);
						c.push_back(l);

						int checker1 = check(a, c);
						int checker2 = check(b, c);
						if (checker == 1)
						{
							if (checker1 == 2 && checker2 == 1)
							{
								valid = true;
							}
						}
						else if (checker == 2)
						{
							if (checker1 == 1 && checker2 == 2)
							{
								valid = true;
							}
						}
					}
				}
			}
		}
		if (valid)
		{
			std::cout << "yes" << std::endl;
		}
		else
		{
			std::cout << "no" << std::endl;
		}
	}

}


int main()
{
	int n;
	std::cin >> n;
	while (n--)
		solve();
}