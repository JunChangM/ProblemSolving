#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, e, a, b, c, d;
int dist[801];
vector<pair<int,int>> map[801];
void dijk(int start) {
	for (int i = 1; i <= n; i++) dist[i] = 8000000;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	dist[start] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < cost) continue;
		for (int i = 0; i < map[cur].size(); i++) {
			int ncost = map[cur][i].second + cost;
			int next = map[cur][i].first;
			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ -ncost,next });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		map[a].push_back({ b,c });
		map[b].push_back({ a,c });
	}
	cin >> a >> b;
	dijk(1);
	if (dist[n] == 8000000) cout << -1;
	else {
		c = dist[a];
		d = dist[b];
		dijk(a);
		c += dist[b];
		d += dist[n];
		dijk(b);
		c += dist[n];
		d += dist[a];

		cout << (c > d ? d : c);
	}
	return 0;
}
/*
특별한 최단 경로(1504)
- 무방향 그래프 ( 1 --> N번 정점까지의 최단 거리 )
- 임의의 정점은 반드시 통과
- 이동했던 정점 다시 갈 수 있음
- 음수 간선 없음
=> 다익스트라
*/