#include <vector>
#include <iostream>

int A1, A2, B1, B2, K, num;
std::vector <std::vector <int>> track;

int next_pos(int curr, int i);

int next_pos(int curr, int i)
{
	if (curr >= A1 && curr <= A2)
	{
		curr = A1 + A2 - curr;
	}
	if (curr >= B1 && curr <= B2)
	{
		curr = B1 + B2 - curr;
	}
	track[i].push_back(curr);
	return curr;
}

int main()
{
	std::cin >> num >> K >> A1 >> A2 >> B1 >> B2;
	std::vector <int> before_out (num);
	std::vector <int> out(num);
	std::vector <int> blank;
	for (int i = 0; i < num; i++)
	{
		track.push_back(blank);
	}

	for (int i = 1; i < num+1; i++)
	{
		int curr = 0;
		int prev = 0;
		int k = 0;
		while (curr != i)
		{
			if (prev == 0)
			{
				curr = i;
				prev++;
			}
			curr = next_pos(curr, i-1);
			k++;
		}
		k = K % k;
		before_out[i-1] = track[i-1][k];
	}
	for (int i = 0; i < num; i++)
	{
		out[before_out[i]-1] = i + 1;
	}
	for (int i = 0; i < num; i++)
	{
		std::cout << out[i] << std::endl;
	}
}