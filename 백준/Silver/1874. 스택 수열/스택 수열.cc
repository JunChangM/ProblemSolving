#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int n;
int input[100000];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	stack<int> s;
	vector<char> c;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> input[i];
	int index = 0;
	for (int i = 1; i <= n; i++) {
		s.push(i);
		c.push_back('+');
		while (!s.empty() && s.top() == input[index]) {
			s.pop();
			c.push_back('-');
			index++;
		}
	}
	if (index == n) {
		for (int i = 0; i < c.size(); i++) cout << c[i] << '\n';
	}
	else cout << "NO";
	return 0;
}