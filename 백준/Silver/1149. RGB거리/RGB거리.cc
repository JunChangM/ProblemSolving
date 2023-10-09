#include <iostream>
#include <algorithm>
using namespace std;
int n, a, b, c;
int dp[1001][3]; // RR GG BB RG RB GR GB BR BG
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b >> c;
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + a;
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + b;
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + c;
	}
	cout << min({ dp[n][0],dp[n][1],dp[n][2] });

	return 0;
}
/*
RGB거리 (1149)
dp[i][j] : i번째에 j 색을 칠 할 때의 최소 비용
*/