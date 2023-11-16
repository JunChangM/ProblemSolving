#include <iostream>
using namespace std;
char c;
int n, k, a, b;
int input[100001];
int tree[400004];
int init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = input[start];
	}
	return tree[node] = init(node * 2, start, (start + end) / 2) 
		* init(node * 2 + 1, (start + end) / 2 + 1, end);
}
int  update(int node, int start, int end, int index, int value) {
	if (index < start || end < index) return tree[node];
	if (start == end) return tree[node] = value;
	return tree[node] = update(node * 2, start, (start + end) / 2, index, value) 
		* update(node * 2 + 1, (start + end) / 2 + 1, end, index, value);
}
int find(int node, int start, int end, int left, int right) {
	if (end < left || right < start) return 1;
	if (left <= start && end <= right) return tree[node];
	return find(node * 2, start, (start + end) / 2, left, right) * find(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie(0);

	while (cin >> n >> k) {
		string ans = "";
		for (int i = 1; i <= n; i++) {
			cin >> a;
			if (a > 0) a = 1;
			else if (a < 0) a = -1;
			input[i] = a;
		}
		init(1, 1, n);
		while (k--) {
			cin >> c >> a >> b;
			if (c == 'C') {
				if (b > 0) b = 1;
				else if (b < 0) b = -1;

				if (input[a] == b) continue;

				if (input[a] != 0) {
					update(1, 1, n, a, b);
					input[a] = b;
				}
				else {
					input[a] = b;
					init(1, 1, n);
				}
			}
			else if (c == 'P') {
				int x = find(1, 1, n, a, b);
				if (x == 1) ans.push_back('+');
				else if (x == -1) ans.push_back('-');
				else ans.push_back('0');
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
