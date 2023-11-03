#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int n;
double ans, a, b;
vector<pair<double, double>> dot;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		dot.push_back({ a,b });
	}

	for (int i = 1; i < n-1; i++) {
		a = dot[0].first * dot[i].second + dot[i].first * dot[i + 1].second + dot[i + 1].first * dot[0].second;
		b = dot[i].first * dot[0].second + dot[i + 1].first * dot[i].second + dot[0].first * dot[i + 1].second;
		ans += (a - b) / 2;
	}

	cout << fixed;
	cout.precision(1);
	cout << abs(ans);
	return 0;
}