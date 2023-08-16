#include <iostream>
#include <vector>
#include <queue>
#define INF 200000000
using namespace std;
vector<pair<int, int>> edge[100001];
int n;
int answer = 0;

int dfs(int start) {
	int dist[100001];
	for (int i = 1; i <= n; i++) dist[i] = INF;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	dist[start] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (cost > dist[cur]) continue;
		for (int i = 0; i < edge[cur].size(); i++) {
			int ncost = cost + edge[cur][i].first;
			int next = edge[cur][i].second;
			if ( ncost < dist[next]) {
				dist[next] = ncost;
				pq.push({ -ncost,next });
			}
			
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF) continue;
		answer = answer > dist[i] ? answer : dist[i];
	}
	for (int i = 1; i <= n; i++) {
		if (dist[i] == answer) return i;
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	int a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a;
		cin >> b;
		while (b != -1) {
			cin >> c;
			edge[a].push_back({ c,b });
			cin >> b;
		}
	}

	int s = dfs(1);
	dfs(s);
	cout << answer;
	return 0;
}