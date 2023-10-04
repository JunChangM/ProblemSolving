#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, a, b, x, c;
vector<pair<int, int>> map;
bool comp(pair<int, int> x, pair<int, int> y) {
	if (x.second < y.second) return true;
	else if (x.second == y.second && x.first < y.first) return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		map.push_back({ a,b });
	}
	sort(map.begin(), map.end(),comp);
	for (int i = 0; i < n; i++) {
		if (map[i].first >= x) {
			x = map[i].second;
			c++;
		}
	}
	cout << c;
	return 0;
}

