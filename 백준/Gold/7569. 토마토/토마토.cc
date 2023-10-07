#include <iostream>
#include <queue>
using namespace std;
int n, m, h, ans;
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int map[100][100][100];
queue < pair<int, pair<int, int>>> q;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) for (int j = 0; j < n; j++) for (int k = 0; k < m; k++) {
		cin >> map[i][j][k];
		if (map[i][j][k] == 1) q.push({ i,{j,k} });
	}
	
	while (!q.empty()) {
		int z = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;
			if (map[nz][nx][ny] == 0) {
				map[nz][nx][ny] = map[z][x][y] + 1;
				q.push({ nz,{nx,ny} });
			}
		}
	}
	int flag = 0;
	for (int i = 0; i < h; i++){
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (map[i][j][k] == 0) {
					flag = 1;
					ans = 0;
					break;
				}
				if (map[i][j][k] > ans) ans = map[i][j][k];
			}
			if (flag) break;
		}
		if (flag) break;
	}
	cout << --ans;
	return 0;
}
