#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#define out(x) std::cout << x
#define in(x) std::cin >> x
#define string std::string
#define vector std::vector

int search(int n, vector<int> v1)
{
	for (int i=0; i < v1.size(); i++)
	{
		if (v1[i] == n)
		{
			return i;
		}

	}

}

int main()
{
	int n;
	in(n);
	vector<int> v, v1;
	for (int i = 0; i < n; i++)
	{
		int k;
		in(k);
		v.push_back(k);
	}

	for (int j = 0; j < n; j++)
	{
		int l;
		in(l);
		v1.push_back(l);
	}

	for (int k = 0; k < n; k++)
	{
		int x = search(k+1, v);
		out(v1[x]);
		out(" ");
	
	}

}