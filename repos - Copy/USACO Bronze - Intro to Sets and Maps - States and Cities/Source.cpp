#include <iostream>
#include <map>
#include <vector>
#define umap map

using namespace std;

int main() {
	int N;
	std::cin >> N;

	vector<pair<string, string>> pairs;
	for (int i = 0; i < N; i++) {
		string city;
		string state;
		std::cin >> city >> state;
		city = city.substr(
			0, 2);  // We only care about the first two letters of the city
		pairs.push_back({ city, state });
	}

	map<string, int> seen;
	long long total = 0;
	for (pair [c, s] : pairs) {
		if (c != s) { total += seen[s + c]; }
		seen[c + s]++;
	}

	std::cout << total << endl;
}