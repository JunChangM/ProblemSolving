#include <iostream>
#include <stack>
using namespace std;
int n, t;
stack<pair<int, int>> s;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		while (!s.empty()) {
			if (t < s.top().second) {
				cout << s.top().first << ' ';
				break;
			}
			s.pop();
		}
		if (s.empty()) cout << 0 << ' ';
		s.push({ i,t });
	}
	return 0;
}	
