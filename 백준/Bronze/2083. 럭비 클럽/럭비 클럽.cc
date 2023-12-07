#include <iostream>
using namespace std;
string str;
int a, b;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (cin >> str >> a >> b) {
		if (!str.compare("#") && a == 0 && b == 0) break;
		if (a > 17 || b >= 80) {
			str += " Senior\n";
		}
		else str += " Junior\n";
		cout << str;
	}
	return 0;
}
