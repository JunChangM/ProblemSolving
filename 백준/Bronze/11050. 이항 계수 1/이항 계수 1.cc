#include <iostream>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	int answer = 1;
	int t = k;
	while (t--) {
		answer *= n;
		n -= 1;
	}
	t = k;
	while(t--) {
		answer /= k;
		k -= 1;
	}
	cout << answer;
	return 0;
}