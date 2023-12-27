#include <iostream>
using namespace std;
int a, b, n, c;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	a = -100000000, b = 100000000;
	cin >> n;
	while (n--) {
		cin >> c;
		a = a < c ? c : a;
		b = b > c ? c : b;
	}
	cout << b << ' ' << a;

	return 0;
}
