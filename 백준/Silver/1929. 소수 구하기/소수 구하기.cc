#include <iostream>
using namespace std;
int m, n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> m >> n;
	if (m == 1) m = 2;
	for (int i = m; i <= n; i++) {
		int flag = 1;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag) cout << i << '\n';
	}

	return 0;
}

