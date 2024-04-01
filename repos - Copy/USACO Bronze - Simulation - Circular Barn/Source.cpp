#include <iostream>
#include <vector>

std::vector <int> cows;
int num;

int dist(int k)
{
	int sum = 0;
	for (int l = 0; l < num; l++)
	{
		sum += l * cows[(k + l) % num];
	}
	return sum;
}

int main()
{
	
	std::cin >> num;
	
	for (int i = 0; i < num; i++)
	{
		int n;
		std::cin >> n;
		cows.push_back(n);
	}
	int least = 100000000;
	for (int j = 0; j < num; j++)
	{
		least = std::min(dist(j), least);
	}

	std::cout << least;
}