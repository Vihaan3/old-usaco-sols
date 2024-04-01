#include <iostream>
#include <vector>

int main()
{
	std::vector<std::pair<int, int>> white (4);
	std::vector<std::pair<int, int>> black1(4);
	std::vector<std::pair<int, int>> black2(4);
	std::cin >> white[0].first >> white[0].second >> white[2].first >> white[2].second;
	std::cin >> black1[0].first >> black1[0].second >> black1[2].first >> black1[2].second;
	std::cin >> black2[0].first >> black2[0].second >> black2[2].first >> black2[2].second;

	white[1].first = white[0].first;
	white[1].second = white[2].second;
	white[3].first = white[2].first;
	white[3].second = white[0].second;

	black1[1].first = black1[0].first;
	black1[1].second = black1[2].second;
	black1[3].first = black1[2].first;
	black1[3].second = black1[0].second;

	black2[1].first = black2[0].first;
	black2[1].second = black2[2].second;
	black2[3].first = black2[2].first;
	black2[3].second = black2[0].second;

	if (black1[0].first <= white[0].first && black1[2].first >= white[2].first && black1[0].second <= white[0].second && black1[2].second >= white[2].second)
	{
		std::cout << "NO" << std::endl;
		return 0;
	
	}
	if (black2[0].first <= white[0].first && black2[2].first >= white[2].first && black2[0].second <= white[0].second && black2[2].second >= white[2].second)
	{
		std::cout << "NO" << std::endl;
		return 0;
	}

	if (black1[0].first <= white[0].first && black1[2].first >= white[2].first && black1[2].second > white[0].second)
	{
		white[0].second = black1[2].second;
	}
	if (black1[2].first <= white[2].first && black1[2].first >= white[2].first && black1[0].second > white[0].second)
	{
		white[2].second = black1[2].second;
	}
	
	if (black1[0].second <= white[0].second && black1[2].second >= white[2].second && black1[0].first < white[0].first)
	{
		white[0].first = black1[2].first;
	}
	if (black1[0].second <= white[0].second && black1[2].second >= white[2].second && black1[2].first > white[2].first)
	{
		white[2].first = black1[2].first;
	}
	
	
	if (black2[0].first <= white[0].first && black2[2].first >= white[2].first && black2[2].second > white[0].second)
	{
		white[0].second = black2[2].second;
	}

	if (black2[2].first <= white[2].first && black2[2].first >= white[2].first && black2[0].second > white[0].second)
	{
		white[2].second = black2[2].second;
	}

	if (black2[0].second <= white[0].second && black2[2].second >= white[2].second && black2[0].first < white[0].first)
	{
		white[0].first = black2[0].first;
	}
	if (black2[0].second <= white[0].second && black2[2].second >= white[2].second && black2[2].first > white[2].first)
	{
		white[2].first = black2[0].first;
	}



	if (white[0].first < white[2].first || white[0].second < white[2].second)
	{
		std::cout << "Yes" << std::endl;
	}
	else
	{
		std::cout << "NO" << std::endl;
	}






















}


