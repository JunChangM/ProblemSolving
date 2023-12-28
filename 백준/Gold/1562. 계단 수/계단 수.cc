#include <iostream>
#define mod 1000000000
using namespace std;
int n, ans;
int dp[101][10][1024]; // dp[numLength][lastNumber][check]
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	int checkValue = (1 << 10) - 1;

	// zero is not start number ans set initial value of 1 ~ 9
	for (int i = 1; i <= 9; i++) {
		dp[1][i][1 << i] = 1;
	}

	// repeat by arriving n length
	for (int i = 2; i <= n; i++) {
		// repeat 0 ~ 9
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= checkValue; k++) {
				// 1. add 0 case : set last value 0 (dp second index) and update check to add 0
				if (j == 0) {
					dp[i][0][k | (1 << 0)] = (dp[i][0][k | (1 << 0)] + dp[i - 1][1][k]) % mod;
				}
				else if (j == 9) {
					dp[i][9][k | (1 << 9)] = (dp[i][9][k | (1 << 9)] + dp[i - 1][8][k]) % mod;
				}
				else {
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % mod;
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % mod;

				}
			}
		}
	}
	ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans = (ans + dp[n][i][checkValue]) % mod;
	}
		
	cout << ans;

	return 0;
}
