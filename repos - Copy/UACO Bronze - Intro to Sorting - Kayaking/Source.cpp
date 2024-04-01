#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> kayakers;
    for (int i = 0; i < 2 * n; i++) {
        int a;
        std::cin >> a;
        kayakers.push_back(a);
    }

    // Sort the kayakers in non-decreasing order of their weights.
    std::sort(kayakers.begin(), kayakers.end());

    int minimum = 100000000;

    // Consider all possible pairs for single kayaks.
    for (int i = 0; i < 2 * n; i++) {
        for (int j = i + 1; j < 2 * n; j++) {
            int tandem_instability = 0;
            std::vector<int> yakers;

            // Create a new vector excluding the two kayakers at indices i and j.
            for (int k = 0; k < 2 * n; k++) {
                if (k != i && k != j) {
                    yakers.push_back(kayakers[k]);
                }
            }

            // Calculate instability of the tandems.
            for (int k = 1; k < 2 * n - 2; k += 2) {
                tandem_instability += yakers[k] - yakers[k - 1];
            }

            // Update the minimum total instability.
            minimum = std::min(minimum, tandem_instability);
        }
    }

    std::cout << minimum;
}