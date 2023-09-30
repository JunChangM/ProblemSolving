#include <iostream>
#include <cmath>
using namespace std;
int n, c, r, ans;
// divide and conquer : 큰 것 -> 작은 것
void dc(int x, int y, int size) {
	if (x == c && y == r) { // 탈출 조건
		cout << ans;
		return;
	}
	else if (c < x + size && r < y + size && c >= x && r >= y) { // 해당 범위 내의 4분면 안에 있을 때
		dc(x, y, size / 2); // 1사분면 이동 -> 이동 이후 다시 4분면 check, 만약 없다면 size * size를 더해준다.
		dc(x + size / 2, y, size / 2); // 2사분면 이동
		dc(x, y + size / 2, size / 2); // 3사분면 이동
		dc(x + size / 2, y + size / 2, size / 2); // 4사분면 이동
	}
	else { // 만약 없다면 size * size를 더해준다.
		ans += size * size;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> r >> c;
	dc(0, 0, pow(2, n));
	return 0;
}
