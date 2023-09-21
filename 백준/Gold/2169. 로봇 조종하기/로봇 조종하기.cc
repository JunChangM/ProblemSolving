#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int map[1000][1000];
int dp[1000][1000]; // 위, 왼, 오
int temp[1000][2];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];
	dp[0][0] = map[0][0];
	for (int i = 1; i < m; i++) dp[0][i] = dp[0][i - 1] + map[0][i];
	for (int i = 1; i < n; i++) {
		temp[0][0] = dp[i - 1][0] + map[i][0];
		temp[m - 1][1] = dp[i - 1][m - 1] + map[i][m - 1];
		for (int j = 1; j < m; j++) 
			temp[j][0] = max(dp[i-1][j], temp[j-1][0]) + map[i][j]; // 왼 -> 오
		for(int j= m-2; j>=0; j--)
			temp[j][1] = max(dp[i-1][j], temp[j + 1][1]) + map[i][j];
		for (int j = 0; j < m; ++j) dp[i][j] = max(temp[j][0], temp[j][1]);
	}
	cout << dp[n - 1][m - 1];
	return 0;
}	
