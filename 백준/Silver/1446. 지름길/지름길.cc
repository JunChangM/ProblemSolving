#include <iostream>
#include <vector>
#include <queue>
#define INF 10001
using namespace std;
int n, d, a, b, c;
int dist[INF];
vector <pair<int, int>> map[INF];
void dijk() {
	priority_queue < pair<int, int> > pq;
	pq.push({ 0, 0 });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		// if (dist[cur] < cost) continue;
		for (int i = 0; i < map[cur].size(); i++) {
			int ncost = map[cur][i].second + cost;
			int next = map[cur][i].first;
			if (ncost > d) continue;
			if (dist[next] >= ncost) {
				dist[next] = ncost;
				pq.push({ -ncost,next });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		map[a].push_back({ b,c });
	}
	for (int i = 0; i <= d; i++) dist[i] = INF;
	for (int i = 0; i < d; i++) map[i].push_back({ i + 1,1 });
	dijk();
	
	cout << dist[d];

	return 0;
}	
