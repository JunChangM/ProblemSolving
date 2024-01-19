#include <iostream>
using namespace std;
int n;
int dp[1001][2];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	dp[0][0] = 1;
	dp[1][0] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] % 10007 + dp[i - 1][1] % 10007;
		dp[i][1] = dp[i - 2][0] % 10007 + dp[i - 2][1] % 10007;
	}
	cout << (dp[n][0] % 10007 + dp[n][1] % 10007) % 10007;
	return 0;
}
/*
dp[i][0] : ㅣ 자로 끝나는 경우
dp[i][1] : = 자로 끝나는 경우
*/