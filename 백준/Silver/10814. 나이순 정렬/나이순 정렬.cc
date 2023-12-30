#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	vector<pair<int, string>> v(n, { 0,"" });
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	stable_sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}

	return 0;
}
