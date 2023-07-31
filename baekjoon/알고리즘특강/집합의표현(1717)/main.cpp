#include <iostream>
using namespace std;
#define MAX 1000001
int parent[MAX];
int n, m, c, a, b;
int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		// return find(parent[x]);
    // 아래 식을 통해 parent[x]의 값을 갱신해줌으로써 최상위의 값을 빠르게 가져올 수 있다.
		return parent[x] = find(parent[x]);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> c >> a >> b;
		if (c == 0) {
			a = find(a);
			b = find(b);
			parent[b] = a;
		}
		else if (c == 1) {
			if (find(a) == find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}
