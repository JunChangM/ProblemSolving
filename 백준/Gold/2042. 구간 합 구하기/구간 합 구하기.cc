#include<iostream>
using namespace std;
long long input[1000001];
long long tree[4000004]; //  data size * 4를 해야 안전하다.
int n, m, k, a, b;
long long c;

long long init(int node, int start, int end) {
	if (start == end) return tree[node] = input[start];
	return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
}
void update(int node, int start, int end, int target, long long diff) {
	if (start > target || end < target) return;
	tree[node] += diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, target, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, target, diff);
	}
}
long long find_sum(int node, int start, int end, int left, int right) {
	if (end < left || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	return find_sum(node * 2, start, (start + end) / 2, left, right) + find_sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	m += k;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	init(1, 0, n - 1);
	while (m--) {
		cin >> a >> b >> c;
		if (a & 1) {
			// b 번째 수를 c 로 바꾸기
			update(1, 0, n - 1, b-1, c - input[b-1]);
			input[b-1] = c;
		}
		else {
			// b ~ c 까지의 수의 합 출력
			cout << find_sum(1, 0, n - 1, b-1, c-1) << "\n";
		}
	}
}
