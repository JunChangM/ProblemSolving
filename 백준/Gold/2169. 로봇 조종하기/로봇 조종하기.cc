#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int map[1000][1000];
int dp[1000][1000][3]; // 위, 왼, 오
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];
	dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = map[0][0];
	for (int i = 1; i < m; i++) {
		dp[0][i][0] = dp[0][i - 1][0] + map[0][i];
		dp[0][i][1] = dp[0][i][2] = dp[0][i][0];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) 
			dp[i][j][0] = max({ dp[i - 1][j][0], dp[i - 1][j][1], dp[i - 1][j][2] }) + map[i][j];
		dp[i][0][1] = dp[i][0][0];
		for (int j = 1; j < m; j++)
			dp[i][j][1] = max(dp[i][j - 1][1], dp[i][j - 1][0]) + map[i][j];
		dp[i][m - 1][2] = dp[i][m - 1][0];
		for(int j= m-2; j>=0; j--){
			dp[i][j][2] = max(dp[i][j + 1][2], dp[i][j + 1][0]) + map[i][j];
		}
	}
	cout << max({ dp[n - 1][m - 1][0], dp[n - 1][m - 1][1], dp[n - 1][m - 1][2] });
	return 0;
}	
