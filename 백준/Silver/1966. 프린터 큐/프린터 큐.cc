#include <iostream>
#include <map>
#include <queue>
using namespace std;
int t, n, m, a;
queue<pair<int,int>> q;
priority_queue <int> pq;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		while (!q.empty()) q.pop();
		while (!pq.empty()) pq.pop();

		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> a;
			q.push({ i,a });
			pq.push(a);
		}

		int ans = 0;
		while (!q.empty()) {
			int cur = q.front().first;
			int priority = q.front().second;
			q.pop();

			if (priority < pq.top()) {
				q.push({ cur,priority });
			}
			else {
				ans++;
				pq.pop();
				if (cur == m) {
					cout << ans << '\n';
					break;
				}
			}

		}
	}

	return 0;
}

