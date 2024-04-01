#include <iostream>
#include <vector>

int main()
{
	long long n = 0;
	long long total = 0;
	long long count = 0;
	std::vector<long long> days, hays;
	std::cin >> n >> total;

	for (long long i = 0; i < n; i++)
	{
		long long l = 0;
		long long p = 0;
		std::cin >> l >> p;
		days.push_back(l);
		hays.push_back(p);
	}
	long long day_counter = 1;
	long long num = 0;
	for (long long k = 0; k < n; k++)
	{
		num = hays[k];
		if (days.size() > k+1)
		{
			long long rand = num - days[k + 1] - days[k] + 1;
			if (rand > 0)
			{
				count += days[k + 1] - days[k]+1;
				num = rand;
				
			}
			else
			{
				count += num;
				num = 0;
				
			}
			//for (long long j = day_counter; j < days[k+1]; j++)
			//{
				//day_counter++;
				//if (num > 0)
				//{
					//num--;
					//count++;
				//}
			//}
		}
		else if (days.size() == k + 1)
		{
			if (num < total - days[k])
				count += num;
			else
				count = total - days[k] + 1;
			//for (long long j = day_counter; j <= total; j++)
			//{
				//day_counter++;
				//if (num > 0)
				//{
					//num--;
					//count++;
				//}
			//}
		}

	}


	std::cout << count;



}