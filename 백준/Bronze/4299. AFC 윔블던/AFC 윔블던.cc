#include <iostream>
using namespace std;
long long a, b, c, d;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b;
	if ((a + b) % 2 == 0) {
		c = (a + b) / 2;
		d = a - c;
		if (c >= 0 && d >= 0)
			cout << c << ' ' << d;
		else cout << -1;
	}
	else cout << -1;
}

