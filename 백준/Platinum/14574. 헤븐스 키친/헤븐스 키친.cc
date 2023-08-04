#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

long long cal(long long p1, long long c1, long long p2, long long c2) {
	long long x = (c1 + c2) / abs(p1 - p2);
	return floor(x);
}

int n;
long long p, c;
long long pc[1001][2];
vector<pair<long long, int>> map[1001];
vector<int> map2[1001];
int parent[1001];
int visited[1001];
long long total;

void prim(int start) {
	priority_queue < pair<long long, pair<int,int> >> pq;
	for (int i = 0; i < n; i++) parent[i] = i;
	pq.push({ 0,{start,start}});
	while (!pq.empty()) {
		long long cost = pq.top().first;
		int cur = pq.top().second.first;
		int before = pq.top().second.second;
		pq.pop();
		if (visited[cur] == 0) {
			visited[cur] = 1;
			total += cost;
			// 시작 (0,0) 을 제외하고 진행한 간선들 map2에 저장
			if (before != cur ) map2[before].push_back(cur);
			for (int i = 0; i < map[cur].size(); i++) {
				int next = map[cur][i].second;
				if (visited[next] == 0) pq.push({ map[cur][i].first,{next,cur} });

			}
		}
		
	}

}
void dfs(int parent, int child) {
	// start = 0 으로 map2에서 dfs 진행
	// 승자가 떠나고 패자가 남음. (패자,승자)로 출력 . leaf 노드가 승자가 되야함.
	for (int i = 0; i < map2[child].size(); i++) {
		dfs(child, map2[child][i]);
	}
	if (parent != child ) cout << parent + 1 << " " << child + 1 << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	// 입력 받기
	for (int i = 0; i < n; i++) {
		cin >> pc[i][0] >> pc[i][1];
	}
	// 간선만들기
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int t = cal(pc[i][0], pc[i][1], pc[j][0], pc[j][1]);
			map[i].push_back({ t, j });
			map[j].push_back({ t, i });
		}
	}

	// prim 으로 Maximum Spanning Tree 찾기
	prim(0);
	cout << total << "\n";

	// 대진표 찾기
	dfs(0,0);

}