#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int h, m;
	cin >> h >> m;
	if (m >= 45) {
		m -= 45;
	}
	else {
		if (h >= 0) {
			h -= 1;
			m += 15;
		}
		if (m >= 60) {
			h += 1;
			m -= 60;
		}
		if (h == -1) h = 23;
		
	}
	cout << h << ' ' << m;

	return 0;
}
