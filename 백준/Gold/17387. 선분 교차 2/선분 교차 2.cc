#include <iostream>
using namespace std;
pair<int, int> d1, d2, d3, d4;
// 선분 교차 알고리즘 : 외적을 통해 시계방향인지, 반시계 방향인지, 직선인지 판단함.
long long ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	long long res = (long long)(b.first - a.first) * (c.second - a.second) - (long long)(c.first - a.first) * (b.second - a.second);
	if (res > 0) return 1;   //반시계
	else if (res < 0) return -1;     //시계
	else return 0;
}
bool find() {
	long long d1d2 = ccw(d1, d2, d3) * ccw(d1, d2, d4);
	long long d3d4 = ccw(d3, d4, d1) * ccw(d3, d4, d2);
	if (d1d2 <= 0 && d3d4 <= 0) {
		if (d1d2 == 0 && d3d4 == 0) {
			if (d1 > d2) swap(d1, d2);
			if (d3 > d4) swap(d3, d4);

			return d3 <= d2 && d1 <= d4;
		}
		return true;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> d1.first >> d1.second >> d2.first >> d2.second;
	cin >> d3.first >> d3.second >> d4.first >> d4.second;
	if (find()) cout << 1;
	else cout << 0;

	return 0;
}