#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int input[10000];
int visited[10000];
vector <int> ans;
void bfs(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << ' ';
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			ans.push_back(input[i]);
			visited[i] = 1;
			bfs(depth + 1);
			ans.pop_back();
			visited[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> input[i];
	sort(input, input + n);
	bfs(0);
	return 0;
}
