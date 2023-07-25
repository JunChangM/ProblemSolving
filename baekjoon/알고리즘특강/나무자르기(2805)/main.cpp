#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
나무 자르기
나무의 수 N, 필요한 나무의 높이 M
(1 ≤ N ≤ 1,000,000, 1 ≤ M ≤ 2,000,000,000) int 는 21억까지 가능
나무의 높이의 합은 항상 M보다 크거나 같다.
시간 :  1,000,000 * 2,000 = 2,000,000,000 = 20억
중복되는 경우 지나쳐야함.
*/


int main() {
	int N;
	unsigned int M;

	cin >> N >> M;
	vector<int> tree;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		tree.push_back(t);
	}
	sort(tree.begin(), tree.end(),greater<int>());  // 내림차순 정렬

	unsigned int sum = 0;
	int H = tree[0] - 1; 
	int over = 1;
  
  // H값을 하나씩 줄여가면서 잘릴 수 있는 나무의 수 (over)을 더하면서 sum을 구했다.
  // H값을 이전 값과의 차이를 이용하여 구하면 조금 더 빨리 할 수 있을 것이다.
	while (sum < M) {

		for (int i = over; i < N; i++) {
			if (tree[i] > H) over += 1;
			else break;
		}
		sum += over;
		H -= 1;

	}

	cout << H+1;

}

/*
이분탐색을 이용해보자. => 가상의 배열 (parametric search)
10억의 size를 갖는 가상의 배열 (각각의 index에 들어갈 값은 index를 h로 잡았을 때, 상근이가 가져갈 수 있는 나무의 길이의 합 )
이 가상의 배열은 내림차순으로 들어갈 것이다.
H 가 올라갈 수록 가져갈 나무는 줄어든다.
5억의 index를 딱 찍어보자.
그 H (=index)를 기준으로 나무를 훑으면서 길이를 구한다 => gettree의 값과 M값을 비교하여 작으면 index 낮추고, 크면, index 높이는 방식.
시간 복잡도 :  N * log 10억 => N * 19
parametric search를 의심할 만한 상황 => 값의 범위가 크고, 값이 증가하거나 감소하는 추세를 가질 때, 의심해 볼만 하다.
*/
