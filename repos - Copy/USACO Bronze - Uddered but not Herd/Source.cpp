#include <iostream>
#include <vector>
#define string std::string

int main()
{
	string alpha;
	string heard;
	std::cin >> alpha >> heard;
	int count = 0;
	int heard_num = 0;
	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] == heard[heard_num])
		{
			heard_num++;
		}

		if (i == 25)
		{
			i = -1;
			count++;
		}

		if (heard_num == heard.size())
			break;
	}
	std::cout << count + 1;
}