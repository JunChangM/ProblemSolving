#include <iostream>
#include <algorithm>
using namespace std;
long long m, amount;
int n, input[10000];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
		amount += input[i];
	}
	cin >> m;
	sort(input, input + n);

	if (m >= amount) {
		cout << input[n-1];
	}

	else {
		long long left = 1;
		long long right = input[n - 1];
		long long mid = 0;
		long long temp;
		long long remain = m;
		long long result;
		while (left <= right) {
			temp = m;
			mid = (left + right) / 2;
			for (int i = 0; i < n; i++) {
				temp -= min((long long)input[i], mid);
			}
			if (temp >= 0) {
				left = mid + 1;
				if (temp < remain) {
					remain = temp;
					result = mid;
				}
			}
			else right = mid - 1;
		}
		cout << result;
	}
	
	return 0;
}	