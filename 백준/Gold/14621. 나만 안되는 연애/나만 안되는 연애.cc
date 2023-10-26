#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m, n, u, v, d;
long long ans;
int parent[1000];
char gender[1000];
vector< pair<int, pair<int, int>>> map;
int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}
bool uni(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return false;
	if (x < y) parent[x] = y;
	else parent[y] = x;
	return true;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> gender[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> d;
		map.push_back({d, { u,v }});
	}
	sort(map.begin(), map.end());


	for (int i = 0; i < n; i++) parent[i] = i;
	
	u = 0;
	for (int i = 0; i < map.size(); i++) {
		int s = map[i].second.first - 1;
		int e = map[i].second.second - 1;
		if (gender[s] != gender[e] && uni(s, e) ) {
			ans += map[i].first;
			if (++u == n - 1) break;
		}
	}
	if (u != n - 1) ans = -1;
	
	

	cout << ans;
	return 0;
}