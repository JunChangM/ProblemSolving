#include <iostream>
#include <queue>
using namespace std;
int n,m, big;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int map[1000][1000];
void find(int x , int y) {
	queue<pair<int, int>> q;
	int temp = 0;
	q.push({ x,y });
	while (!q.empty()) {
		temp++;
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == 1) {
				map[nx][ny] = 0;
				q.push({ nx,ny });
			}
		}
	}
	big = big > temp ? big : temp;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int num = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				map[i][j] = 0;
				num++;
				find(i, j);
			}
		}
	}
	cout << num << "\n";
	cout << big << "\n";
	return 0;
}	
