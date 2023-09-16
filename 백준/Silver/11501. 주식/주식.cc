#include <iostream>
using namespace std;
int t, n;
int input[1000000];
int maxbehind[1000000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> input[i];
		int m = input[n - 1];
		maxbehind[n - 1] = m;
		for (int i = n - 2; i >= 0; i--) {
			if (m < input[i]) m = input[i];
			maxbehind[i] = m;
		}
		long long sum = 0;
		for (int i = 0; i < n; i++) sum += (maxbehind[i] - input[i]);
		cout << sum << "\n";
	}
	return 0;
}	
