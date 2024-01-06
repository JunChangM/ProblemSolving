#include <iostream>
using namespace std;
int n;
int check() {
	if (n % 4 != 0) return 0;
	if (n % 100 != 0 || n % 400 == 0) return 1;
	return 0;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	cout << check();

	return 0;
}
