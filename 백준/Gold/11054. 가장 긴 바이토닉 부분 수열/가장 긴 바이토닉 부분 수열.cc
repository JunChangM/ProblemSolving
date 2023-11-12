#include <iostream>
#include <algorithm>
using namespace std;
int n;
int input[1001];
int input2[1001];
int dp[1001];
int dp2[1001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> input[i];
	}
	
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		int dp_value = 0;
		for (int j = 1; j < i; j++) {
			if (dp[j] > dp_value && input[j] < input[i]) {
				dp_value = dp[j];
			}
		}
		dp[i] = dp_value + 1;
	}
	
	for (int i = n; i >= 1; i--) {
		input2[n - i + 1] = input[i];
	}

	dp2[1] = 1;
	for (int i = 2; i <= n; i++) {
		int dp_value = 0;
		for (int j = 1; j < i; j++) {
			if (dp2[j] > dp_value && input2[j] < input2[i]) {
				dp_value = dp2[j];
			}
		}
		dp2[i] = dp_value + 1;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = ans > dp[i] + dp2[n - i + 1] - 1 ? ans : dp[i] + dp2[n - i + 1] - 1;
	}
	cout << ans;

	return 0;
}
/*
가장 긴 증가하는 부분 수열
method 1)
dp[i]: A[i]로 끝나는 가장 긴 증가하는 부분 수열의 길이
dp[i]는 0 ~ i-1까지 인덱스를 가지는 원소 중 값은 A[i] 보다 작으면서 가장 큰 dp 값을 가지는 원소에 1을 더한 값이다.
=> O(N^2)
*/

