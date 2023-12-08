#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> ans;
void dfs(int dep) {
	if (dep == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = ans.back() + 1; i <= n; i++) {
		ans.push_back(i);
		dfs(dep + 1);
		ans.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		ans.push_back(i);
		dfs(1);
		ans.pop_back();
	}
	return 0;
}
