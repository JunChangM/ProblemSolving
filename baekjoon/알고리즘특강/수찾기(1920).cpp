#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;


int main() {
  	//  시간 초과 -> 입력 받는데 시간이 오래 걸린다.
	// c와 c++ 입출력 스트림의 동기화를 해제하여 c++만 사용하게 함으로써
	// 입출력 속도를 높인다. + endl 보다 "\n"이 속도가 더 빠르다.  (endl은 출력 버퍼를 비우는 역할까지 담당하여 오래 걸린다.)
  // <https://www.acmicpc.net/board/view/22716>
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N;
	vector<int> A;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		A.push_back(temp);
	}
	sort(A.begin(), A.end());


	// 이 수가 A안에 존재하는지 확인.
	// 정렬된 A에 대하여 이분 탐색 진행
	// 있으면 1 없으면 0

	cin >> M;
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		if (binary_search(A.begin(), A.end(), temp)) cout << "1\n";
		else cout << "0\n";
	}

	return 0;
}


/*
입력을 주는 M(쿼리의 수)는 줄일 수 있는 방법이 없다.
N번 훑는 것을 빠르게 할 수 있는 방법을 찾아야한다.
M이 10만이면 (Log N) 을 통해 19 * 10만 정도는 가능할 것이다.
counting 배열을 이용하면 O(n)으로 해결이 가능하지만, 이 경우 int의 범위가 +- 2^31제곱으로 42억개의 int형 메모리가 필요 => 불가능
(MlogN)으로 해결하려면 이분탐색이 필요하다. 이때 정렬이 필요하다. => 190만의 연산 + 190만의 연산 => 380만의 연산 => 가능


*/
