#include <iostream>
#define max(a, b) (a > b ? a : b)
using namespace std;
int n,m;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0,0,1,-1 };
int map[500][500];
int dp[500][500];
int dfs(int x, int y) {
	if (dp[x][y] != 0) return dp[x][y];
	dp[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (map[x][y] < map[nx][ny]) {
			dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
		}
	}
	return dp[x][y];
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> map[i][j];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) m = m > dfs(i, j) ? m : dfs(i, j);
	cout << m;
}
/*
정석적인 DP의 풀이이다.
최종적으로 도달한 지점의 값을 1로 잡고 반환되면서 1씩 증가하는 형태이다.
한번 방문했다면, 기록해둔 값을 반환한다.
*/
