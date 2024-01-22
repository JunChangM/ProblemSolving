#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int n, m, a, b;
vector<int> map[101];
int visited[101];

void bfs(int start) {
	queue<int> q;
	memset(visited, -1, sizeof(visited));
	q.push(start);
	visited[start] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < map[x].size(); i++) {
			int y = map[x][i];
			if (visited[y] == -1) {
				visited[y] = visited[x] + 1;
				q.push(y);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	int ans = 2000000000, num = 0;
	for (int i = 1; i <= n; i++) {
		bfs(i);

		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += visited[j];
		}

		if (sum < ans) {
			ans = sum;
			num = i;
		}
	}
	cout << num;
	return 0;
}
