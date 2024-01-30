#include <iostream>
#include <queue>
using namespace std;
int n, m;
int map[1000][1000];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> q;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				q.push({ i,j });
			}
		}
	}

	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];

			if (nx < 0 || ny < 0 || nx > n || ny > m) continue;

			if (map[nx][ny] == 1) {
				map[nx][ny] = map[curx][cury] + 1;
				q.push({ nx,ny });
			}

		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) cout << map[i][j] << ' ';
			else cout << map[i][j] - 2 << ' ';
		}
		cout << '\n';
	}

	return 0;
}

