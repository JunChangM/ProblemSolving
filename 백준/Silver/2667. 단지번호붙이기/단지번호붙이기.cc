#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, num;
char c;
int map[25][25];
vector<int> number;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void bfs(int x, int y) {
	queue<pair<int, int>> q;
	int many = 0;
	q.push({ x,y });
	map[x][y] = num;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		many++;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (map[nx][ny] == 1) {
				map[nx][ny] = num;
				q.push({ nx,ny });
			}
		}
	}
	number.push_back(many);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			map[i][j] = c - '0';
		}
	}
	num = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				num++;
				bfs(i, j);
			}
		}
	}
	sort(number.begin(), number.end());

	cout << num - 1 << "\n";
	for (int i = 0; i < number.size(); i++) {
		cout << number[i] << "\n";
	}

	return 0;
}