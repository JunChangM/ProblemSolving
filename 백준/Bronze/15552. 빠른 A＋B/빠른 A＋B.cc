#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, a, b;
	cin >> n ;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		cout << a + b << '\n';
	}
	return 0;
}
