#include <iostream>
#include <vector>
#include <queue>
#define INF 200000000
using namespace std;
int n, m, a, b, c;
vector<pair<int, int>> map[50001];
int dist[50001];
void dijk(int x) {
	for (int i = 1; i <= n; i++) dist[i] = INF;
	priority_queue<pair<int, int>> q;
	q.push({ 0,x });
	dist[x] = 0;
	while (!q.empty()) {
		int cost = -q.top().first;
		int cur = q.top().second;
		q.pop();
		if (dist[cur] < cost) continue;
		for (int i = 0; i < map[cur].size(); i++) {
			int next = map[cur][i].first;
			int ncost = map[cur][i].second + cost;
			if (dist[next] > ncost) {
				dist[next] = ncost;
				q.push({ -ncost,next });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c;
		map[a].push_back({ b,c });
		map[b].push_back({ a,c });
	}
	dijk(1);
	cout << dist[n];
	return 0;
}

