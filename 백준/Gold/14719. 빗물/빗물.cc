#include <iostream>
using namespace std;
int h, w, ans;
int input[501];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> h >> w;
	input[0] = -1;
	for (int i = 1; i <= w; i++) cin >> input[i];
	for (int i = 1; i <= w; i++) {
		int height = 0;
		for (int j = i + 1; j <= w; j++) {
			if (input[height] < input[j]) height = j;
			if (input[j] >= input[i]) {
				ans += input[i] * (j - i - 1);
				for (int k = i + 1; k < j; k++) ans -= input[k];
				i = j - 1;
				break;
			}
			else if (j == w ) {
				ans += input[height] * (height - i - 1);
				for (int k = i + 1; k < height; k++) ans -= input[k];
				i = height - 1;
			}
		}
	}
	cout << ans;
	return 0;
}

