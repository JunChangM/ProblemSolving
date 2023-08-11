#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, c, a;
long long v;
long long input[1000001];
long long tree[4000001];
// min_index를 구할 수 있는 segment tree를 만들어야한다.
int min_index(int x, int y) {
	if (input[x] == input[y]) return min(x, y);
	return input[x] < input[y] ? x : y;
} // 두 노드의 값이 들어 왔을 때, 해당하는 index의 input 값을 알려준다.
// tree의 각 node에는 min_index의 값이 들어간다. 즉 루트 노드의 값을 반환해주면 답이 된다.
long long init(int node, int start, int end) {
	if (start == end) return tree[node] = start;
	return tree[node] = min_index(init(node * 2, start, (start + end) / 2), init(node * 2 + 1, (start + end) / 2 + 1, end));
}
long long update(int node, int start, int end, int idx) {
	if (start > idx || end < idx || start == end) return tree[node];
	return tree[node] = min_index(update(node * 2, start, (start + end) / 2, idx), update(node * 2 + 1, (start + end) / 2 + 1, end, idx));
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> input[i];
	init(1, 0, n-1);
	cin >> m;
	while (m--) {
		cin >> c;
		if (c == 2) {
			cout <<  tree[1] + 1 << "\n";
		}
		else if (c == 1) {
			cin >> a >> v;
			input[a-1] = v;
			update(1, 0, n-1, a-1);
		}
	}
	return 0;
}