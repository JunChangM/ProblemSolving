#include <iostream>
using namespace std;
int n, s;
char arr[1000001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	for (int i = 0; i < s; i++) {
		cin >> arr[i];
	}
	int ans = 0;
	for (int i = 0; i < s; i++) {
		bool flag = 1;
		if (arr[i] == 'I') {
			for (int j = 1; j <= 2 * n; j+=2) {
				if (i + j + 1 >= s || arr[i + j] != 'O' || arr[i + j + 1] != 'I') {
					flag = 0;
					break;
				}
			}
			if (flag == 1) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}

