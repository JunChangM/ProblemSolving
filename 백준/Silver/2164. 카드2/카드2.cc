#include <iostream>
#include <queue>;
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	queue<int> q;
	for (int i = 1; i <= n; i++) q.push(i);
	while (q.size() > 2) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	if (q.size() == 2) {
		q.pop();
	}
	cout << q.front();
	return 0;
}	
