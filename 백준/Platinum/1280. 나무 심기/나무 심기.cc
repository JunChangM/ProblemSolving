#include <iostream>
#include <set>
#define div 1000000007
#define N 200000
using namespace std;
pair<long long,long long> tree[N * 4];
void update(int node, int start, int end, int index) {
	if (start <= index && index <= end) {
		tree[node].first++;
		tree[node].second += index;
		if (start == end) return;
		update(node * 2, start, (start + end) / 2, index);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index);
	}
}
pair<long long, long long> find(int node, int start, int end, int left, int right) {
	if (start > right || left > end) return { 0,0 };
	if (left <= start && end <= right) return tree[node];
	pair<long long, long long> x = find(node * 2, start, (start + end) / 2, left, right);
	pair<long long, long long> y = find(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return { x.first + y.first , x.second + y.second };
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long ans = 1;
	int a;
	int n;
	set<int> st;
	cin >> n;
	if (n >= 1) {
		cin >> a;
		update(1, 0, N, a);
		st.insert(a);
	}
	for (int i = 2; i <= n; i++) {
		cin >> a;
		st.insert(a);
		pair<long long, long long> leftx = find(1, 0, N, 0, a - 1);
		pair<long long, long long> rightx = find(1, 0, N, a + 1, N);
		update(1, 0, N, a);
		long long temp = abs(leftx.first * a - leftx.second) + abs(rightx.first *  a - rightx.second);
		if (temp == 0) continue;
		ans = (ans * (temp % div)) % div;
	}
	if (st.size() == 1) cout << 0;
	else cout << ans;
	return 0;
}
