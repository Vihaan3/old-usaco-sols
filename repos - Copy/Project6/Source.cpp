#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	
	int N;
	cin >> N;
	vector<int> degree(N);
	int a, b;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		degree[a - 1]++, degree[b - 1]++;
	}
	int result = 0;
	for (int i = 0; i < N; i++) result = max(result, degree[i]);
	cout << result + 1 << '\n';
}