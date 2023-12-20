#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int n, m;
string s;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	map<string, int> ma;
	vector<string> ans;

	for (int i = 0; i < n + m; i++) {
		cin >> s;
		ma[s]++;
		if (ma[s] > 1) ans.push_back(s);
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}
