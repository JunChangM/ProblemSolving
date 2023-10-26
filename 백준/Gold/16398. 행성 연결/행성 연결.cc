#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, d;
long long ans;
int parent[1000];
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
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> d;
			map.push_back({ d, { i,j } });
		}
		
	}
	sort(map.begin(), map.end());

	for (int i = 0; i < n; i++) parent[i] = i;
	
	d = 0;
	for (int i = 0; i < map.size(); i++) {
		int s = map[i].second.first;
		int e = map[i].second.second;
		if (uni(s, e) ) {
			ans += map[i].first;
			if (++d == n - 1) break;
		}
	}
	
	cout << ans;
	return 0;
}