#include <iostream>
using namespace std;
int n, k, ans;
int coin[11];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> coin[i];

	int i = n - 1;
	while (k != 0) {
		if (k >= coin[i]) {
			k -= coin[i];
			ans++;
		}
		else i--;
		if (i < 0) return -1;
	}

	cout << ans;

	return 0;
}

