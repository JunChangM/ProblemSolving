#include <iostream>
#include <queue>
using namespace std;
int n, m, ans;
int map[500][500];
int dp[500][500];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void  dfs(int x, int y) {
	priority_queue <pair<int,pair<int, int>>> q;
	q.push({ map[x][y],{ x,y } });
	dp[x][y] = 1;
	while (!q.empty()) {
		x = q.top().second.first;
		y = q.top().second.second;
		int cur = q.top().first;
		q.pop();
		
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int next = map[nx][ny];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || next >= cur ) continue;

			if (dp[nx][ny] == 0) q.push({ next,{ nx,ny } });
			dp[nx][ny] += dp[x][y];
			
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];
	dfs(0, 0);
	cout << dp[n-1][m-1];
}