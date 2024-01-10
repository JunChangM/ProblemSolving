#include <iostream>
#include <string.h>
using namespace std;
string s;
int ans[26];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(ans, -1, sizeof(ans));
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (ans[s.at(i) - 'a'] == -1)
			ans[s.at(i) - 'a'] = i;
	}
	for (int i = 0; i < 26; i++) cout << ans[i] << ' ';
	return 0;
}
