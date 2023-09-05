#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		v.push_back(m);
	}
	sort(v.begin(), v.end());

	int left = 0, right = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		int x = v[i];
		if (x + left <= right + 1) {
			right = x + right;
		}
		else {
			ans = right + 1;
			break;
		}
	}
	if (ans != 0) cout << ans;
	else cout << right + 1;
	return 0;
}