#include <iostream>
#include <queue>
using namespace std;
int n, m, ans;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int map[9][9];
int submap[9][9];
queue<pair<int, int>> mainq;
int bfs() {
	int count = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) submap[i][j] = map[i][j];

	queue<pair<int, int>> q = mainq;
	queue<pair<int, int>> nq;
	while (!q.empty()) {
		nq = q;
		while (!q.empty()) q.pop();
		while (!nq.empty()) {
			int x = nq.front().first;
			int y = nq.front().second;
			nq.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m || submap[nx][ny] == 1 || submap[nx][ny] == 2) continue;
				submap[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		if (submap[i][j] == 0)  count++;

	return count;
}

void f(int depth) {
	if (depth == 3) {
		int temp = bfs();
		ans = ans > temp ? ans : temp;
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				f(depth + 1);
				map[i][j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) mainq.push({ i,j });
		}
	}
	f(0);
	cout << ans;
}