#include <iostream>
#include <vector>
#include <queue>
#define INF 100000000
using namespace std;
int V, E, k, u, v, w;
vector<pair<int,int>> map[20001]; // { cost, destination }
int dist[20001];
void dijk(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	dist[start] = 0;
	
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < cost) continue;

		for (int i = 0; i < map[cur].size(); i++) {
			int ncost = map[cur][i].first;
			int next = map[cur][i].second;
			if (dist[next] > cost + ncost) {
				dist[next] = cost + ncost;
				pq.push({ -(dist[next]), next });
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> V >> E >> k;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		map[u].push_back({ w,v });
	}

	for (int i = 0; i <= V; i++) {
		dist[i] = INF;
	}

	dijk(k);

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
}