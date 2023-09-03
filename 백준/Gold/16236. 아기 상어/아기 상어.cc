#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int n, s, answer, sx, sy;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int map[21][21];
int dist[21][21];
vector<pair<int, int>> v;
vector<bool> cond;
bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first) return true;
	else if (a.first == b.first && a.second < b.second) return true;
	else return false;
}
void bfs(int x, int y) {
	queue<pair<int,int>> q;
	memset(dist, 0, sizeof(dist));
	q.push({ x,y });
	dist[x][y] = 1;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || dist[nx][ny] > 1 ) continue;
			if (map[nx][ny] > s) continue;
			dist[nx][ny] = dist[x][y] + 1;
			q.push({ nx,ny });
		}
	}
}
int find() {
	int count = 0;
	s = 2; answer = 0;
	while (!v.empty()) {
		int mx = 100, my = 100, mv = 1000, index = 100;
		bfs(sx, sy);

		for (int i = 0; i < v.size(); i++) {
			if (cond[i] && map[v[i].first][v[i].second] < s && dist[v[i].first][v[i].second] < mv && dist[v[i].first][v[i].second] > 0) {
				index = i;
				mx = v[i].first;
				my = v[i].second;
				mv = dist[mx][my];
			}
		}
		if (mx != 100) {
			map[sx][sy] = 0;
			sx = mx;
			sy = my;
			answer += mv - 1;
			count++;
			cond[index] = false;
			map[sx][sy] = 9;

			if (count == s) {
				count = 0;
				s++;
			}
		}
		else break;
	}
	return answer;
}
int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				sx = i;
				sy = j;
			}
			else if (map[i][j] != 0) {
				v.push_back({ i,j });
				cond.push_back(true);
			}
		}
	}
	sort(v.begin(), v.end(), comp);
	cout << find();
	return 0;
}