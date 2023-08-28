#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, a, b, answer;
int visited[101];
vector<int> map[101];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < map[x].size(); i++) {
			int y = map[x][i];
			if (visited[y] == 0) {
				answer++;
				visited[y] = 1;
				q.push(y);
			}
		}
	}
	cout << answer;
}