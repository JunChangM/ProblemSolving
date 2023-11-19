#include <iostream>
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	int a = 1;
	while (a * (a + 1) / 2 < n) {
		a++;
	}
	int m = n - (a - 1) * a / 2;
	if (a % 2 != 0) {
		cout << a - m + 1 << '/' << m ;
	}
	else
		cout << m << '/' << a - m + 1;

	return 0;
}
