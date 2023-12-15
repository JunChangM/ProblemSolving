#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int n, t;
int ans[10];
int map[10];
void count_number(int x) {
	while (x > 9) {
		ans[x % 10] += pow(10, t);
		x /= 10;
	}
	ans[x] += pow(10, t);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	while (n > 0) {

		while (n > 0 && n % 10 != 9) {
			count_number(n);
			n--;
		}

		if (n == 0) break;

		int temp = n;

		temp = (temp - 9) / 10;
		for (int i = 0; i <= 9; i++) {
			ans[i] += (temp + 1) * pow(10, t);
		}
		ans[0]-= pow(10, t);

		n /= 10;
		t++;
	}

	for (int i = 0; i <= 9; i++) {
		cout << ans[i] << ' ';
	}
}
