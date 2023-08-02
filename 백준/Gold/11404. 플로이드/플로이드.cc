#include <iostream>
#include <algorithm>
#define INF 100000000
using namespace std;
int n, m;
int a, b, c;
int map[101][101];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = INF;
		}
	}

	for (int i = 1; i <= n; i++) map[i][i] = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (map[a][b] == 0) map[a][b] = c;
		else {
			if (c < map[a][b]) map[a][b] = c;
		}
	}
	// f
	for (int k = 1; k <= n; k++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				map[s][e] = min(map[s][e], map[s][k] + map[k][e]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++){
			if (map[i][j] == INF) cout << 0 << " ";
			else cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}