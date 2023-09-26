#include <iostream>
using namespace std;
int h, w, ans;
int input[501];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> h >> w;
	input[0] = -1;
	for (int i = 1; i <= w; i++) {
		cin >> input[i];
	}
	for (int i = 1; i <= w; i++) {
		int height = 0;
		for (int j = i + 1; j <= w; j++) {
			if (input[height] < input[j]) {
				height = j;
			} 
			if (input[j] >= input[i]) {
				ans += input[i] * (j - i - 1);
				for (int k = i + 1; k < j; k++) ans -= input[k];
				// cout << i << ' ' << j << ' ' << input[i] << ' ' << input[j] << ' ' << ans << endl;
				i = j - 1;
				break;
			}
			else if (j == w ) {
				// 끝까지 없으면 그 전까지 제일 높은애의 index check 
				ans += input[height] * (height - i - 1);
				for (int k = i + 1; k < height; k++) ans -= input[k];
				//cout << i << ' ' << j << ' ' << input[i] << ' ' << input[j] << ' ' << ans << endl;
				i = height - 1;

			}
		}
	}

	cout << ans;


	return 0;
}
/*
1. 빗물을 채우고 안되는 부분을 지워나간다 => N^2
*/
