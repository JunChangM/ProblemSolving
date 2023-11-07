#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
int n, m, ans;
int map[50][50];
int visit[50][50];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
void bfs() {

	int total_dist = 0;
	int dist[50][50] = { 0, };
	for (int i = 0; i < chicken.size(); i++) {
		queue<pair<int, int>> q;
		if (visit[chicken[i].first][chicken[i].second] == 0) continue;
		for (int j = 0; j < house.size(); j++) {
			int x = house[j].first;
			int y = house[j].second;
			if (dist[x][y] == 0) {
				dist[x][y] = abs(x - chicken[i].first) + abs(y- chicken[i].second);
			}
			else {
				dist[x][y] = min(dist[x][y],abs(x - chicken[i].first) + abs(y - chicken[i].second));
			}
		}
	}

	for (int j = 0; j < house.size(); j++) {
		int x = house[j].first;
		int y = house[j].second;
		total_dist += dist[x][y];
	}
	

	if (ans > total_dist) ans = total_dist;
}


void dfs(int depth, int cur) {
	if (depth == m) {
		bfs();
		return;
	}

	for (int i = cur; i < chicken.size(); i++) {
		int x = chicken[i].first;
		int y = chicken[i].second;
		if (visit[x][y] == 0) {
			visit[x][y] = 1;
			dfs(depth + 1, i + 1);
			visit[x][y] = 0;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) house.push_back({ i,j });
			else if (map[i][j] == 2) chicken.push_back({ i,j });
		}
	}

	ans = 200000000;
	dfs(0, 0);
	cout << ans;

	return 0;
}
