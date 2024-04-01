#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#define fin std::cin 
#define fout std::cout 
#define uset std::unordered_set
int main()
{	
	//std::ifstream fin("backforth.in");
	//std::ofstream fout("backforth.out");
	uset <int> barner1;
	uset<int> barner2;
	for (int i = 0; i < 10; i++)
	{
		int n;
		fin >> n;
		barner1.insert(n);
	}
	for (int i = 0; i < 10; i++)
	{
		int n;
		fin >> n;
		barner2.insert(n);
	}
	uset <int> poss;
	std::vector <int> barn1 (barner1.size());
	std::vector <int> barn2 (barner2.size());
	// CHECK IF THIS WORKS
	std::copy(barner1.begin(), barner1.end(), barn1.begin());
	std::copy(barner2.begin(), barner2.end(), barn2.begin());

	for (int i = 0; i < barn1.size(); i++)
	{
		int tuesday = 1000 - barn1[i];
		std::vector<int> tbarn1 = barn1;
		tbarn1.erase(tbarn1.begin()+i);
		std::vector <int> tbarn2 = barn2;
		tbarn2.push_back(barn1[i]);
		for (int j = 0; j < tbarn2.size(); j++)
		{
			int wednesday = tuesday + tbarn2[j];
			std::vector<int> wbarn2 = tbarn2;
			wbarn2.erase(wbarn2.begin() + j);
			std::vector <int> wbarn1 = tbarn1;
			wbarn1.push_back(tbarn2[j]);
			for (int k = 0; k < wbarn1.size(); k++)
			{
				int thursday = wednesday - wbarn1[k];
				std::vector<int> thbarn1 = wbarn1;
				thbarn1.erase(thbarn1.begin() + k);
				std::vector <int> thbarn2 = wbarn2;
				thbarn2.push_back(wbarn1[k]);

				for (int l = 0; l < thbarn2.size(); l++)
				{
					int friday = thursday + thbarn2[l];
					poss.insert(friday);
				}
			}
		}
	}
	fout << poss.size();
}
