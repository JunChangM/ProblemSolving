#include <iostream>
using namespace std;
int n;
int ans[42];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 10; i++) {
		cin >> n;
		ans[n % 42]++;
	}
	n = 0;
	for (int i = 0; i <= 41; i++) {
		if (ans[i] != 0) n++;
	}
	cout << n;

	return 0;
}
