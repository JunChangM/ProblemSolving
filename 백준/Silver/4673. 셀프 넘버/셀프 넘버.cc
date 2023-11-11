#include <iostream>
using namespace std;
int number[10000];
int digit(int x) {
	int s = 0;
	while (x != 0) {
		s += x % 10;
		x /= 10;
	}
	return s;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 1; i < 10000; i++) {
		if (number[i] == 0) {
			int sum = i + digit(i);
			while (sum < 10000) {
				number[sum] = 1;
				sum = sum + digit(sum);
			}
		}
	}
	for (int i = 1; i < 10000; i++) {
		if (number[i] == 0) {
			cout << i << "\n";
		}
	}
	return 0;
}

