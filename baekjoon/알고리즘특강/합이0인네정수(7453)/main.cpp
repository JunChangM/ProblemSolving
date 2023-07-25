
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
hashmap은 기본적으로 hash function을 사용한다.
hashmap이 일반적인 경우에는 O(1) 이지만, key 값의 범위가 큼에따라 중복값이 많아 충돌이 일어나면, 뒤에 따라붙는 O(K)만큼 발생할 수 있다.
다른 방법을 사용하여야 한다.

합이 0인 네 정수
배열의 크기가 N인 A,B,C,D의 배열 , 최대 4000 * 4 = 16000
정수의 절댓값은 최대 2^28

1. 완전탐색
4000^4 = 64,000,000,000,000 => 64,000 초 => 불가능

2.
A와 B, C와 D를 묶는다 => 4000 * 4000 = 16,000,000개의 경우 2개

뒤의 항만 sorting 한후
sorting이 가능한가? Nlog N = 16000000 * 24 == 4억 8천만 => 약 5초 걸림.

100이면 -101이 몇개가 존재하는지 찾으면 된다. => 이분탐색 => lower_bound, upper_bound => log N 
=> 가능

*/


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, a, b, c, d;
	cin >> n;

	int A[4000], B[4000], C[4000], D[4000];


	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d;
		A[i] = a; B[i] = b; C[i] = c; D[i] = d;
	}

	int X[16000000], Y[16000000];

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			X[i * n + k] = A[i] + B[k];
			Y[i * n + k] = C[i] + D[k];
		}
	}
	
	int nn = n * n;
	sort(Y, Y + nn);

	long answer = 0;
	long start, end;
	// 이진탐색
	for (int i = 0; i < nn; i++) {
		//  count 하는 binary_search 필요
		// 일일이 세면 안됨.
		// 처음 나오는 위치와 마지막에 나오는 위치 찾기
		// c 언어에서는 지원해줌
		start = lower_bound(Y, Y + nn, -X[i]) - Y;
		end = upper_bound(Y, Y + nn, -X[i]) - Y;

		start += (Y[start] != -X[i]); // start가 값과 다른 경우
		end -= (end == nn || Y[end] != -X[i]); // 맨 끝까지 갔던가, end가 값과 다른 경우
		if (end >= start) {
			answer += end - start + 1;
		}
	}


	cout << answer;
}
