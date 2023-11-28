#include <iostream>
using namespace std;
int n, m, ans;
int input[100];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int temp = input[i] + input[j] + input[k];
				if (temp > ans && temp <= m) {
					ans = temp;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
