#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, x, y, z;
vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;
vector<pair<int, pair<int, int>>> weight;
int parent[100001];
int find(int a) {
	if (parent[a] == a) return a;
	else {
		return parent[a] = find(parent[a]);
	}
}
void _union(int a, int b) {
	int x = find(a);
	int y = find(b);
	if (x < y) {
		parent[y] = x;
	}
	else {
		parent[x] = y;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	X.assign(n, { 0,0 });
	Y.assign(n, { 0,0 });
	Z.assign(n, { 0,0 });
	weight.assign(3 * (n - 1) + 1, { 0, {0,0} });
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		X[i] = { x,i };
		Y[i] = { y,i };
		Z[i] = { z,i };
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());
	for (int i = 0; i < n - 1; i++) {
		weight.push_back({ X[i + 1].first - X[i].first,{X[i + 1].second,X[i].second} });
		weight.push_back({ Y[i + 1].first - Y[i].first,{Y[i + 1].second,Y[i].second} });
		weight.push_back({ Z[i + 1].first - Z[i].first,{Z[i + 1].second,Z[i].second} });
	}
	sort(weight.begin(), weight.end());

	// 크루스칼
	int total = 0;
	for (int i = 0; i < weight.size(); i++) {
		int w = weight[i].first;
		int from = weight[i].second.first;
		int to = weight[i].second.second;
		if (find(from) != find(to)) {
			total += w;
			_union(from, to);
		}
	}
	cout << total;
	return 0;
}

/*
간선을 직접 계산하려면 10만 * 10만으로 너무 많은 경우가 존재한다.
가장 작은 간선만 구하면 되기 때문에, 각 좌표별로 크기별로 정렬한 후 그 사이값을 weight로 만든다.
모든 weight에 대하여 최소 비용을 찾기 위해 union-find를 이용한 크루스칼을 진행한다.
<https://chanhuiseok.github.io/posts/baek-34/>
*/
