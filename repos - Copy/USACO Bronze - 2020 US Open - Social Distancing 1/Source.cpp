#include <iostream>
#include <fstream>
#include <vector>
//#define fin std::cin 
//#define fout std::cout
std::pair <int, int> gap(std::string s)
{
	int length = 0;
	std::pair <int, int> final;
	bool valid = false;
	std::pair<int, int> curr;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '0' && valid == false)
		{
			curr.first = i;
			valid = true;
		}

		if (s[i] == '1' && valid == true)
		{
			curr.second = i-1;
			valid = false;
			int size = curr.second - curr.first + 1;
			if (size > length)
			{
				length = size;
				final.first = curr.first;
				final.second = curr.second;
			}
		}
	}
	return final;
}

int main()
{
	int n;
	std::string s;
	std::ifstream fin("socdist1.in");
	std::ofstream fout("socdist1.out");
	fin >> n >> s;
	/*
	Cases:
	1. Both cows are in separate gaps (largest, left_most, or right_most)
		a. for each cow place it at the center of the largest gap, the left_most, or the right_most and find the lowest answer -> integer divide by 2
	2. Both cows are in the same gap
		a. place them both in the largest gap, with one 1/3 of the way and the other 2/3 of the way -> rounded division by 3 is answer

	Some kind of function that finds the lenght of the largest gap
	*/
	int min = 0;
	auto coord = gap(s);
	std::string copy = s;
	copy[((coord.second - coord.first + 1) / 2) + coord.first] = '1';
	min = ((coord.second - coord.first + 1) / 2);
	if ((coord.second - coord.first + 1) % 2 == 1)
	{
		min += 1;
	}
	auto coord2 = gap(copy);
	copy[((coord2.second - coord2.first + 1) / 2) + coord2.first] = '1';
	int place = (coord2.second - coord2.first + 1) / 2;
	if ((coord2.second - coord2.first + 1) % 2 == 1)
	{
		place += 1;
	}
	min = std::max(min, place);

	auto coord3 = gap(s);
	int doub = (coord3.second - coord3.first + 1) / 3;
	if ((coord3.second - coord3.first + 1) % 3 == 2)
	{
		doub += 1;
	}
	min = std::max(min, doub);
	fout << min;
}