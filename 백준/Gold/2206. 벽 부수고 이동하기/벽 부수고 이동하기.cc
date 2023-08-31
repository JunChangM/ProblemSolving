#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int map[1000][1000];
int visited[1000][1000][2];
int find() {
	queue<pair<int,pair<int,int>>> q;
	q.push({ 0,{ 0,0 } });
	visited[0][0][0] = 1;

	while (!q.empty()) {
		int block = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		if (x == n - 1 && y == m - 1) return visited[x][y][block];
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m ) continue;

			if (map[nx][ny] == 1 && block == 0) {
				visited[nx][ny][1] = visited[x][y][0] + 1;
				q.push({ 1,{nx,ny} });
			}
			else if (map[nx][ny] == 0 && visited[nx][ny][block] == 0) {
				visited[nx][ny][block] = visited[x][y][block] + 1;
				q.push({ block,{nx,ny} });
			}

		}
	}

	return -1;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j] - '0';
		}
	}

	cout << find();
	return 0;
}