#include <iostream>
#include <algorithm>
using namespace std;
int input[501][501];
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i  + 1; j++) {
			cin >> input[i][j];
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0) {
				input[i][j] += input[i - 1][j];
			}
			else if (j == i) {
				input[i][j] += input[i - 1][j - 1];
			}
			else {
				input[i][j] += max(input[i - 1][j - 1], input[i - 1][j]);
			}
		}
	}
	int answer = -1;
	for (int i = 0; i < n + 1; i++) {
		if (answer < input[n - 1][i]) answer = input[n - 1][i];
	}
	cout << answer;
}