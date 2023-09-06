#include <iostream>
using namespace std;
int n, m;
int dx[3] = { -1,0,1 };
int dy[3] = { 1,1,1 };
char input[10001][501];
bool dfs(int x, int y) {
	input[x][y] = 'x';
	if (y == m - 1) {
		return true;
	}
	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m || input[nx][ny] == 'x') continue;
		if (dfs(nx, ny)) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> input[i][j];
	int ans = 0;
	for (int i = 0; i < n; i++) if (dfs(i, 0)) ans++;
	cout << ans;
	return 0;
}