#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int n, ans, temp;
int dx[4] = { 1,-1,0,0};
int dy[4] = { 0,0,1,-1};

int map[100][100];
bool visited[100][100];

void bfs(int x, int y, int h) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = 1;

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[nx][ny] == 0 && map[nx][ny] > h) {
				visited[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int h = 0; h <= 100; h++) {

		temp = 0;
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == 0 && map[i][j] > h) {
					bfs(i, j, h);
					temp++;
				}
			}
		}

		ans = temp > ans ? temp : ans;

	}
		cout << ans;
		return 0;
	}
		
