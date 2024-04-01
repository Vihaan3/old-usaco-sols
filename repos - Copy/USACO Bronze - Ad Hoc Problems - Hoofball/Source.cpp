#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main(void)
{
    int n;
    int balls = 0;
    std::ifstream fin("hoofball.in");
    std::ofstream fout("hoofball.out");
    fin >> n;
    //std::cin >> n;
    std::vector <int> cows(n);
    
    for (int i = 0; i < n; i++)
    {
        fin >> cows[i];
        //std::cin >> cows[i];
    }
    std::sort(cows.begin(), cows.end());

    std::unordered_map <int, std::vector<int>> locs;

    locs[cows[1]].push_back(cows[0]);
    locs[cows[n-2]].push_back(cows[n-1]);

    for (int i = 1; i < n - 1; i++)
    {
        if (cows[i] - cows[i - 1] <= cows[i + 1] - cows[i])
        {
            locs[cows[i - 1]].push_back(cows[i]);
        }
        else
        {
            locs[cows[i + 1]].push_back(cows[i]);
        }
    }
    
    for (int i = 0 ; i < n; i++)
    {
        if (locs.count(cows[i]) == 0 || locs[cows[i]].size() == 0)
        {
            balls++;
        }
        else
        {
            if (locs[cows[i]].size() == 1 && locs[locs[cows[i]][0]].size() == 1 && locs[locs[cows[i]][0]][0] == cows[i])
            {
                balls++;
            }
        }
    }

    fout << balls << "\n";
    //std::cout << balls;
    return 0;
}
