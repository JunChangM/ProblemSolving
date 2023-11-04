#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001][1001];
string x, y;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> x >> y;


	for (int i = 1; i <= x.length(); i++) {
		for (int j = 1; j <= y.length(); j++) {
			if (x.at(i - 1) == y.at(j - 1)) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}


	cout << dp[x.length()][y.length()];

	return 0;
}