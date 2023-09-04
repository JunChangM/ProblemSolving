#include <iostream>
#include <vector>
#include <queue>
#define N 1001
#define INF 10000001
using namespace std;
int n, m, x, a, b, c;
int dist[N]; // 돌아올때
int dist2[N]; // x까지 가는데 
vector<pair<int,int>> map[N];
vector<pair<int, int>> map2[N];


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> x;
	while (m--) {
		cin >> a >> b >> c;
		map[a].push_back({ b,c });
		map2[b].push_back({ a,c });
	}

	for (int i = 1; i <= n; i++) dist[i] = INF;
	for (int i = 1; i <= n; i++) dist2[i] = INF;
	dist[x] = 0;
	dist2[x] = 0;

	//  N : 1
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,x });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (cost > dist2[cur]) continue;
		for (int i = 0; i < map2[cur].size(); i++) {
			int ncost = map2[cur][i].second + cost;
			int next = map2[cur][i].first;
			if (dist2[next] > ncost) {
				dist2[next] = ncost;
				pq.push({ -ncost,next });
			}
		}
	}



	// 1 : N

	pq.push({ 0,x });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (cost > dist[cur]) continue;
		for (int i = 0; i < map[cur].size(); i++) {
			int ncost = map[cur][i].second + cost;
			int next = map[cur][i].first;
			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ -ncost,next });
			}
		}
	}

	// max(dist1 + dist 2 )
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF || dist2[i] == INF) continue;
		ans = ans > dist[i] + dist2[i] ? ans : dist[i] + dist2[i];
	}

	cout << ans;
    return 0;
}