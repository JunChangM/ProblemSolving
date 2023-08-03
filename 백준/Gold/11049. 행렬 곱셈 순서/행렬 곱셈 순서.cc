#include <iostream>
using namespace std;
int n, r, c;
int dp[501][501];
int map[501][2];// r c
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i][0] >> map[i][1];
	}
	for (int i = 0; i < n; i++) {
		dp[i][i] = 0;
		dp[i][i + 1] = map[i][0] * map[i][1] * map[i + 1][1];
	}
	for (int j = 2; j < n; j++) {
		for (int i = 0; i + j < n; i++) {
			int minvalue = 200000000;
			for (int k = i; k < i + j; k++) {
				int temp = dp[i][k] + dp[k + 1][i + j] + map[i][0] * map[k][1] * map[i + j][1];
				if (minvalue > temp) minvalue = temp;
			}
			dp[i][i + j] = minvalue;
		}
	}
	cout << dp[0][n - 1];
}