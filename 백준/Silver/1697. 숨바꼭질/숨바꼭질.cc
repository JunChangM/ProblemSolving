#include <iostream>
#include <algorithm>
using namespace std;
int n,k;
int dp[100001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	if (n >= k) cout << n - k;
	else { // n < k
		for (int i = n - 1; i > 0; i--) dp[i] = dp[i + 1] + 1;
		for (int i = n + 1; i <= 100000; i++) {
			if (i % 2 == 0) {
				dp[i] = min(dp[i / 2] + 1, dp[i - 1] + 1);
				int j = i - 1;
				while (j > 0 && dp[i] < dp[j] - 1) {
					dp[j] = dp[j + 1] + 1;
					j--;
				}
			}
			else dp[i] = dp[i - 1] + 1;
		}
		cout << dp[k];
	}
	return 0;
}