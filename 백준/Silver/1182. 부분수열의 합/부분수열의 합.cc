#include <iostream>
using namespace std;
int n, s, input[20], ans;
void dfs(int x, int depth) {
	if (depth == n) {
		if (s == x) ans++;
		return;
	}
	dfs(x + input[depth], depth + 1);
	dfs(x, depth + 1);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> input[i];
	dfs(0, 0);
	if (s == 0) ans--;
	cout << ans;
    return 0;
}
/*
부분 수열 : 수열의 순서가 보장이 되어야 한다.
*/