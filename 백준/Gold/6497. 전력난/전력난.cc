#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m, n, x, y, z;
long long ans;
int parent[200000];
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
	cin >> n >> m; // 집의 수 n, 길의 수 m 으로 하자
	while (n != 0 && m != 0) {
		ans = 0;
		map.clear();
		for (int i = 0; i < m; i++) {
			cin >> x >> y >> z;
			map.push_back({ z,{x,y} });
			ans += z;
		}
		sort(map.begin(), map.end());
		for (int i = 0; i < n; i++) parent[i] = i;
		x = 0;
		for (int i = 0; i < m; i++) {
			if (uni(map[i].second.first, map[i].second.second)) {
				ans-=map[i].first;
				if (++x == n - 1) break;
			}
		}
		cout << ans << "\n";
		cin >> n >> m;
	}
	return 0;
}