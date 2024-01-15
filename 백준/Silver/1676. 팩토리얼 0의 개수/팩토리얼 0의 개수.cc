#include <iostream>
#include <algorithm>
using namespace std;
int n, a, b, c;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		c = i;
		while (c % 2 == 0) {
			c /= 2;
			a++;
		}
		while (c % 5 == 0) {
			c /= 5;
			b++;
		}
	}
	cout << min(a, b);
	return 0;
}
