#include <iostream>
using namespace std;
int n, s;
int input[100000];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	int left = 0, right = 0, amount = 0, leng = 100001;
	while (left <= right && right < n) {
		 //cout << left << ' ' << right << ' ' << amount << endl;
		if (amount < s) {
			amount += input[right++];
		}
		else {
			if (leng > right - left) leng = right - left;
			amount -= input[left++];
		}
	}
	while (left <= right && amount >= s) {
		if (leng > right - left) leng = right - left;
		amount -= input[left++];
	}
	if (leng == 100001) leng = 0;
	cout << leng;
	return 0;
}