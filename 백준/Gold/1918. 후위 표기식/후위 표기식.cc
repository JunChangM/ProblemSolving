#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	stack<char> op;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		// A ~ Z 문자가 들어올 경우 출력한다.
		if (s[i] >= 'A' && s[i] <= 'Z') {
			cout << s[i];
		}
		else {
			if (s[i] == '(') // 괄호의 시작. 나중에 )가 발생할 경우 ( 까지의 operation을 꺼내준다.
				op.push('(');
			else if (s[i] == '*' || s[i] == '/') {
				// * or / 이 들어올 경우 이전의 * or / 연산자가 있으면 먼저 처리해야함으로 꺼내준다.
				while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
					cout << op.top();
					op.pop();
				}
				op.push(s[i]);
			}
			else if (s[i] == '+' || s[i] == '-') {
				// + or - 가 들어올 경우 사칙연산의 우선순위에 따라 괄호 외의 이전 연산자를 모두 꺼내주어야 한다.
				while (!op.empty() && op.top() != '(') {
					cout << op.top();
					op.pop();
				}
				op.push(s[i]);
			}
			else if (s[i] == ')') {
				// 괄호를 닫으면 열린 괄호가 나올 때 까지의 모든 연산자를 꺼내주어야 한다.
				while (!op.empty() && op.top() != '(') {
					cout << op.top();
					op.pop();
				}
				op.pop();
			}
		}
	}
	// 남아 있는 연산자는 제거해준다.
	while (!op.empty())
	{
		cout << op.top();
		op.pop();
	}
	return 0;
}
