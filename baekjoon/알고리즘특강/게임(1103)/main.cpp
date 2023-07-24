#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int N, M; // 세로 N, 가로 M <= 50
vector<string> map;
vector<vector<int>> visited;

int memo[51][51]; // 시간 초과를 해결하기 위해 memo 이용
// memo[x][y] : x,y 까지 도달하는데 걸린 depth

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int loop = 0;
int maxdeep = 0;

void dfs(int x, int y, int depth) {

	if (maxdeep < depth) maxdeep = depth;

	memo[x][y] = depth;

	int move = map[x][y] - '0'; // 자연수 바꿔주기

	for (int i = 0; i < 4; i++) {
		int nx = x + move * dx[i];
		int ny = y + move * dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

		if (map[nx][ny] != 'H') { // 이동 가능하다면
			if (visited[nx][ny] == 1) {
				loop = -1;
				return;
			}
			if (memo[nx][ny] > depth) continue; // 기록된 값보다 depth가 작으면 더 갈 필요가 없다.

			visited[nx][ny] = 1;
			dfs(nx, ny, depth + 1);
			visited[nx][ny] = 0;
		}
	}
}


int main() {
	cin >> N >> M;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		string temp;
		getline(cin, temp);
		map.push_back(temp);
	}
	visited.resize(N, vector<int>(M, 0));

	// 동전의 위치에서 숫자만큼 이동
	// 이동한 곳이 H이면 안됨.
	// 갈 수 있는 곳이 H밖에 없으면 최대횟수로 종료
	// 갈 수 있는 곳이 반복 되면, 무한 루프로 -1 출력, 지나온 경로 기록해야함
	// 재귀로 할 것인가, 스택으로 할 것인가, DFS

	// 512MB => 재귀로 해보자
	visited[0][0] = 1;
	dfs(0, 0, 1); // 0,0 은 H가 아니다.
	visited[0][0] = 0;

	if (loop == -1) {
		cout << -1;
	}
	else {
		cout << maxdeep;
	}
}


