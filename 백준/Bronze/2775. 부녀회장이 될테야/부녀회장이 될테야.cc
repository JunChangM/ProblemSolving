#include <iostream>
using namespace std;

int g(int x, int y) {
	if (y == 1) {	
		return 1;
	}
	else if (x == 0) {
		return y;
	}
	else {
		return (g(x - 1, y) + g(x, y - 1));
	}
}

int main() {
	int t, k, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> k >> n;
		cout << g(k, n) << endl;
	}
}
