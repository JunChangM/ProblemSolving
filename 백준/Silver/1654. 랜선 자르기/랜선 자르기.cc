#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int k, n;
long long l, r, mid, ans;
int input[10000];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> input[i];
	}
	sort(input, input + k);
	ans = 1;
	l = 1;
	r = input[k - 1];
	
	while (l <= r) {
		int temp = 0;
		mid = (l + r) / 2;
		for (int i = 0; i < k; i++) {
			temp += input[i] / mid;
		}

		if (temp >= n) {
			ans = max(ans, mid);
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans;

	return 0;
}
