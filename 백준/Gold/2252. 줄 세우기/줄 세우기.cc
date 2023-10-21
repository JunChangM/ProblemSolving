#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, a, b;
vector<int> map[32001];
int visit[32001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		visit[b]++;
		map[a].push_back(b);
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) if (visit[i] == 0) q.push(i);
	while (!q.empty()) {
		int cur = q.front();
		cout << cur << ' ';
		q.pop();
		for (int i = 0; i < map[cur].size(); i++) {
			int next = map[cur][i];
			visit[next]--;
			if (visit[next] == 0) q.push(next);
		}
	}
    return 0;
}
