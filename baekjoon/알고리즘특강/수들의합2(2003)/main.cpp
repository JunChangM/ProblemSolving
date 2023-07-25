#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
N = 10000
M = 300,000,000
A[N] 의 부분 수열의 합이 M이 되도록한다.
1. 좌우 포인터를 이용하여 근접하게 계산하기
최악의 경우 2 * N = 20,000 번 < 0.5초

*/

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> A;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		A.push_back(t);
	}

	int left = 0, right = 0, sum = 0, answer = 0;

	while (right < N) {
		if (sum == M) {
			answer += 1;
			sum -= A[left++];
			sum += A[right++];
		}
		else if(sum < M) {
			sum += A[right++];
		}
		else { // sum > M
			sum -= A[left++];
		}
	}

	while (left < right) {
		if (sum == M) {
			answer += 1;
		}
		sum -= A[left++];

		if (sum < M) break;
	}


	cout << answer;

	return 0;
}
