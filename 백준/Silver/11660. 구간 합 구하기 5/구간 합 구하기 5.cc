#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int x1, x2, y3, y2;
int map[1025][1025];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			map[i][j] += map[i - 1][j] + map[i][j - 1] - map[i - 1][j - 1];
		}
	}

	while (m--) {
		cin >> x1 >> y3 >> x2 >> y2;
		cout << map[x2][y2] - map[x1 - 1][y2] - map[x2][y3 - 1] + map[x1 - 1][y3 - 1] << "\n";
	}
	return 0;
}