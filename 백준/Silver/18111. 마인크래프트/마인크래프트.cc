#include <iostream>

using namespace std;
int n, m, b, t, ans, anst;
int map[501][501];

int high() {
	int value = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			value = map[i][j] > value ? map[i][j] : value;
		}
	}
	return value;
}
void find(int v) {
	int time = t;
	int block = b;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int gap = v - map[i][j];

			block -= gap;

			if (block < 0) {
				return;
			}

			time += gap;

		}
	}

	if (time < anst) {
		anst = time;
		ans = v;
	}
}
void f() {
	int h = high();
	find(h);
	
	while (h != 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == h) {
					map[i][j]--;
					t += 2;
					b++;
				}
			}
		}
		h--;
		find(h);
	}
	
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	anst = 100000000;
	f();

	cout << anst << ' ' << ans;
}

