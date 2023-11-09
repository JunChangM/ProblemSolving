#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, ans;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int map[500][500];
int visited[500][500];
void dfs(int x, int y, int depth, int s) {
	if (depth == 4) {
		ans = ans > s ? ans : s;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; 
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (visited[nx][ny] == 0) {
			visited[nx][ny] = 1;
			dfs(nx, ny, depth + 1, s + map[nx][ny]);
			visited[nx][ny] = 0;
		}
	}
}
void shape1(int r, int c)
{
	int sum = 0;
	sum = map[r][c] + map[r][c + 1] + map[r][c + 2] + map[r - 1][c + 1];
	ans = max(ans, sum);
}

void shape2(int r, int c)
{
	int sum = 0;
	sum = map[r][c] + map[r][c + 1] + map[r][c + 2] + map[r + 1][c + 1];
	ans = max(ans, sum);
}

void shape3(int r, int c)
{
	int sum = 0;
	sum = map[r][c] + map[r + 1][c] + map[r + 2][c] + map[r + 1][c + 1];
	ans = max(ans, sum);
}

void shape4(int r, int c)
{
	int sum = 0;
	sum = map[r][c] + map[r - 1][c + 1] + map[r][c + 1] + map[r + 1][c + 1];
	ans = max(ans, sum);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 1;
			dfs(i, j, 1, map[i][j]);
			visited[i][j] = 0;
			if (i - 1 >= 0 && j + 2 < m) shape1(i, j);
			if (j + 2 < m && i + 1 < n) shape2(i, j);
			if (i + 2 < n && j + 1 < m) shape3(i, j);
			if (i + 1 < n && i - 1 >= 0 && j + 1 < m) shape4(i, j);
		}
	}

	cout << ans;
	return 0;
}
