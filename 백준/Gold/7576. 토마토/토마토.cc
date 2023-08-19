#include <iostream>
#include <queue>
using namespace std;
int n, m, day;
int dx[4] = { 1, -1, 0,0 };
int dy[4] = { 0,0,1,-1 };
int map[1000][1000];
queue <pair<int, int>> tomato;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j]; // 1 익은 토마토, 0 안익은 토마토, -1 비어있음
			if (map[i][j] == 1) tomato.push({ i,j });
		}
	}
	day = 0;
	queue<pair<int, int>> q;
	while (!tomato.empty()) {
		q = tomato;
		day++;
		while (!tomato.empty()) tomato.pop();

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
				if (map[nx][ny] == 0) {
					map[nx][ny] = 1;
					tomato.push({ nx,ny });
				}
			}
		}
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << day - 1;
	return 0;
}