#include <iostream>
#include <string>
#include <map>
using namespace std;
int parent[200001];
int fr[200001];
string a, b;
int i, t, n;
map<string, int> m;
int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
void unionset(int x1, int y1) {
	int x = find(x1);
	int y = find(y1);
	if (x != y) {
		int temp = fr[x] + fr[y];
		fr[x] = temp;
		fr[y] = temp;
	}
	if (x < y) parent[x] = y;
	else parent[y] = x;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		m.clear();
		int idx = 1;
		for (i = 1; i <= 200001; i++) {
			parent[i] = i;
			fr[i] = 1;
		}

		for (i = 0; i < n; i++) {
			cin >> a >> b;
			if (m.find(a) == m.end()) m.insert({ a, idx++ });
			if (m.find(b) == m.end()) m.insert({ b, idx++ });
			unionset(m[a], m[b]);
			cout << fr[find(m[a])] << "\n";
		}
	}
	return 0;
}