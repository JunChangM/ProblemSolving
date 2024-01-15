#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first > b.first) return false;
	if (a.first == b.first && a.second > b.second) return false;
	return true;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<pair<int, int>> v(n, { 0,0 });
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
	return 0;
}
