#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int t, h;
int dx[8] = { 1,-1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,1,-1 };

int map[51][51];


void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	map[x][y] = 0;

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= t || ny >= h) continue;
			if (map[nx][ny] == 1) {
				map[nx][ny] = 0;
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (cin >> h >> t) {
		if (t == 0 && h == 0) break;
		memset(map, 0, sizeof(map));
		int ans = 0;

		for (int i = 0; i < t; i++) {
			for (int j = 0; j < h; j++) {
				cin >> map[i][j];
			}
		}
		
		for (int i = 0; i < t; i++) {
			for (int j = 0; j < h; j++) {
				if (map[i][j] == 1) {
					ans++;
					bfs(i, j);
				}
			}
		}
		
		cout << ans << '\n';
	}
	return 0;
}
