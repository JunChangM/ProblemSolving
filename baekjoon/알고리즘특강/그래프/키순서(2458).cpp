// [키 순서](2458)
/*
방향이 있는 그래프에서는 화살표 방향으로 가는 것이 편하다.
들어오는 친구들을 구하기가 힘들다
간선의 방향을 뒤집는다.
큰 친구 방향 + 작은 친구 방향 = N-1 개의 관계를 가지는지 확인한다.

*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, m, s, e;
vector<int> graph[2][501];
int visit[501];
int main() {
	int answer = 0;
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		graph[0][s].push_back(e);
		graph[1][e].push_back(s);
	}
	for (int start_node = 1; start_node <= n; start_node++) {
		//queue 를 이용하여 정방향 역방향 dfs 진행
		// visited 배열을 초기화 하지 않고 dfs 진행하도록 더 간략히 짤 수도 있음.
		int comnum = 1;

		for (int i = 0; i < 2; i++) {
			queue<int> q;
			memset(visit, 0, sizeof(visit));
			visit[start_node] = 1;
			for (auto x : graph[i][start_node]) {
				q.push(x);
				visit[x] = 1;
				comnum += 1;
			}
			while (!q.empty()) {
				int x = q.front();
				// cout << start_node << " " << i << " 방문 노드 " << x << endl;
				q.pop();
				for (int y : graph[i][x]) {
					if (visit[y] == 0) {
						visit[y] = 1;
						q.push(y);
						comnum += 1;
					}
				}
			}
			
		}
		// cout << comnum << endl;
		if (comnum == n) answer += 1;
	}
	// 관계가 n이면 answer
	cout << answer;
}
