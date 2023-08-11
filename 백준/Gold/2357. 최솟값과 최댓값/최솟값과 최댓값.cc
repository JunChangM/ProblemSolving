#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a, b;
long long input[100001];
pair<long long, long long>  tree[400004];// 최소, 최대
pair<long long, long long> init(int node, int start, int end) {
	if (start == end) return tree[node] = { input[start],input[start] };
	pair<long long, long long> x = init(node * 2, start, (start + end) / 2);
	long long x1 = x.first;
	long long x2 = x.second;
	x = init(node * 2 + 1, (start + end) / 2 + 1, end);
	long long y1 = x.first;
	long long y2 = x.second;
	x1 = min(x1, y1);
	x2 = max(x2, y2);
	return tree[node] = { x1,x2 };
}
pair<long long, long long> find(int node, int start, int end, int left, int right) {
	if (end < left|| right < start) return { 1000000001,-1 };
	if (left <= start && end <= right) return tree[node];
	pair<long long, long long> x = find(node * 2, start, (start + end) / 2, left, right);
	pair<long long, long long> y = find(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return { min(x.first,y.first),max(x.second, y.second) };
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	init(1, 0, n - 1);

	while (m--) {
		cin >> a >> b;
		a--; b--;
		pair<long long, long long> ans = find(1, 0, n - 1, a, b);
		cout << ans.first << ' ' <<  ans.second << "\n";
	}
}