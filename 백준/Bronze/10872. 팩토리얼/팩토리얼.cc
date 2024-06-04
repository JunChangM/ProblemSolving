#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long a = 1;
	int n;
	cin >> n ;
	for (int i = 1; i <= n; i++) a *= i;
	if (n == 0) cout << 1;
	else cout << a;
	return 0;
}
