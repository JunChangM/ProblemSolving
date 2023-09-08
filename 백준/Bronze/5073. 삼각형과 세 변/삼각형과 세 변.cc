#include <iostream>
#include <algorithm>
using namespace std;
int a, b, c;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b >> c;
	while (a != 0  && b != 0 && c != 0) {
		int temp = max({ a,b,c });
		if (a == b && b == c) cout << "Equilateral\n";
		else if (a == b || b == c || a == c) {
			if (a + b + c - temp <= temp) cout << "Invalid\n";
			else cout << "Isosceles\n";
		}
		else {
			if (a + b + c - temp <= temp) cout << "Invalid\n";
			else cout << "Scalene\n";
		}
		cin >> a >> b >> c;
	}
	return 0;
}