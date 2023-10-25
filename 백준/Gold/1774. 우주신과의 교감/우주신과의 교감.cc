#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int m, n, x, y, t;
double ans;
int position[1000][2];
int parent[1000];
vector< pair<double, pair<int, int>>> map;
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
		cin >> position[i][0] >> position[i][1];
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			double dist = sqrt(pow(position[i][0] - position[j][0], 2) + pow(position[i][1] - position[j][1], 2));
			map.push_back({ dist,{i+1,j+1} });
		}
	}
	sort(map.begin(), map.end());
	for (int i = 1; i <= n; i++) parent[i] = i;
	

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		if (uni(x, y)) t++;
	}

	if (t != n - 1) {
		for (int i = 0; i < map.size(); i++) {
			if (uni(map[i].second.first, map[i].second.second)) {
				ans += map[i].first;
				if (++t == n - 1) break;
			}
		}
	}
	

	cout << fixed;
	cout.precision(2);
	cout << ans;
	return 0;
}