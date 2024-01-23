#include <iostream>
#include <vector>
using namespace std;
int n,a;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int> v(10001, 0);
	for (int i = 0; i < n; i++) {
		cin >> a;
		v[a]++;
	}
	for (int i = 0; i < 10001; i++) {
		if (v[i] == 0) continue;
		for (int j = 0; j < v[i]; j++) {
			cout << i << '\n';
		}
	}
	return 0;
}
