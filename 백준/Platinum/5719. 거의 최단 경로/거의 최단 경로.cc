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
		//dist [d]가 되는 값을 dfs에서 찾기에는 비용이 너무 많이 걸림
		// dist[d] 기준으로 반대로 접근하였을 때, dist[x] = dist[d] - cost 라면 최단 경로에 포함된다.
		// 반대 방향에 대한 배열도 필요?
		// 지나온 길 제거해주고 dijk() 하면 dist[d]가 답.
		bfs();
		dijk();

		if (dist[d] == INF) cout << "-1\n";
		else cout << dist[d] << "\n";
	}
	return 0;
}

/*
2 1
1 0
0 1 5
2 2
1 0
0 1 5
1 0 5*/