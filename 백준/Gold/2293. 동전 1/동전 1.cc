#include <iostream>
#include <algorithm>
using namespace std;
int n, k, t, ans;
int coin[100];
int value[10001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	sort(coin, coin + n);
	for (int i = 0; i < n; i++) {
		int start = coin[i];

		// 다른 코인 조합
		for (int j = 1; j + start <= k; j++) {
			value[j + start] += value[j];
		}

		// 단일 코인
		for (int j = 1; start * j <= k; j++) {
			value[start * j]++;
		}
		
	}

	cout << value[k];

	return 0;
}
