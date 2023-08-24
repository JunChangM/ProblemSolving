#include <iostream>
#define N 2000000
using namespace std;
int n, a, b;
int tree[(N+1) * 4];
void update(int node, int start, int end, int index, int val) {
	int mid = (start + end) / 2;
	if (start <= index && index <= end) {
		tree[node] += val;
		if (start == end) return;
		update(node * 2, start, mid, index, val);
		update(node * 2 + 1, mid + 1, end, index, val);
	}
}
int depfind(int node, int start, int end) {
	int mid = (start + end) / 2;
	if (start == end) return start;
	if (tree[node * 2 + 1] >= 1) return depfind(node * 2 + 1, mid + 1, end);
	else return depfind(node * 2, start, mid);
}

int find(int node, int start, int end, int ord) {
	int mid = (start + end) / 2;
	if (start == end) return start;
	if (tree[node] == ord) {
		return depfind(node, start, end);
	}
	else if (tree[node] > ord) {
		if (tree[node * 2] < ord) return find(node * 2 + 1, mid + 1, end, ord - tree[node * 2]);
		else {
			return find(node * 2, start, mid, ord);
		}
	}
	else {
		return 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a == 1) {
			update(1, 1, N, b,1);
		}
		else {
			ans = find(1, 1, N, b);
			update(1, 1, N, ans, -1);
			cout << ans << "\n";
		}
	}
	return 0;
}
