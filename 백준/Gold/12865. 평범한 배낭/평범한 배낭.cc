#include <iostream>
#include <algorithm>
using namespace std;
int n, k, w, v;
int bag[101][100001];
int item[101][2];
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> item[i][0] >> item[i][1];
	}

	for (int i = 1; i <= n; i++) {
		w = item[i][0];
		v = item[i][1];
		for (int j = 1; j <= k; j++) {
			if (j < w) bag[i][j] = bag[i - 1][j];
			else {
				bag[i][j] = max(bag[i - 1][j], v + bag[i - 1][j - w]);
			}
		}
	}

	cout << bag[n][k];
	return 0;
}
/*
물건들의 가치 합의 최댓값을 구하자.
n 개의 물건 중에서 최대로 담을 수 있는 무게는 k 이다.
완전 탐색 => n = 100 : 2^100 (fail)
DP[i] => [i] 번째 물건을 닮을 때 i 번째 까지 배당에 넣을 수 있는 최대 가치 (impossible)
=> 무게가 i 인 가방에 넣을 수 있는 최대 가치
*/

