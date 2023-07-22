#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		// 1. 두 좌표가 같은 경우 -> 길이가 같으면 무한대(-1) -> 길이가 다르면 0 
		// 2. 좌표가 다른 경우 -> 
		// 길이가 같으면 -> 2개 : r1 + r2 > d , 1개 : r1 + r2 == d , 0개 : r1 + r2 < d 
		// 길이가 다르면 -> 2개 : r1 + r2 > d , 1개 : r1 + r2 == d , 0개 : r1 + r2 < d
		// 0 0 (3) 0 7 (4)
		int answer; 

		if (x1 == x2 && y1 == y2) { // 좌표가 같은 경우
			if (r1 == r2) {// 길이가 같은 경우
				if (r1 == 0) {
					answer = 1;
					// cout << 1 << endl;
				}
				else {
					answer = -1;
					// cout << -1 << endl;
				}
			}
			else { // 길이가 다른 경우
				answer = 0;
				// cout << 0 << endl;
			}
		}
		else { // 좌표가 다른 경우
			double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
			int a = max(r1, r2);
			int b = min(r1, r2);

			if (r1 + r2 == d || a- b == d) {
				answer = 1;
				// cout << 1 << endl;
			}
			else if (r1 + r2 < d || d + b < a) {
				answer = 0;
				// cout << 0 << endl;
			}
			else {
				answer = 2;
				// cout << 2 << endl;
			}

		}
		cout << answer << endl;
	}

}
