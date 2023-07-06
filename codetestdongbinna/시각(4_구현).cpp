// 4-2 시각

#include <iostream>

using namespace std;


int check(int num) {
	// 10의 자리
	if (int(num / 10) == 3) return 1;

	// 1의 자리
	if (num % 10 == 3) return 1;

	return 0;
}


int main() {
	int n;
	cin >> n;

	int h = 0, m = 0, s = 0, count = 0;
	while (h <= n) {
		if (check(s) || check(m) || check(h)) count += 1;
		s += 1;
		if (s == 60) {
			s -= 60;
			m += 1;
		}

		if (m == 60) {
			m -= 60;
			h += 1;
		}

		

	}
	cout << count << endl;
	return 0;
}
