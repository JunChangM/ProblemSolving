#include <iostream>
using namespace std;
int k, m, n, x, y;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> m >> n >> x >> y;
		int d = m * n / gcd(m, n);
		if (y == n) y = 0;
		while (x % n != y) {
			x += m;
			if (x > d) {
				x = -1;
				break;
			}

		}
		cout << x << '\n';

	}
	return 0;
}

/*
* 
int a = 1, b = 1, ans = 1;
		while (a != x || b != y)
		{
			ans++;
			a++;
			b++;

			if (a == m && b == n && a != x && b != y) {
				ans = -1;
				break;
			}

			if (a > m) a = 1;

			if (b > n) b = 1;

		}
		cout << ans << '\n';

*/