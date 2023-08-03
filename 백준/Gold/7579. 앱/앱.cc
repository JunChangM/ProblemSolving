#include <iostream>
#include <vector>
#include <algorithm>
#define N 1000000
using namespace std;
int n, m;
int input[101][2]; // m , c
int dp[101][10001]; // N C 
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input[i][0];
	}
	for (int i = 0; i < n; i++) {
		cin >> input[i][1];
	}
	for (int i = 0; i <= 10000; i++) {
		dp[0][i] = input[0][1] <= i ? input[0][0] : 0;
	}

	for (int i = 1; i < 100; i++) {
		for (int j = 0; j <= 10000; j++) {
			int restcost = j - input[i][1];
			if (restcost < 0) dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = input[i][0] + dp[i - 1][restcost] > dp[i - 1][j] ? input[i][0] + dp[i - 1][restcost] : dp[i - 1][j];
			}
			
		}
	}
	int temp = 10001;
	int maxm = 0;
	for (int i = 0; i <= 10000; i++) {
		// cout << dp[n - 1][i] << " ";
		if (dp[n - 1][i] >= m) {
			maxm = dp[n - 1][i];
			temp = i;
			break;
		}
		
	}

	cout << temp;
}
/*

		*/