#include <iostream>
#include <vector>

int main()
{
	
	long long n = 0;
	long long k = 0;
	std::cin >> n >> k;
	std::vector <long long> days;
	for (long long i = 0; i < n; i++)
	{
		int j = 0;
		std::cin >> j;
		days.push_back(j);
	}

	
	long long counter1 = n*(k + 1);
	long long counter2 = ((days[days.size()-1]-days[0]) + 1)+k;

	if (counter1 < counter2)
		std::cout << counter1;
	else
		std::cout << counter2;






}