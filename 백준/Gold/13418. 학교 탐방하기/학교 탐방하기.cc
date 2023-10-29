#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, a, b, c;
int parent[1001];
vector < pair<int,  int>> down;
vector < pair<int,  int>> up;
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
	for (int i = 0; i <= m; i++) {
		cin >> a >> b >> c;
		if (c == 1) {
			down.push_back({ a,b });
		}
		else {
			up.push_back({ a,b });
		}
	}

	sort(down.begin(), down.end());
	sort(up.begin(), up.end());

	a = 0; b = 0;
	for (int i = 0; i <= n; i++) parent[i] = i;

	for (int i = 0; i < down.size(); i++) {
		if (uni(down[i].first, down[i].second)) {
			a++;
			if (a == n) break;
		}
	}
	for (int i = 0; i < up.size(); i++) {
		if (a == n) break;
		if (uni(up[i].first, up[i].second)) {
			b++;
			a++;
		}
	}

	a = 0; c = 0;
	for (int i = 0; i <= n; i++) parent[i] = i;

	for (int i = 0; i < up.size(); i++) {
		if (uni(up[i].first, up[i].second)) {
			c++;
			a++;
			if (a == n) break;
		}
	}
	for (int i = 0; i < down.size(); i++) {
		if (a == n) break;
		if (uni(down[i].first, down[i].second)) {
			a++;
		}
	}

	cout << abs(b * b - c * c);
	return 0;
}