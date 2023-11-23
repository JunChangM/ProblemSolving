#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int i, j;
string a, b;
int dp[1001][1001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b;

	for (i = 1; i <= a.size(); i++) {
		for (j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	i = a.size(), j = b.size();
	string ans = "";
	while (i >= 1 && j >= 1) {
		if (dp[i][j] == dp[i - 1][j]) {
			i--;
		}
		else if (dp[i][j] == dp[i][j - 1]) {
			j--;
		}
		else {
			ans += a[i - 1];
			i--;
			j--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << dp[a.size()][b.size()] << '\n' << ans;



	return 0;
}
