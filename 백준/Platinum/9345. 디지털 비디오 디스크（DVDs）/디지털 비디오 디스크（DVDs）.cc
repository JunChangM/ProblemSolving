#include <iostream>
#include <cstring>
#define N 100001
using namespace std;
int t, n, k, q, a, b;
int dvd[N];
pair<int,int> tree[N * 4];
pair<int,int> init(int node, int start, int end) {
	if (start == end) return tree[node] = { dvd[start],dvd[start] };
	int mid = (start + end) / 2;
	pair<int, int> x = init(node * 2, start, mid);
	pair<int, int> y = init(node * 2 + 1, mid + 1, end);
	return tree[node] = { max(x.first,y.first) , min(x.second,y.second) };
}
pair<int,int> update(int node, int start, int end, int index, int value) {
	if (start <= index && index <= end) {
		if (start == end) {
			return tree[node] = { value,value };
		}
		int mid = (start + end) / 2;
		pair<int, int> x = update(node * 2, start, mid, index, value);
		pair<int, int> y = update(node * 2 + 1, mid + 1, end,index, value);
		return tree[node] = { max(x.first,y.first) , min(x.second,y.second) };
	}
	else {
		return tree[node];
	}
}
pair<int, int> find(int node, int start, int end, int left, int right) {
	if (right < start || end < left) return { -1,N };
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	pair<int, int> x = find(node * 2, start, mid, left, right);
	pair<int, int> y = find(node * 2 + 1, mid + 1, end, left, right);
	return { max(x.first,y.first) , min(x.second,y.second) };
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--){
		memset(tree, 0, sizeof(tree));
		cin >> n >> k;
		for (int i = 0; i < n; i++) dvd[i] = i;
		init(1, 0, n - 1);

		while (k--) {
			cin >> q >> a >> b;
			if (q == 0) { // a와 b 바꾸기
				update(1, 0, n - 1, a, dvd[b]);
				update(1, 0, n - 1, b, dvd[a]);
				int temp = dvd[a];
				dvd[a] = dvd[b];
				dvd[b] = temp;
			}
			else {
				pair<int, int> f = find(1, 0, n - 1, a, b);
				if (b == f.first && a == f.second ) cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}
	return 0;
}