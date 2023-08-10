#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, k, t, r;
int parent[52];
vector<int> temp[51];

int _find(int x) {
	if (parent[x] == x) return x;
	else {
		return parent[x] = _find(parent[x]);
	}
}

void _union(int x, int y) {
	int fx = _find(x);
	int fy = _find(y);
	if (fx < fy) parent[fx] = fy;
	else parent[fy] = fx;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= 51; i++) parent[i] = i;

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> t;
		parent[t] = 51;
	}

	for (int i = 0; i < m; i++) {
		cin >> t;

		cin >> r;
		temp[i].push_back(r);
		for (int j = 1; j < t; j++) {
			cin >> k;
			temp[i].push_back(k);
			_union(r, k);
		}

	}


	int count = 0;

	for (int i = 0; i < m; i++) {
		int flag = 1;
		for (int j = 0; j < temp[i].size(); j++) {
			if (_find(temp[i][j]) == 51) {
				flag = 0;
				break;
			}
		}
		if (flag) count++;
	}


	cout << count;
}