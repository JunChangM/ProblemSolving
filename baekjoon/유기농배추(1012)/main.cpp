#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<vector<int>> map;

int M, N, K; // M : 가로, N : 세로, K : 심어져 있는 위치의 개수

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int a, int b) {
	

	map[a][b] = 0;
	queue<pair<int,int>> q;
	q.push({ a,b });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
				continue;
			}

			if (map[nx][ny] == 1) {
				q.push({ nx,ny });
				map[nx][ny] = 0;
			}
		}

	}

}



int main() {
	int n;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		// 1. 입력받기
		int worm = 0;
		queue<pair<int, int>> B;
		cin >> M >> N >> K;
		
		map.resize(N, vector<int>(M, 0));

		for (int j = 0; j < K; j++) {
			int a, b;
			cin >> a >> b;
			map[b][a] = 1;
			B.push({ b, a });
		}

		// 2. 문제 풀기
		// cout << "start dfs \n";
		while (!B.empty()) {
			int f = B.front().first;
			int s = B.front().second;
			B.pop();
			if (map[f][s] == 1) {
				dfs(f, s);
				worm += 1;
			}

		}
		// 3. 답 출력
		cout << worm << endl;
		map.clear();
	}

	return 0;
}
