#include <iostream>
#include <queue>
using namespace std;
int n;
queue<int> q;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		if (!s.compare("push")) {
			int a;
			cin >> a;
			q.push(a);
		}
		else if (!s.compare("pop")) {
			if (q.empty()) cout << "-1\n";
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (!s.compare("size")) cout << q.size() << '\n';
		else if (!s.compare("empty")) {
			if (q.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (!s.compare("front")) {
			if (q.empty()) cout << "-1\n";
			else cout << q.front() << '\n';
		}
		else if (!s.compare("back")) {
			if (q.empty()) cout << "-1\n";
			else cout << q.back() << '\n';
		}
	}
	return 0;
}
