#include <iostream>
#include <algorithm>
using namespace std;
int n, a;
int input[301];
int dp[301];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> input[i];
	}
	dp[1] = input[1];
	dp[2] = max(input[1] + input[2], input[2]);
	dp[3] = max(input[1] + input[3], input[2] + input[3]);

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + input[i], dp[i - 3] + input[i - 1] + input[i]);
	}
	cout << dp[n];
}