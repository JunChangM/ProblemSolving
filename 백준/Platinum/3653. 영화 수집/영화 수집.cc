#include <iostream>
using namespace std;
int t, n, m, k;
int input[200001];
int tree[800001];
int init(int node, int start, int end) {
	if (start == end) {
		if (start <= n) return tree[node] = 1;
		else return tree[node] = 0;
	}
	return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
}
int find(int node, int start, int end, int left, int right) {
	if (start > right || end < left) return 0;
	if (left <= start && end <= right) return tree[node];
	return find(node * 2, start, (start + end) / 2, left, right) + find(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void update(int node, int start, int end, int index, int val) {
	if (start <= index && index <= end) {
		if (start == end && start == index) {
			tree[node] += val;
		}
		else {
			tree[node] += val;
			update(node * 2, start, (start + end) / 2, index, val);
			update(node * 2 + 1, (start + end) / 2 + 1, end, index, val);
		}
	}

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) input[i] = n - i + 1;
		init(1, 1, n + m);
		for (int i = 1; i <= m; i++) {
			cin >> k;
			cout << find(1, 1, n + m, input[k] + 1, n + m) << ' ';
			update(1, 1, n + m, input[k], -1);
			input[k] = n + i;
			update(1, 1, n + m, input[k], 1);
		}
		cout << "\n";
	}
	return 0;
}
