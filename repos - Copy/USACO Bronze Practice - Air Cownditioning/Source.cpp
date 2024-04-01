#include <iostream>
#include <vector>
/*
While thinking of the solution maybe look at each individual one
*/

int sgn(int n)
{
	if (n > 0)
	{
		return 1;
	}
	else if (n < 0)
	{
		return -1;
	}
	return 0;
}

int main()
{
	int n;
	std::cin >> n;
	std::vector <int> a(n);
	std::vector <int> b(n);
	std::vector <int> diff(n);
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		std::cin >> b[i];
		diff[i] = a[i] - b[i];
	}

	while (true)
	{
		int first = 0;
		int zero = 0;
		bool change = false;
		for (int j = 0; j < n; j++)
		{

			if (diff[j] != 0)
			{
				first = j;
				change = true;
				break;
			}
			else
			{
				zero++;
			}
		}
		if (zero == n)
		{
			break;
		}
		
		int end = 0;
		for (int j = first; j < n && change; j++)
		{
			if (sgn(diff[j]) != sgn(diff[first]))
			{
				// ERROR COULD BE THIS
				end = j;
				break;
			}
			if (j == n - 1)
			{
				end = n;
			}
		}
		bool valid = false;
		for (int j = first; j < end && change; j++)
		{
			
			if (sgn(diff[first]) == 1)
			{
				diff[j]--;
				valid = true;
			}
			else if (sgn(diff[first]) == -1)
			{
				diff[j]++;
				valid = true;
			}
		}
		if (valid)
			count++;
	}
	std::cout << count;
}