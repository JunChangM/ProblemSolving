#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, num, ans;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int map[100][100];
int parent[102];
vector < pair<int, pair<int, int>>> bridge;

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

bool uni(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return false;

	if (x < y) parent[x] = y;
	else parent[y] = x;
	return true;
}

void findisland(int x, int y) {
	queue<pair<int,int>> q;
	q.push({ x,y });
	map[x][y] = num;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == 1) {
				map[nx][ny] = num;
				q.push({ nx,ny });
			}
		}
	}
}

void caldist(int x, int y) {
	int start = map[x][y];
	for (int i = 0; i < 4; i++) {
		bool outOfBound = 0;
		int nx = x + dx[i];
		int ny = y + dy[i];
		while (map[nx][ny] == 0) {
			nx += dx[i];
			ny += dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
				outOfBound = 1;
				break;
			}
		}
		if (outOfBound == 0 && map[nx][ny] != start) {
			int dist = max(abs(nx - x), abs(ny - y)) - 1;
			if (dist >= 2) {
				bridge.push_back({ dist,{start,map[nx][ny]} });
			}
		}


	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// 1. input
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	// 2. seperate same island
	num = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				findisland(i, j);
				num++;
			}
		}
	}

	// 3. calculate the dist of each island
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0) {
				caldist(i, j);
			}
		}
	}

	// 4. parent initialization
	for (int i = 2; i < num; i++) parent[i] = i;

	// 5. MST
	sort(bridge.begin(), bridge.end());
	n = 0; num -= 2;
	for (int i = 0; i < bridge.size(); i++) {
		int s = bridge[i].second.first;
		int e = bridge[i].second.second;

		if (uni(s, e)) {
			ans += bridge[i].first;
			if (++n == num - 1) break;
		}
	}

	if (n != num - 1) ans = -1;

	cout << ans;
	return 0;
}