#include <iostream>
#include <array>

int bin(std::array<int, 7> arr, int start, int end, int l)
{
	int mid = (start + end) / 2;

	if (arr[mid] == l)
	{
		return mid;
	}

	else
	{
		if (arr[mid]>l)
		{
			bin(arr, start, mid, l);
		}

		else
		{
			bin(arr, mid, end, l);
		}
	}
	
}

int main(void)
{
	std::array <int,7> arr = {1,2,3,7,9,10,13};
	int key = bin(arr, 0, 6, 1);
	std::cout << key << std::endl;
	
}