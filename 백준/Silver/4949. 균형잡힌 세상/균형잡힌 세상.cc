#include <iostream>
#include <stack>
#include <string>
using namespace std;
string s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	

	while (getline(cin, s)) {
		int flag = 1;
		stack<char> st;

		if (s.at(0) == '.') break;

		for (int i = 0; i < s.size(); i++) {

			if (s.at(i) == '[') {
				st.push('[');
			}

			else if (s.at(i) == ']') {
				if (st.size() == 0 || st.top() != '[') {
					flag = 0;
					break;
				}
				else {
					st.pop();
				}
			}

			else if (s.at(i) == '(') {
				st.push('(');
			}

			else if (s.at(i) == ')') {
				if (st.size() == 0 || st.top() != '(') {
					flag = 0;
					break;
				}
				else {
					st.pop();
				}
			}

		}

		
		if (st.size() != 0 || flag == 0) {
			cout << "no\n";
		}
		else {
			cout << "yes\n";
		}



	}
	
	return 0;
}
		
