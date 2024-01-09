#include <iostream>
using namespace std;
int t, a, b, c;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		int d = c / a;
		int e = c - d * a;
		if (e == 0) e = a;
		if (c % a != 0) d++;
		cout << e * 100 + d << '\n';
	}
	return 0;
}
