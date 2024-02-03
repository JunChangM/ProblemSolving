#include <iostream>
#include <stack>
using namespace std;
int n, ans, a;
stack <int> s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 0) {
			s.pop();
		}
		else {
			s.push(a);
		}
	}
	while(!s.empty()) {
		ans += s.top();
		s.pop();
	}
	cout << ans;

	return 0;
}

