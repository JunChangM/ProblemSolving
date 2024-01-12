#include <iostream>
using namespace std;
int a, b, c;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b;
	if (a < b) {
		int t = a;
		a = b;
		b = t;
	}
	c = 1;

	for (int i = 2; i <= b; i++) {
		while (a % i == 0 && b % i == 0) {
			c *= i;
			a /= i;
			b /= i;
		}
	}
	cout << c << '\n' << c * a * b;
	return 0;
}
