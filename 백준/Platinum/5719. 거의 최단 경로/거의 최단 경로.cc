#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 2147483647
using namespace std;
int n, m, s, d, u, v, p;
vector<pair<int, int>> input[501];
vector<pair<int, int>> rev[501];
int dist[501];
int matrix[501][501]; // matrix 가  0 이면 그냥 진행 1이면 제외
priority_queue<pair<int, int>> pq;

void dijk() {
	vector<int> move;
	// 0부턴데 왜 1부터 초기화를 했니...
	for (int i = 0; i <= n; i++) {
		dist[i] = INF;
	}
	dist[s] = 0;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < input[cur].size(); i++) {
			int ncost = -input[cur][i].first;
			int next = input[cur][i].second;
			if (matrix[cur][next] == 1) continue;
			if (dist[next] > cost + ncost) {
				dist[next] = cost + ncost;
				pq.push({ -dist[next],next });
			}
		}
	}
}

void bfs() {
	queue<int> q;
	q.push(d);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		
		for (int i = 0; i < rev[x].size(); i++) {
			if (matrix[rev[x][i].second][x] == 0 && dist[rev[x][i].second] == dist[x] - rev[x][i].first) {
				matrix[rev[x][i].second][x] = 1;
				q.push(rev[x][i].second);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		cin >> s >> d;
		
		for (int i = 0; i <= n; i++) {
			input[i].clear();
			rev[i].clear();
		}
		memset(matrix, 0, sizeof(matrix));

		for (int i = 0; i < m; i++) {
			cin >> u >> v >> p;
			input[u].push_back({ -p, v });
			rev[v].push_back({ p,u });
		}
		dijk();
		bfs();
		dijk();

		if (dist[d] == INF) cout << "-1\n";
		else cout << dist[d] << "\n";
	}
	return 0;
}

