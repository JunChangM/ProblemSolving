#include <iostream>
#include <map>
using namespace std;
long long t, ans;
int n, m;
long long a[1001], b[1001];
map <long long, long long> point;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) a[i] += a[i - 1];
	cin >> m;
	for (int i = 1; i <= m; i++) cin >> b[i];
	for (int i = 1; i <= m; i++) b[i] += b[i - 1];


	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			point[a[j] - a[i-1]]++;
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= m; j++) {
			long long temp = b[j] - b[i-1];
			ans += point[t - temp];
		}
	}

	cout << ans;
	return 0;
}
