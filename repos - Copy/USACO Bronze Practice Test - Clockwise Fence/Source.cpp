#include <iostream>
#include <vector>
#include <unordered_map>
#define string std::string
#define umap std::unordered_map

int main()
{
	int num;
	std::cin >> num;
	for (int i = 0; i < num; i++)
	{
		string s;
		std::cin >> s;
		int left = 0;
		int right = 0;
		umap <char, char> cw = { {'N', 'E'}, {'E', 'S'}, {'S', 'W'}, {'W', 'N'}};
		umap <char, char> ccw = { {'N', 'W'}, {'E', 'N'}, {'S', 'E'}, {'W', 'S'} };
		for (int j = 0; j < s.size()-1; j++)
		{
			// IF DOESN' WORK JUST DO J++
			if (cw[s[j]] == s[j+1])
			{
				right++;
			}
			else if (ccw[s[j]] == s[j + 1])
			{
				left++;
			}
		}
		if (right < left)
			std::cout << "CCW" << std::endl;
		else
			std::cout << "CW" << std::endl;
	}
}