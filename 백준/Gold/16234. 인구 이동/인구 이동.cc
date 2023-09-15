#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
int n, l, r, day, flag;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int map[51][51];
bool visited[51][51];
int bfs(int x, int y) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;
	v.push_back({ x,y });
	q.push({ x,y });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		int start = map[x][y];
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			int value = abs(start - map[nx][ny]);
			if (visited[nx][ny] == 0 && value >= l && value <= r) {
				visited[nx][ny] = 1;
				q.push({ nx,ny });
				v.push_back({ nx,ny });
			}
		}
	}

	if (v.size() > 1) {
		int s = 0;
		for (int i = 0; i < v.size(); i++) {
			s += map[v[i].first][v[i].second];
		}
		s /= v.size();
		for (int i = 0; i < v.size(); i++) {
			map[v[i].first][v[i].second] = s;
		}
		return 1;
	}
	return 0;
}
void search() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				visited[i][j] = 1;
				if (bfs(i, j) == 1) {
					flag = 0;
				}
				
			}
		}
	}
	if (flag == 0) day++;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> map[i][j];

	while (flag == 0) {
		flag = 1;
		search();
		memset(visited, 0, sizeof(visited));
	}
	
	cout << day;
	return 0;
}	
