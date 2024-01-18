#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int n, m, a, b, s;
vector<int> v[1001];
int visited[1001];

void dfs(int x) {
	visited[x] = 1;
	cout << x << ' ';
	for (int i = 0; i < v[x].size(); i++) {
		if (visited[v[x][i]] == 0) {
			dfs(v[x][i]);
		}
	}
}

void bfs(int x) {
	memset(visited, 0, sizeof(visited));
	visited[x] = 1;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int cur = q.front();
		cout << cur << ' ';
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (visited[next] == 0) {
				visited[next] = 1;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= 1000; i++) {
		sort(v[i].begin(), v[i].end());
	}


	dfs(s);
	cout << '\n';
	
	bfs(s);

	return 0;
}
