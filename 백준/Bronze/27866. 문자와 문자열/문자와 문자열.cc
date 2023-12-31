#include <iostream>
#include <string>
using namespace std;
int n;
string s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;
	cin >> n;
	cout << s.at(n-1);

	return 0;
}
