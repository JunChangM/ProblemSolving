#include <iostream>
using namespace std;
int n;
int dp[1001][2];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> dp[i][0];
		int m = 0;
		for (int j = 1; j < i; j++) {
			if (dp[j][0] < dp[i][0] && m < dp[j][1]) m = dp[j][1];
		}
		dp[i][1] = m + 1;
	}

	int ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i][1]);
	}
	cout << ans;
	return 0;
}
