#include <iostream>
#define div 1000000007
using namespace std;
int n, m, k, a, b, c;
int input[1000001];
long long tree[4000004];
long long init(int node, int start, int end) {
	if (start == end) return tree[node] = input[start];
	return tree[node] = (init(node * 2, start, (start + end)/2) * init(node * 2 + 1, (start + end)/2 + 1, end)) % div;
}

long long update0(int node, int start, int end, int target) {
	if (target < start || end < target) return tree[node];
	if (start == target && target == end) {
		return tree[node] = input[target];
	}
	return tree[node] = (update0(node * 2, start, (start + end) / 2, target) * update0(node * 2 + 1, (start + end) / 2 + 1, end, target)) % div;
}
long long f(int node, int start, int end, int left, int right) {
	if (left > end || start > right) return 1;
	if (left <= start && end <= right) {
		return tree[node];
	}
	return (f(node * 2, start, (start + end)/2, left, right) * f(node * 2 + 1, (start + end)/2 + 1, end, left, right)) % div;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	m += k;
	for (int i = 0; i < n; i++) cin >> input[i];
	init(1, 0, n - 1);
	while (m--) {
		cin >> a >> b >> c;
		if (a == 1) { // b 번재  수를  c 로 바꾸기
			b--;
			input[b] = c;
			update0(1, 0, n - 1, b);
		}
		else { // b 부터 c 까지의 곱 출력
			b--;
			c--;
			cout << f(1, 0, n - 1, b, c) << "\n";
		}
	}
	return 0;
}