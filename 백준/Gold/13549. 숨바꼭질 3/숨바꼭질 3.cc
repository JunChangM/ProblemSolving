#include <iostream>
#include <vector>
#include <queue>
#define INF 200000000
using namespace std;
int n, k, ans;
int dist[100001];
vector<pair<int, int>> map[100001];
void dijk() {
	priority_queue <pair<int, int>> pq;
	for (int i = 0; i < 100001; i++) dist[i] = INF;
	dist[n] = 0;
	pq.push({ 0,n });
	while (!pq.empty()) {
		int t = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < t) continue;
		for (int i = 0; i < map[cur].size(); i++) {
			int next = map[cur][i].first;
			int nt = map[cur][i].second;
			if (dist[next] > nt + t) {
				dist[next] = nt + t;
				pq.push({ -dist[next],next });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	if (k <= n) ans = n - k;
	else {
		map[0].push_back({ 1,1 });
		for (int i = 1; i < 100000; i++) {
			map[i].push_back({ i + 1,1 });
			map[i].push_back({ i - 1,1 });
			if (2 * i <= 100000)
				map[i].push_back({ 2 * i, 0 });
		}
		map[100000].push_back({ 100000 - 1,1 });
		dijk();
		ans = dist[k];
	}
	cout << ans;
	return 0;
}
