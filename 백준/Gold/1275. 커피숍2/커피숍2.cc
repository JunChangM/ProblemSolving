#include <iostream>
using namespace std;
int n, q, x, y, a, b, input[100000];
long long tree[400004];
long long init(int node, int start, int end) {
	if (start == end) return tree[node] = input[start];
	return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
}
void update(int node, int start, int end, int index, int newvalue ,int oldvalue) {
	if (start > index || end < index) return;
	tree[node] = tree[node] - oldvalue + newvalue;
	if (start == index && end == index) return;
	update(node * 2, start, (start + end) / 2, index, newvalue, oldvalue);
	update(node * 2 + 1, (start + end) / 2 + 1, end, index, newvalue, oldvalue);
}
long long findval(int node, int start, int end, int left, int right) {
	if (end < left || right < start) return 0;
	if (left <= start && end <= right) {
		return tree[node];
	}
	return findval(node * 2, start, (start + end) / 2, left, right) + findval(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	init(1, 0, n - 1);

	while (q--) {
		cin >> x >> y >> a >> b;
		x--; y--; a--;
		if (x > y) {
			int temp = x;
			x = y;
			y = temp;
		}
		cout << findval(1, 0, n - 1, x, y) << "\n";
		update(1, 0, n - 1, a, b, input[a]);
		input[a] = b;
	}
	return 0;
}