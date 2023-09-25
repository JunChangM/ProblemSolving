#include <iostream>
#include <vector>
using namespace std;
int n, k;
int a[201], b[201];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= 2 * n; i++) cin >> a[i];
	int start = 1;
	int des = n;
	int zero = 0;
	int step = 0;
	while (zero < k) {
		step++;
		// 컨베이어벨트 회전
		if (start == 1) start = 2 * n; 
		else start--;

		if (des == 1) des = 2 * n;
		else des--;

		if (b[des] == 1) b[des] = 0;

		// 로봇 이동
		vector<int> temp;
		int right = des;
		for (int i = 1; i < n; i++) { 
			right--;
			if (right == 0) right = 2 * n;
			if (b[right] == 0) continue;

			int next = right + 1;
			if (next == 2 * n + 1) next = 1;

			if (a[next] > 0 && b[next] == 0) {
				a[next]--;
				b[right] = 0;
				temp.push_back(next);
				if (a[next] == 0) zero++;
			}
		}

		for (int i = 0; i < temp.size(); i++) b[temp[i]] = 1;
		if (b[des] == 1) b[des] = 0;
		
		// 로봇 올리기
		if (a[start] > 0 && b[start] == 0) {
			a[start]--;
			b[start] = 1;
			if (a[start] == 0) zero++;
		}
	}
	cout << step;
	return 0;
}

