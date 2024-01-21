#include <iostream>
#include <queue>
using namespace std;
int n, k, t;
queue<int> q;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	cout << '<';
	while (q.size() != 1) {
		for (int i = 1; i < k; i++) {
			t = q.front();
			q.pop();
			q.push(t);
		}
		cout << q.front() << ", ";
		q.pop();
	}

	cout << q.front();
	cout << '>';

	return 0;
}
