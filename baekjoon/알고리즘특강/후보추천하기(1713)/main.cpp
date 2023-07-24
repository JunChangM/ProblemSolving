#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	// 시간제한 2초 => 2억번의 연산 가능
	// N 개의 사진틀, 몇 번 추천 받았는가, 언제 추천 받았는가

	int N, total;
	cin >> N >> total;

	vector<vector<int>> map;
	map.resize(N, vector<int>(3, 0)); // (학생의 번호, 추천 횟수, 게시한 순서)

	for (int i = 0; i < total; i++) {
		int temp, k;
		cin >> temp;
		for (k = 0; k < N; k++) {
			if (map[k][0] == 0 || map[k][0] == temp) {
				break;
			}
		}
		if (k != N) { // 사진틀에 자리가 있는 경우 또는 이미 있는 경우
			if (map[k][0] == temp) {
				map[k][1] += 1;
			}
			else {
				map[k][0] = temp;
				map[k][1] = 1;
				map[k][2] = i;
			}

		}
		else {//   사진틀에 자리가 없는 경우
			// 가장 작은 추천 횟수를 받았으면서, 오래전에 받은 사람.
			int minchoice = 1001;
			int minindex = 0;
			for (k = 0; k < N; k++) {
				if (map[k][1] < minchoice ) {
					minchoice = map[k][1];
					minindex = k;
				}
				else if (map[k][1] == minchoice) {
					if (map[k][2] < map[minindex][2]) {
						minchoice = map[k][1];
						minindex = k;
					}
				}
			}
			map[minindex][0] = temp;
			map[minindex][1] = 1;
			map[minindex][2] = i;
		}
	}

	vector<int> answer;

	for (vector<int> x : map) {
		if (x[0] == 0) { // 사진틀이 모두다 차지 않는 경우를 고려했어야 했다.
			continue;
		}
		answer.push_back(x[0]);
	}

	sort(answer.begin(), answer.end());


	for (int x : answer) {
		cout << x << " ";
	}

	return 0;
	// 코드를 구현하는 방법을 생각했다면. 시간 복잡도를 바탕으로 가능한 경우인지를 생각해야한다.
	// 사진틀(N) 은 최대 20개. 추천횟수(M)에 대하여 N번 탐색해야한다. M은 최대 1000
	// 시간복잡도는 NM = 20000 번

	// 가중치를 이용한 data 구조로 구현도 가능하다.
	// 101 * 1001 + i * 101 + t
	// (추천수 ) + (게시 시점 ) + 학생 번호
	// mod 1001 을 했을 때 추천수를, mod 101을 했을 때 게시 시점을 알 수 있다.
	// mod 100 하면 학생 번호도 가져올 수 있다.
	// priority에 관한 문제를 풀 떄, 가중치를 활용하면 속도를 높일 수 있음. => README.md 참조
}

