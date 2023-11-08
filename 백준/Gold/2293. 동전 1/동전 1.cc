#include <iostream>
using namespace std;
int n, k, t;
int v[10001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	v[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> t;
		for (int j = t; j <= k; j++) v[j] += v[j - t];
	}
	cout << v[k];
	return 0;
}
