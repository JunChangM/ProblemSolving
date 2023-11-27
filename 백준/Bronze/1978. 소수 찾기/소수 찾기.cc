#include <iostream>
using namespace std;
int n, a, ans;
bool field[1001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	field[1] = true;
	for (int i = 2; i < 1001; i++) {
		for (int j = 2; j < 1001; j++) {
			if (i * j <= 1000) {
				field[i * j] = true;
			}
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (field[a] == false) ans++;
	}
	cout << ans;

	return 0;
}
