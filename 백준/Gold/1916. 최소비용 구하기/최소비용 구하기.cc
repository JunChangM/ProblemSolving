#include <iostream>
#include <vector>
#include <queue>
#define INF 200000000
using namespace std;
int n, m, s, e, t;
vector<pair<int, int>> v[1001];
int dijk(int start) {
	vector<int> dist(n + 1, INF);
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	dist[start] = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < cost) continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int ncost = v[cur][i].second + cost;
			int next = v[cur][i].first;
			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ -ncost,next });
			}
		}
	}
	return dist[e];
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> t;
		v[s].push_back({ e,t });
	}
	cin >> s >> e;
	cout << dijk(s);
	return 0;
}
/*

*/