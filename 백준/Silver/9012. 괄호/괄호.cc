#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		stack<char> st;
		bool flag = true;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '(') st.push('(');
			else if (s[j] == ')') {
				if (st.empty()) {
					flag = false;
					break;
				}
				st.pop();
			}
		}

		if (!st.empty()) flag = false;

		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}

	
	return 0;
}

