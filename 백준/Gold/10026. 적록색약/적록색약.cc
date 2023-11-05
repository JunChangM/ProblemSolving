#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, r, g, b;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char map[100][100];
char map2[100][100];
void bfs(int x, int y) {
	char standard = map[x][y];
	if (standard == 'R') r++;
	else if (standard == 'B') b++;
	else g++;

	map[x][y] = '0';
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (map[nx][ny] == standard) {
				map[nx][ny] = '0';
				q.push({ nx,ny });
			}
		}
	}
}

void bfs2(int x, int y) {

	g++;
	map[x][y] = 'B';

	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (map2[nx][ny] != 'B') {
				map2[nx][ny] = 'B';
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			map2[i][j] = map[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != '0') {
				bfs(i, j);
			}
		}
	}

	r = r + g + b;
	g = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map2[i][j] != 'B') {
				bfs2(i, j);
			}
		}
	}



	cout << r << ' ' << g + b;
	return 0;
}