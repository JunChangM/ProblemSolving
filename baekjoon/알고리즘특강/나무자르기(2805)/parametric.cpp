#include <iostream>


using namespace std;

/*
parameter search

*/

int input[1000000];

int main() {

	int n, m, t;
	int answer, mid, left = 0, right = 1000000000;
	long long sum;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> t;
		input[i] = t;
	}

	while (left <= right) {
		sum = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < n; i++) {
			t = input[i] - mid;
			if (t > 0) sum += t;
		}
		// m값 보다 sum이 크다는 것은 충분히 잘랐다는 것을 의미한다.
		// 이때 H를 높여서 sum을 줄여야한다. => left 가 오른쪽으로 이동해야한다.
		if (m <= sum) { 
			answer = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

	}

	cout << answer;

}


