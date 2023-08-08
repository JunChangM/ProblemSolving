#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int t, n, k, x, y, w, build[1001];
vector<int> map[1001];
int inDegree[1001];
int maxtime[1001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i <= n; i++) {
			map[i].clear();
			build[i] = 0;
			inDegree[i] = 0;
			maxtime[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			cin >> build[i];
		}
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			map[x].push_back(y);
			inDegree[y]++;
		}
		cin >> w;
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (inDegree[i] == 0) {
				q.push(i);
				maxtime[i] = build[i];
			}
		}
		for (int i = 0; i < n; i++) {
			if (q.empty()) {
				cout << "cycle";
				return 0;
			}
			x = q.front();
			q.pop();
			for (int s : map[x]) {
				inDegree[s]--;
				if (inDegree[s] == 0) {
					q.push(s);
				}
				maxtime[s] = max(maxtime[s], maxtime[x] + build[s]);
			}
		}
		cout << maxtime[w] << "\n";
	}

	return 0;
}