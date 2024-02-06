#include <iostream>
using namespace std;
int t, n;
long long map[101];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	map[1] = 1;
	map[2] = 1;
	map[3] = 1;
	for (int i = 4; i < 101; i++) {
		map[i] = map[i - 2] + map[i - 3];
	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout << map[n] << '\n';
	}

	return 0;
}

