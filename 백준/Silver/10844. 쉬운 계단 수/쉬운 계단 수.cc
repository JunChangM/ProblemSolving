#include <iostream>
using namespace std;
int n;
long long ans, a, b, dp[10];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= 9; i++) dp[i] = 1;
	for (int i = 2; i <= n; i++) {
		long long dp1 = dp[1];
		long long dp8 = dp[8];
		b = dp[0];
		for (int k = 1; k <= 8; k++) {
			a = dp[k];
			dp[k] = (b + dp[k + 1]) % 1000000000;
			b = a;
		}
		dp[0] = dp1;
		dp[9] = dp8;
	}
	for (int k = 0; k <= 9; k++) {
		ans += dp[k];
		ans %= 1000000000;
	}
	cout << ans  % 1000000000;
	return 0;
}