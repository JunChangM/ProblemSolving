#include <iostream>
#include <vector>
#define INF 200000000
using namespace std;
int tc, n, m, w, s, e, t;
vector<pair<int, pair<int, int>>> edge;
bool bellman_ford() {
	vector<int> dist(n + 1, INF);
	dist[1] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < edge.size(); j++) {
			s = edge[j].first;
			e = edge[j].second.first;
			t = edge[j].second.second;
			if (dist[e] > dist[s] + t) dist[e] = dist[s] + t;
		}
	}
	for (int j = 0; j < edge.size(); j++) {
		s = edge[j].first;
		e = edge[j].second.first;
		t = edge[j].second.second;
		if (dist[e] > dist[s] + t) return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> tc;
	while (tc--) {
		edge.clear();
		cin >> n >> m >> w;
		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;
			edge.push_back({ s,{e,t} });
			edge.push_back({ e,{s,t} });
		}
		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			edge.push_back({ s,{e,-t} });
		}
		if (bellman_ford()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
/*
웜홀(1865)
음수 간선이 존재할 때, 음수의 값으로 시작점 도달 가능한지 => 벨만포드
1회 실패 => 모든 간선이 연결되었다는 것이 보장이 되어 있지 않다. 
=> 시작지점을 1로 잡으면 안되고 음수 사이클의 존재 여부만 파악하며 된다.
*/