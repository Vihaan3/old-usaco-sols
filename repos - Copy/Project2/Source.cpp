#include <iostream>
#include <unordered_map>

int main() {
    // List of numbers with one number repeated
    int numbers[] = { 1, 2, 3, 4, 5, 5 };
    int n = sizeof(numbers) / sizeof(int);

    // Use a hash table to store the frequency of each number
    std::unordered_map<int, int> frequency;
    for (int i = 0; i < n; i++) {
        frequency[numbers[i]]++;
    }
    std::cout << n << std::endl;
    // Iterate through the list and find the number that is repeated
    for (int i = 0; i < n; i++) {
        if (frequency[numbers[i]] > 1) {
            std::cout << "The number " << numbers[i] << " is repeated." << std::endl;
            return 0;
        }
    }

    std::cout << "No number is repeated." << std::endl;

    return 0;
}