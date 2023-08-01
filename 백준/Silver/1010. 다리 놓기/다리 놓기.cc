#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, t, k;
	long long answer;
	cin >> t;
	while (t--)
	{
		cin >> n >> m; // m C n
		answer = 1;
		if (m / 2 < n) n = m - n;
		k = n;
		while (k--) {
			answer *= m;
			m -= 1;
		}
		k = n;
		while (k--) {
			answer /= n;
			n -= 1;
		}
		cout << answer << "\n";
	}
	

}