#include <iostream>
#include <math.h>
using namespace std;
long long n, a, b, c;
//bool check(long long x, long long y) {
//	if (y == 1) return true;
//	if (y == 0) return false;
//	return check(y, x % y);
//}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	c = 1;
	a = n;
	for (long long i = 2; i * i <= n; i++) {
		if (a % i == 0) {
			b = 0;
			while (a % i == 0) {
				b++;
				a /= i;
			}
			c *= pow(i, b - 1) * (i - 1);
		}
	}

	if (a != 1) {
		c *= (a - 1);
	}

	cout << c;
	return 0;
}
