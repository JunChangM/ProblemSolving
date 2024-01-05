#include <iostream>
using namespace std;
int a, b;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 5; i++) {
		cin >> a;
		b += a * a;
	}
	b %= 10;
	cout << b;
	return 0;
}
