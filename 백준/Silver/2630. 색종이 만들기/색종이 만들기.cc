#include <iostream>
using namespace std;
int n, w, b;
int map[129][129];
void divide_and_conquer(int x, int left, int right) {
	if (x == 1) {
		if (map[left][right] == 1) b++;
		else w++;
	}
	else {
		int bflag = 1;
		for (int i = left; i < left + x; i++) {
			for (int j = right; j < right + x; j++) {
				if (map[i][j] == 0) {
					bflag = 0;
					break;
				}
			}
		}
		if (bflag == 0) {
			int wflag = 1;
			for (int i = left; i < left + x; i++) {
				for (int j = right; j < right + x; j++) {
					if (map[i][j] == 1) {
						wflag = 0;
						break;
					}
				}
			}
			if (wflag == 0) { // b 와 w 혼합 상태
				divide_and_conquer(x / 2, left, right);
				divide_and_conquer(x / 2, left + x / 2, right + x / 2);
				divide_and_conquer(x / 2, left + x / 2, right);
				divide_and_conquer(x / 2, left, right + x / 2);

			}
			else {
				w++;
			}

		}
		else {
			b++;
		}
	}
	
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	divide_and_conquer(n,1,1);

	cout << w << '\n' << b;

	return 0;
}
