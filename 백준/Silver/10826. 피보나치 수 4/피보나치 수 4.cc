#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int n;
string f[10001];
string sum(string x, string y) {
	string z;
	int num, carry;
	carry = 0;
	while (x.length() < y.length()) {
		x += '0';
	}
	while (x.length() > y.length()) {
		y += '0';
	}
	for (int i = 0; i < x.length(); i++) {
		num = (x[i] - '0') + (y[i] - '0') + carry;
		carry = num / 10;
		num = num % 10;
		
		z += to_string(num);
	}
	if (carry != 0) z += to_string(carry);
	return z;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	f[0] = '0';
	f[1] = '1';
	for (int i = 2; i <= n; i++) {
		f[i] = sum(f[i - 1], f[i - 2]);
	}
	reverse(f[n].begin(), f[n].end());
	cout << f[n];
	return 0;
}