/*
[K번쨰 최단경로 찾기](1854)
다익스트라..........
값이 k번 갱신 될 때까지 다익스트라를 진행해준다.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, k;
int a, b, c;
int visited_count[1001];
vector<pair<int, int>> map[1001];
int dist[1001]; 

void dijk() {
	priority_queue<pair<int, int>> pq; // max 값이 top에 온다. -> 음수의 값으로 넣어 오름차순으로 정렬

	pq.push({ 0,1 }); // cost, start node
	int count = n;
	while (count && !pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (visited_count[cur] >= k) continue;
		visited_count[cur]++;
		if (visited_count[cur] == k) count--;
		dist[cur] = -cost; // 어쩌피 작은 값으로 먼저 갱신이 된다.
		for (int i = 0; i < map[cur].size(); i++) {
			if (visited_count[map[cur][i].second] < k) {
				int ncost = map[cur][i].first;
				int nextcur = map[cur][i].second;
				pq.push({ ncost + cost ,nextcur });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		map[a].push_back({-c,b });
	}
	dijk();
	for (int i = 1; i <= n; i++) {
		if (visited_count[i] == k) cout << dist[i] << "\n";
		else cout << -1 << "\n";
	}
}