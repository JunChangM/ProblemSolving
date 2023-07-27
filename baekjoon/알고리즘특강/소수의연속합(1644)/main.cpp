#include <iostream>
#include <vector>
using namespace std;

vector<int> prime;
int map[4000001] = { 1,1 };

int dfs(int n, int index) {
	if (n == 0) return 1;
	if (index < 0) return 0;
	if (n < 0) return 0;
	//cout << n << " " <<  index << endl;
	return dfs(n - prime[index], index - 1);
}


int main() {
	int n; int answer = 0;
	cin >> n;

	/*
	for (int i = 2; i <= n; i++) {
		if (map[i] == 0) {
			prime.push_back(i);
			for (int j = 1; j * i <= n; j++) {
				map[i*j] = 1;
			}
		}
	}
	위의 방식이 더 느림. 다 만들고, 소수 뽑아내야함.
	*/

	for (int i = 2; i * i <= n; i++) {
		if (map[i] == 0) {
			for (int j = 2; j * i <= n; j++) {
				map[i*j] = 1;
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		if (map[i] == 0) prime.push_back(i);
	}

	// 소수 시작 위치
	for (int i = prime.size() - 1; i >= 0; i--) {
		answer += dfs(n, i);
	}

	cout << answer;

	return 0;
}

/*
1. 완전 탐색 : N보다 작은 소수를 모으고, dfs 로 찾기
시간 복잡도 : sqrt(n) + p
2. 투 포인터를 이용한 부분 합의 관점에서도 볼 수 있음.
*/
