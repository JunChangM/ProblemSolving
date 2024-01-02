#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n, a, t;
string s;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		a = 0;
		t = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s.at(j) == 'O') a += ++t;
			else t = 0;
		}
		cout << a << '\n';
	}

	
	return 0;
}
