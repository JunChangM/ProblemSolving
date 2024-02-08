#include <iostream>
#include <map>
#include <queue>
#include <limits.h> 
using namespace std;
int t, n, k, ans, ans2;
char c;
map<long, int> m;
priority_queue <int> pq; // max is top
priority_queue <int, vector<int>, greater<int>> pq_min;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> k;
		m.clear();
		while (!pq.empty()) pq.pop();
		while (!pq_min.empty()) pq_min.pop();

		while (k--) {
			cin >> c >> n;
			// insert
			if (c == 'I') {
				m[n]++;
				pq.push(n);
				pq_min.push(n);
			}
			// delete
			else if (c == 'D') {
				if (n == 1 && !pq.empty()) {
					m[pq.top()]--;
					pq.pop();
				}

				if (n == -1 && !pq_min.empty()) {
					m[pq_min.top()]--;
					pq_min.pop();
				}

				while (!pq.empty() && m[pq.top()] == 0) {
					pq.pop();
				}

				while (!pq_min.empty() && m[pq_min.top()] == 0) {
					pq_min.pop();
				}
			}
		}
		// print max min 

		/*while (!pq.empty())
		{
			if (m[pq.top()] > 0) {
				ans = pq.top();
				break;
			}
			pq.pop();
		}

		while (!pq_min.empty())
		{
			if (m[pq_min.top()] > 0) {
				ans2 = pq_min.top();
				break;
			}
			pq_min.pop();
		}*/

		if (pq.empty() || pq_min.empty()) cout << "EMPTY\n";
		else cout << pq.top() << ' ' << pq_min.top() << '\n';

	}

	return 0;
}

