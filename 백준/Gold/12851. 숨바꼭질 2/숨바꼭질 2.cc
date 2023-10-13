#include <iostream>
#include <algorithm>
using namespace std;
int n, k, c,ans;
int p[100001];
int num[100001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	if (n >= k) cout << n - k << "\n" << 1;
	else { // n < k
		for (int i = n; i >= 0; i--) {
			p[i] = n - i;
			num[i] = 1;
		}
		for (int i = n + 1; i <= 100000; i++) {
			if (i > 2 * k) break;
			if (i % 2 == 0) {
				if (p[i - 1] == p[i / 2]) {
					p[i] = p[i - 1] + 1;
					num[i] = num[i - 1] + num[i / 2];
				}
				else if (p[i - 1] < p[i / 2]) {
					p[i] = p[i - 1] + 1;
					num[i] = num[i - 1];
				}
				else {
					p[i] = p[i / 2] + 1;
					num[i] = num[i / 2];
				}
				for (int j = i - 1; j >= i / 2; j--) {
					if (p[j] <= p[j + 1] + 1) {
						if (p[j] == p[j + 1] + 1) num[j] += num[j + 1];
						break;
					}
					p[j] = p[j + 1] + 1;
					num[j] = num[j + 1];
				}
			}
			else{
				p[i] = p[i - 1] + 1;
				num[i] = num[i - 1];
				
			}
			// cout << i << ' ' << p[i] << ' ' << num[i] << "\n";
		}
		cout << p[k] << "\n" << num[k];
	}
	return 0;
}

// 0 3 -> 3 2