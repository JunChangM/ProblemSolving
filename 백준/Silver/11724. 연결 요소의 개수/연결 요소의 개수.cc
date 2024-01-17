#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m, a, b;
vector<int> v[1001];
int visited[1001];

void sear(int x) {
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (visited[next] == 0) {
				visited[next] = 1;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	a = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			a++;
			sear(i);
		}
	}
	cout << a;
	return 0;
}
