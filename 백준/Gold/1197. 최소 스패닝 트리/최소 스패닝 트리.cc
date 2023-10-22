#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, a, b, c;
long long ans;
int parent[100001];
vector< pair<int, pair<int, int>>> map;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

bool uni(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) return false;

	if (x < y) parent[x] = y;
	else  parent[y] = x;

	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		map.push_back({ c,{a,b} });
	}
	sort(map.begin(), map.end());
	c = 0;
	
	for (int i = 0; i < m; i++) {
		if (uni(map[i].second.first, map[i].second.second)) {
			ans += map[i].first;
			c++;
			if (c == n - 1) {
				// ans -= map[i].first;
				break;
			}
		}
	}
	cout << ans;
    return 0;
}
