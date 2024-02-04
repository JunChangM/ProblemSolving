#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
string s;
int stoint(string a) {
	int r = 0;
	istringstream aa(a);
	string stringBuffer;
	vector<string> xx;
	while (getline(aa, stringBuffer, '+')) {
		r += stoi(stringBuffer);
	}
	return r;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int sign = 1;

	cin >> s;
	if (s.at(0) == '-') sign = -1;

	istringstream ss(s);
	string stringBuffer;
	vector<string> x;

	while (getline(ss, stringBuffer, '-')) {
		x.push_back(stringBuffer);
	}

	int ans = sign * stoint(x[0]);
	for (int i = 1; i < x.size(); i++) {
		ans -= stoint(x[i]);
	}

	cout << ans;

	return 0;
}

