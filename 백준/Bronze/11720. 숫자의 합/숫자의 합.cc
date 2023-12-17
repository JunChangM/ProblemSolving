#include <iostream>
using namespace std;
int n, a;
char c;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		a += c - '0';
	}

	cout << a;

	return 0;
}
