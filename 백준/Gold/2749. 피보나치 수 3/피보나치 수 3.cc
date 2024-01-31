#include <iostream>
#define mod 1000000
using namespace std;
long long n;
const int P = 15 * (mod / 10); // 피사노 주기
long long arr[P];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	arr[1] = 1;

	for (int i = 2; i < P; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % mod;
	}

	cout << arr[n % P];

	return 0;
}

