#include <iostream>
#include <vector>
#include <unordered_map>

int together_tracker = 0;
int up = 49;
int down = 49;
int max = 1000;
std::vector<bool> space[100][100];


void movement(std::string key, int value)
{
	if (key == "N")
	{
		for (int i = 0; i < value; i++)
		{
					
		}
	}

}

int main()
{
	int num;
	std::cin >> num;
	std::unordered_map <std::string, int> move;
	int up_down, int left_right;
	for (int i = 0; i < num; i++)
	{
		std::string s;
		int k;
		std::cin >> s >> k;
		if (s == "E" || s == "W")
		{
			left_right+= k;
		}
		else
		{
			up_down+= k;
		}
		move[s] = k;
	}
	int counter = 1000;
	for (const auto& pair : move) 
	{
		const std::string& key = pair.first;
		const int& value = pair.second;
		movement(key, value);
	}

	if (together_tracker == 0)
	{
		std::cout << -1;
	}
	else
	{
		std::cout << max;
	}


}