#include <iostream>
#include <algorithm>
using namespace std;
int a, b, c, d;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b >> c;
	if (a == b && b == c) {
		d = 10000 + a * 1000;
	}
	else if (a == b) {
		d = 1000 + 100 * a;
	}
	else if (c == b) {
		d = 1000 + 100 * b;
	}
	else if (a == c) {
		d = 1000 + 100 * a;
	}
	else {
		d = max({ a,b,c }) * 100;
	}
	cout << d;
	return 0;
}
