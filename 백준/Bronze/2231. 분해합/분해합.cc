#include <iostream>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	int ans = 0;
	int temp = 0;
	while (temp != n) {
		ans++;
		int t = ans;
		temp = t;
		while (t != 0) {
			temp += t % 10;
			t /= 10;
		}
		if (ans > n) {
			cout << 0;
			return 0;
		}
	}
	cout << ans;
}

