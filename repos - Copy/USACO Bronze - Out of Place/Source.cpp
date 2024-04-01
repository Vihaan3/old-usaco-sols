#include <iostream>
#include <fstream>
#include <vector>


int main(void)
{
    int n;
    std::ifstream fin("outofplace.in");
    fin >> n;
    std::vector <int> cow(n);
    for (int i = 0; i < n; i++)
    {
        fin >> cow[i];
    }
    int prev = cow[0];
    int bessie = 0; 
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        if (cow[i] < prev)
        {
            bessie = cow[i];
            end = i;
            break;
        }
        else
            prev = cow[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (bessie < cow[i])
        {
            start = i;
            break;
        }
    }
    prev = cow[start];
    int swaps = 0;
    for (int i = start; i < end; i++)
    {
        if (cow[i] != prev)
        {
            swaps++;
            prev = cow[i];
        }
    }
    std::ofstream fout("outofplace.out");
    
    fout << swaps + 1 << "\n";
    return 0;
}
