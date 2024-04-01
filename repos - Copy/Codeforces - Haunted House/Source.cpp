#include <iostream>
#define string std::string

void bit(int i, string number)
{
	int place = number.length() - 1 - i;
	int zero = 0;
	int count = 0;
	int ones = 0;
	int sum_ones = 0;
	int sum_zeros = 0;
	int num_zeros = 0;
	for (int j = 0; j < number.length()-1; j++)
	{
		char c = number[j];
		if (c == '0')
		{
			zero++;
		}
		//might have to be just greater than 
		if (count >= place)
		{
			if (c == '1')
			{
				ones++;
				sum_ones += count;
			}
		}
		// might have to put count at the beginning
		count++;
	}
	
	if (i > zero)
	{
		std::cout << -1;
	}
	
	else
	{	
		for (int j = place; j > 0; j--)
		{
			if (number[j] == '0')
			{
				num_zeros++;
				sum_zeros += j;
				if (num_zeros == ones)
				{
					break;
				}
			}
		}

		std::cout << sum_ones - sum_zeros << " ";
	}
}

void solve()
{
	int num;
	string s;
	std::cin >> num >> s;
	for (int i = 0; i < num; i++)
	{
		bit(i + 1, s);
	}
	std::cout << std::endl;
}

int main(void)
{
	int num;
	std::cin >> num;
	for (int i = 0; i < num; i++)
	{
		solve();
	}
}