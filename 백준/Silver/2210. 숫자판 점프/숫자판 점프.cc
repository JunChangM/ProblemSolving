#include <iostream>
#include <vector>
#include <set>
using namespace std;
int input[5][5];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<int> a;

void dfs(int x, int y, int depth, int s) {
	if (depth == 6) {
		a.push_back(s);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
		dfs(nx, ny, depth + 1, s * 10 + input[nx][ny]);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> input[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, 1, input[i][j]);
		}
	}
	set<int> s(a.begin(), a.end());
	cout << s.size();
	return 0;

}