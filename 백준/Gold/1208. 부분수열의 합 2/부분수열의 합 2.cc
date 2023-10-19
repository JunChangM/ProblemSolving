#include <iostream>
#include <map>
using namespace std;
int n, s, a[40];
long long ans;
map<int, int> leftsum;
void left(int x, int depth) {
	if (depth == n/2) {
		leftsum[x]++;
		return;
	}
	left(x + a[depth], depth + 1);
	left(x, depth + 1);
}
void right(int x, int depth) {
	if (depth == n) {
		ans += leftsum[s - x];
		return;
	}
	right(x + a[depth], depth + 1);
	right(x, depth + 1);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> a[i];
	left(0, 0);
	right(0, n / 2);
	if (s == 0) ans--;
	cout << ans;
    return 0;
}
/*
부분 수열 : 수열의 순서가 보장이 되어야 한다.
*/