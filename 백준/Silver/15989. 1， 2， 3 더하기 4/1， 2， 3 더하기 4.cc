#include <iostream>
using namespace std;
int t, n;
int memo[10001][3];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memo[1][0] = 1; memo[1][1] = 0; memo[1][2] = 0;
	memo[2][0] = 1; memo[2][1] = 1; memo[2][2] = 0;
	memo[3][0] = 1; memo[3][1] = 1; memo[3][2] = 1;

	for (int i = 4; i <= 10000; i++) {
		memo[i][0] = memo[i - 1][0];
		memo[i][1] = memo[i - 2][0] + memo[i - 2][1];
		memo[i][2] = memo[i - 3][0] + memo[i - 3][1] + memo[i - 3][2];
	}

	cin >> t;
	while (t--) {
		cin >> n;
		cout << memo[n][0] + memo[n][1] + memo[n][2] << "\n";
	}
	return 0;
}	
/*
i 가 1으로 끝나는 경우 i - 1 의 1 로 끝나는 경우
i 가 2으로 끝나는 경우 i - 2 의 1 로 끝나는 경우 + 2 로 끝나는 경우
i 가 3으로 끝나는 경우 i - 3 의 1,2,3으로 끝나는 경우
*/