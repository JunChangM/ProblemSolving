#include <iostream>
#include <vector>
using namespace std;
int input[10][10];
vector<pair<int, int>> empty_block;

bool isPossible(int x, int y, int k) {
	for (int i = 1; i <= 9; i++) {
		if (input[x][i] == k && i != y) return false;
		if (input[i][y] == k && i != x) return false;
		int nx = (x - 1) / 3 * 3 + 1 + (i - 1) / 3;
		int ny = (y - 1) / 3 * 3 + 1 + (i - 1) % 3;
		if (input[nx][ny] == k && !(nx == x && ny == y)) return false;
	}
	return true;
}

void search(int idx) {
	if (idx == empty_block.size()) {
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				cout << input[i][j];
			}
			cout << "\n";
		}
		exit(0);
	}
	int x = empty_block[idx].first;
	int y = empty_block[idx].second;

	for (int value = 1; value <= 9; value++) {
		if (isPossible(x, y, value)) {
			input[x][y] = value;
			search(idx + 1);
			input[x][y] = 0;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 1; i <= 9; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= 9; j++) {
			input[i][j] = str[j - 1] - '0';
			if (input[i][j] == 0) empty_block.push_back(make_pair(i, j));
		}
	}
	search(0);

	return 0;
}