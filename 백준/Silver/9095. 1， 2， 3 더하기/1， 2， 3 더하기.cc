#include <iostream>
using namespace std;
int n, num, ans;
void sum123(int x) {
	if (x == 0) {
		ans += 1;
	}
	else {
		for (int i = 1; i < 4; i++) {
			if (x - i >= 0) sum123(x - i);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	while (n--) {
		cin >> num;
		ans = 0;
		sum123(num);
		cout << ans << "\n";
	}
	return 0;
}