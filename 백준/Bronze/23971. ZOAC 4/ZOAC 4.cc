#include <iostream>
#include <algorithm>
using namespace std;
int h, w, n, m;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> h >> w >> n >> m;
	n++;
	m++;
	if (w % m == 0) w /= m;
	else w = w / m + 1;
	if (h % n == 0) h /= n;
	else h = h / n + 1;
	cout << w * h << endl;
	return 0;
}	