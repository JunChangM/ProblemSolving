#include <iostream>
#include <string.h>
using namespace std;
int map[15][15];
int dp[1<<15][15][15]; // [vistied][current][cost]
int n, flag = 0;
char c;
int f(int visited, int current, int cost) {
	if (dp[visited][current][cost] != 0) return dp[visited][current][cost];

	for (int i = 1; i < n; i++) {
		if (!(visited & (1 << i)) && map[current][i] >= cost) {
			int nextvisited = visited | (1 << i);
			dp[visited][current][cost] = max(dp[visited][current][cost], f(nextvisited,i,map[current][i]) + 1);
		}
	}

	return dp[visited][current][cost];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			map[i][j] = c - '0';
		}
	}

	f(1, 0, 0);

	cout << dp[1][0][0] + 1;
	
	
}