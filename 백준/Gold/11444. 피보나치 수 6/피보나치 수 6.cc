#include <iostream>
#include <map>
#define value 1000000007LL
using namespace std;
long long n;
map<long long, long long> f;

long long fibonacci(long long n) {
	if (n == 0) return 0;
	if (n == 1 || n == 2) return 1;
	if (f.count(n) > 0) return f[n];
	if (n % 2 == 0) {
		long long m = n / 2;
		long long temp1 = fibonacci(m - 1); long long temp2 = fibonacci(m);
		f[n] = ((2LL * temp1 + temp2) * temp2) % value;
		return f[n];
	}
	long long m = (n + 1) / 2;
	long long temp1 = fibonacci(m); long long temp2 = fibonacci(m - 1);
	f[n] = (temp1 * temp1 + temp2 * temp2) % value;
	return f[n];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	cout << fibonacci(n);
	return 0;
}

