#include <iostream>
using namespace std;
int r, c, a;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visited[26];
char map[20][20];

void bfs(int x, int y, int depth) {
	a = depth > a ? depth : a;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
		if (visited[map[nx][ny] - 'A'] == 0) {
			visited[map[nx][ny] - 'A'] = 1;
			bfs(nx, ny, depth + 1);
			visited[map[nx][ny] - 'A'] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) cin >> map[i][j];
	visited[map[0][0] - 'A'] = 1;
	bfs(0, 0, 1);
	cout << a;
	return 0;
}
