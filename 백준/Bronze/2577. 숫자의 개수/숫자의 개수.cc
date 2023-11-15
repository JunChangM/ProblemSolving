#include <iostream>
using namespace std;
int a, b, c;
int number[10];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b >> c;
	a = a * b * c;
	while (a > 9) {
		number[a % 10]++;
		a /= 10;
	}
	number[a]++;
	for (int i = 0; i < 10; i++) {
		cout << number[i] << "\n";
	}
	return 0;
}
