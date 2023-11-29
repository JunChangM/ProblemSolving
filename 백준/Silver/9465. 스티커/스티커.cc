#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int t, n, input[100001][2], dp[100001][2];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {

		cin >> n;
		for (int i = 1; i <= n; i++) cin >> input[i][0];
		for (int i = 1; i <= n; i++) cin >> input[i][1];
		
		dp[1][0] = input[1][0];
		dp[1][1] = input[1][1];
		dp[2][0] = input[2][0] + dp[1][1];
		dp[2][1] = input[2][1] + dp[1][0];
		for (int i = 3; i <= n; i++) {
			dp[i][0] = input[i][0] + max(dp[i - 1][1], dp[i - 2][1]);
			dp[i][1] = input[i][1] + max(dp[i - 1][0], dp[i - 2][0]);
		}

		cout << max({ dp[n - 1][0] , dp[n - 1][1], dp[n][0], dp[n][1] }) << "\n";
	}
	return 0;
}
