// 메모리: 2208 KB, 시간: 684 ms
#include <iostream>
#include <string>
using namespace std;
int n, m, t;
bool remote[10]; 
bool check(int x) {
	if (x == 0 && remote[0]) return false;
	while (x != 0) {
		if (remote[x % 10]) return false;
		x /= 10;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> t;
		remote[t] = true;
	}
	t = abs(n - 100);
	for (int i = 0; i <= 999999; i++) {
		if (check(i)) {
			int temp = abs(n - i) + to_string(i).size();
			t = t < temp ? t : temp;
		}
	}
	cout << t;
	return 0;
}

