#include <iostream>
#define INF 1000000
using namespace std;
int dp[2501];
bool p[2501][2501];
string input;

void fillp() {
	int len = input.size();
	input = " " + input;
	for (int i = 1; i <= len; i++) p[i][i] = true;
	for (int i = 1; i < len; i++) if (input[i] == input[i + 1]) p[i][i + 1] = true;
	for (int leng = 3; leng <= len; leng++) {
		for (int start = 1; start + leng - 1 <= len; start++) {
			int end = start + leng - 1;
			if (input[start] == input[end] && p[start + 1][end - 1] == true) p[start][end] = true;

		}
	}
	for (int i = 1; i <= len; i++) dp[i] = INF;
	for (int end = 1; end <= len; end++) {
		for (int start = 1; start <= end; start++) {
			if (p[start][end] == true) {
				dp[end] = min(dp[end], dp[start - 1] + 1);
			}
		}
	}

	cout << dp[len];
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> input;
	fillp();
	return 0;
}