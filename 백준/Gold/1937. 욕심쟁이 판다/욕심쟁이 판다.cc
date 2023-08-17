#include <iostream>
#include <queue>
using namespace std;
int n, ans;
int map[500][500];
int dp[500][500];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
priority_queue <pair<int, pair<int, int>>> q;
void  dfs() {
	
	while (!q.empty()) {
		int x = q.top().second.first;
		int y = q.top().second.second;
		int cur = q.top().first;
		q.pop();
		
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int next = map[nx][ny];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || next >= cur ) continue;
			dp[nx][ny] = max(dp[nx][ny], dp[x][y] + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> n ;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		cin >> map[i][j];
		q.push({ map[i][j],{i,j} });
	}
	dfs();
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		ans = dp[i][j] > ans ? dp[i][j] : ans;
	}
	cout << ans + 1;
}