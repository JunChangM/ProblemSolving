#include <iostream>
using namespace std;
int a, b, c;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (cin >> a >> b >> c)
	{
		if (a == 0 && b == 0 && c == 0) break;
		if (a < b) {
			int t = a;
			a = b;
			b = t;
		}
		if (a < c) {
			int t = a;
			a = c;
			c = t;
		}
		if (a * a == b * b + c * c) cout << "right\n";
		else cout << "wrong\n";



	}
	return 0;
}
