#include <iostream>
using namespace std;
int a, b, c;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 10; i++) {
		c = a; // before
		cin >> b;
		a += b; // after
		if (a > 100) {
			if (a - 100 <= 100 - c) {
				cout << a;
			}
			else cout << c;
			return 0;
		}
	}
	cout << a;
	
	return 0;
}
		
