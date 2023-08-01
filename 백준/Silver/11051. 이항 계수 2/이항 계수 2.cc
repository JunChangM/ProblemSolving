#include <iostream>
#define r 10007
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	if (n / 2 < k) k = n - k;

	long long answer = 1;

	int t = k;
	while (t--) {
		answer *= n;
		answer %= r;
		while (answer % k != 0) {
			answer += r;
		}
		answer /= k;
		n -= 1;
		k -= 1;
	}
	

	
	answer %= r;

	cout << answer;
	return 0;
}