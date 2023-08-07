#include <iostream>
using namespace std;
int n;
long long f[91];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	cout << f[n];
	return 0;
}