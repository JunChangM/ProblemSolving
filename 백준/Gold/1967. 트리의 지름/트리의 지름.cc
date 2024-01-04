#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int n, a, b, c;
vector < pair<int, int>> map[10001];
int dist[10001];

int search(int start) {
	queue<int> q;
	memset(dist, 0, sizeof(dist));

	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < map[cur].size(); i++) {
			int next = map[cur][i].first;
			int ncost = map[cur][i].second;
			if (dist[next] == 0) {
				dist[next] = dist[cur] + ncost;
				q.push(next);
			}
		}
	}
	dist[start] = 0;
	int m = 0;
	for (int i = 1; i <= n; i++) {
		m = dist[m] > dist[i] ? m : i;
	}
	return m;

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		map[a].push_back({ b,c });
		map[b].push_back({ a,c });
	}
	int s = search(1);

	cout << dist[search(s)];

	return 0;
}
