#include <iostream>
using namespace std;
int n, m, ans;
char map[50][50];

void check(int x, int y) {
	int count = 0;

	for (int i = 0; i < 8; i += 2) {
		for (int j = 0; j < 8; j += 2) {
			if (map[x][y] != map[x + i][y + j]) {
				count++;
			}
		}
	}

	for (int i = 1; i < 8; i += 2) {
		for (int j = 1; j < 8; j += 2) {
			if (map[x][y] != map[x + i][y + j]) {
				count++;
			}
		}
	}

	for (int i = 0; i < 8; i += 2) {
		for (int j = 1; j < 8; j += 2) {
			if (map[x][y] == map[x + i][y + j]) {
				count++;
			}
		}
	}

	for (int i = 1; i < 8; i += 2) {
		for (int j = 0; j < 8; j += 2) {
			if (map[x][y] == map[x + i][y + j]) {
				count++;
			}
		}
	}

	count = count < 64 - count ? count : 64 - count;
	ans = ans < count ? ans : count;

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ans = 65;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			check(i, j);
		}
	}

	cout << ans;

	return 0;
}

