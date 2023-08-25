#include <iostream>
#include <algorithm>
#define N 100001
#define INF 1000000001
using namespace std;
int n, m, a, b;
long long input[N];
long long tree[N * 4];
long long init(int node, int start, int end) {
	if (start == end) return tree[node] = input[start];
	int mid = (start + end) / 2;
	return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}
long long find(int node, int start, int end, int left, int right) {
	if (right < start || end < left) return INF;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return min(find(node * 2, start, mid, left, right), find(node * 2 + 1, mid + 1, end, left, right));
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> input[i];
	init(1, 1, n);
	while (m--) {
		cin >> a >> b;
		cout << find(1, 1, n, a, b) << "\n";
	}
	return 0;
}