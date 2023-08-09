#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
string str;
int s, ans;
int dp[51][51]; // dp[left][right] : left ~ right 까지 팰린드롬하는데 필요한 최소 비용
int factory(int left, int right, string temp) {
	if (dp[left][right] != -1) return dp[left][right];
	if (left >= right) return 0;
	int& x = dp[left][right];
	x = min({ factory(left + 1, right, temp) + 1, factory(left, right - 1, temp) + 1, 
		factory(left + 1,right - 1, temp) + (temp[left] != temp[right]) });
	return x;
}
int main() {
	cin >> str;
	s = str.size();
	memset(dp, -1, sizeof(dp));
	ans = factory(0, s - 1, str);
	// 4번 조건 처리
	for (int i = 0; i < s; i++) {
		for (int j = i + 1; j < s; j++) {
			memset(dp, -1, sizeof(dp));
			string temp = str;
			swap(temp[i], temp[j]);
			ans = min(ans, factory(0, s - 1,temp) + 1); // swap 횟수 + 1
		}
	}
	cout << ans;
}