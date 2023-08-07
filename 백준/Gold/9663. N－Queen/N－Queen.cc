#include <iostream>
using namespace std;
int n, answer;
int list[16];
bool check(int depth) {
	for (int i = 0; i < depth; i++) {
		if (list[i] == list[depth] || depth - i == abs(list[depth] - list[i])) return false;
	}
	return true;
}
void nqueen(int depth) {
	if (depth == n) answer += 1;
	else {
		for (int i = 0; i < n; i++) {
			list[depth] = i;
			if (check(depth)) {
				nqueen(depth + 1);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	nqueen(0);
	cout << answer;
}
/*
2차원으로 하나씩 재귀의 형태로 접근하려고 하였으나, 각 행에는 하나의 값만 들어가므로 열을 구분하는 1차원 배열을 이용하였다.
행은 자동을 구분되므로, 각 열과 대각선에 존재하는지만을 확인하면 된다. 
대각선을 확인하는 방법은 x의 성분 차 와 y의 성분 차가 같으면 대각선에 위치한다는 것을 이용했다.
재귀를 구현할 때, 항상 탈출 조건을 제시하여 주고, 그 이후에 재귀 조건을 작성해주어야한다.
왠만하면 재귀안에 들어와서 처리하는 방식으로 구현해야한다.
마지막으로 check 조건을 구상할 때 list[depth]에 값을 넣고 비교하는 방식을 통해 재귀를 짧게 처리할 수 있었다.
*/