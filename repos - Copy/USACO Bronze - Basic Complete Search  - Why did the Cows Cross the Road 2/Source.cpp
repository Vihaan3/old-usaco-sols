#include <iostream>
#include <vector>
#define string std::string

int main()
{
	int num = 52;
	std::vector <char> alpha;
	for (int i = 0; i < num; i++)
	{
		char q;
		std::cin >> q;
		alpha.push_back(q);
	}
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::vector<std::pair<char, std::vector<int>>> cross_vec (26);
	 
	for (char c : alphabet)
	{
		cross_vec[c - 'A'].first = c;

	}
	for (char c : alphabet)
	{
		for (int i = 0; i < 52; i++)
		{
			if (alpha[i] == c)
			{
				cross_vec[c - 'A'].second.push_back(i);
			}
		}
	}
	int count = 0;
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (cross_vec[i].second[0] < cross_vec[j].second[0] && cross_vec[i].second[1] > cross_vec[j].second[0] && cross_vec[i].second[1] < cross_vec[j].second[1])
				count++;
		}
	}
	std::cout << count;
}
