#include <iostream>
#include <map>
#include <queue>
#include <math.h>
using namespace std;
long long n, m;

map<long long, long long> dict;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	queue<long long> q;
	dict[n] = 1;
	q.push(n);

	while (!q.empty()) {
		long long cur = q.front();
		q.pop();

		if (2 * cur <= m) {
			if (dict.count(2 * cur) == 0 || dict[2 * cur] >= dict[cur] + 1) {
				dict[2 * cur] = dict[cur] + 1;
				q.push(2 * cur);
			}
		}

		if (10 * cur + 1 <= m) {
			if (dict.count(10 * cur + 1) == 0 || dict[10 * cur + 1] >= dict[cur] + 1) {
				dict[10 * cur + 1] = dict[cur] + 1;
				q.push(10 * cur + 1);
			}
		}

	}

	if (dict.count(m) == 0) cout << -1;
	else cout << dict[m];
	
	return 0;
}
		
