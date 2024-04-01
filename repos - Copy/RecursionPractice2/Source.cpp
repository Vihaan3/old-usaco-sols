#include <iostream>
#include <vector>

std::vector<int> flip(std::vector<int> coins, int n, int count)
{
    // add base case to stop the recursion
    if (count > n)
        return coins;

    else
    {
        // fix the loop to iterate over all n elements
        for (int i = 0; i < count; i++)
        {
            if (coins[i] == 0)
                coins[i] = 1;
            else
                coins[i] = 0;
        }

        // increment the count before the recursive call
        count++;
        return flip(coins, n, count);
    }
}

int main()
{
    std::vector<int> coins = { 1,1,1,1,1 };
    int n = coins.size();
    coins = flip(coins, n, 1);
    // fix the loop to iterate over all n elements
    for (int i = 0; i < n; i++)
        std::cout << coins[i] << ",";
}