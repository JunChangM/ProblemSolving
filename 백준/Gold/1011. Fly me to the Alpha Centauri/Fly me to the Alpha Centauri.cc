#include <iostream>
#include <cmath>
using namespace std;
int t;
long long x, y;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> x >> y;
		double d = y - x; // 두 지점 사이의 거리
		double dpow = sqrt(d); // 거리의 제곱근
		int pow = round(sqrt(d)); // 거리의 제곱근을 반올림

		if (dpow <= pow) cout << pow * 2 - 1 << "\n";
		else cout << pow * 2 << "\n";
	}

	return 0;
}
