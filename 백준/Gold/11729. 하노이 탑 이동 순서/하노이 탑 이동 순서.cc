#include <iostream>
using namespace std;
void move(int n, int s, int mid, int e) {
	if (n == 1) cout << s << ' ' << e << "\n";
	else {
		move(n - 1, s, e, mid);
		cout << s << ' ' << e << "\n";
		move(n - 1, mid, s, e);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	cout << (1 << n) - 1 << "\n";
	move(n, 1, 2, 3);
	return 0;
}

