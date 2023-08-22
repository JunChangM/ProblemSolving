#include <iostream>
#include <algorithm>
using namespace std;
int n, number;
long long r;
long long input[500001];
long long talent[500001];
long long tree[2000000];
void update(int node, int start, int end, int index) {
	if (start <= index && index <= end) {
		tree[node]++;
		if (start == end) return;
		update(node * 2, start, (start + end) / 2, index);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index);
	}
}
int find(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	return find(node * 2, start, (start + end) / 2, left, right) + find(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> talent[i];
		input[i] = talent[i];
	}
	sort(talent, talent + n);
	for (int i = 0; i < n; i++) {
		input[i] = lower_bound(talent, talent + n, input[i]) - talent;
	}
	for (int i = 0; i < n; i++) {
		update(1, 0, n - 1, input[i]);
		cout << i + 2 - find(1, 0, n - 1, 0, input[i]) << "\n";
	}
	return 0;
}
