#include <iostream>
using namespace std;
int x, n, c;
long long s, t;
long long input[250001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> x;
	cin >> input[0];
	for (int i = 1; i < n; i++) {
		cin >> t;
		input[i] = input[i - 1] + t;
	}
	s = input[x - 1];
	c = 1;
	for (int i = x; i < n; i++) {
		t = input[i] - input[i - x];
		if (t > s) {
			s = t;
			c = 1;
		}
		else if (t == s)c++;
	}

	if (s == 0) cout << "SAD";
	else cout << s << "\n" << c;
	return 0;
}	
