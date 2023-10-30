#include <iostream>
#include <string>
#include <map>
using namespace std;
int n, m;
string temp;
map<int, string> dic;
map<string, int> dics;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		dic.insert({ i, temp });
		dics.insert({ temp,i });
	}
	for (int i = 0; i < m; i++) {
		cin >> temp;
		if (temp[0] >= 'A') {
			cout << dics.at(temp) << "\n";
		}
		else {
			cout << dic.at(stoi(temp)) << "\n";
		}
	}
	return 0;
}