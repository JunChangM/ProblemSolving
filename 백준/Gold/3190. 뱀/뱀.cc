#include <iostream>	
#include <queue> // 큐 를 이용해 하나씩 빼면서 진행 3190
using namespace std;
char c;
int n, k, l, a, b, x, y, t, way; // way : 0 오른쪽 
int dx[4] = { 0,-1,0,1 }; //  R N L S
int dy[4] = { 1,0,-1,0 };
int map[1001][1001];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> n >> k;
	while (k--) {
		cin >> a >> b;
		map[a][b] = 1;
	}
	// 1. initial position
	queue<pair<int, int>> q;
	bool flag = false;
	x = 1, y = 1, t = 1, way = 0;
	q.push({ x,y });

	cin >> l;
	while (l--) {

		cin >> a >> c;
		if (!flag) {
			for (; t<= a; t++) {
				 x = x + dx[way];
				 y = y + dy[way];
				if (x <= 0 || y <= 0 || x > n || y > n) {
					flag = true;
					break;
				}

				queue<pair<int, int>> subq = q;
				while (!subq.empty()) {
					if (subq.front().first == x && subq.front().second == y) {
						//cout << "대가리 " << x << ' ' << y <<  " t : " << t << endl;
						flag = true;
						break;
					}
					subq.pop();
				}
				if (flag) break; 

				if (map[x][y] != 1)q.pop();
				else map[x][y] = 0;
				q.push({ x,y });

			}
			
			if (c == 'D') way--;
			else way++;

			if (way == -1) way = 3;
			if (way == 4) way = 0;

			if (l == 0) {
				for (; flag == false; t++) {
					x = x + dx[way];
					y = y + dy[way];
					if (x <= 0 || y <= 0 || x > n || y > n) {
						flag = true;
						break;
					}

					queue<pair<int, int>> subq = q;
					while (!subq.empty()) {
						if (subq.front().first == x && subq.front().second == y) {
							flag = true;
							break;
						}
						subq.pop();
					}

					if (flag) break;
					if (map[x][y] != 1)q.pop();
					else map[x][y] = 0;
					q.push({ x,y });

				}
			}
		}
	}

	cout << t;
    return 0;
}