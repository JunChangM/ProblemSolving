#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> map;
bool visited[1000][1000]; // 0 아니면 1 이기 때문에 1로서 visited를 처리하면 된다.
int N, M;

bool ice_cream_dfs(int x, int y) {
	if (x <= -1 || x >= N || y <= -1 || y >= M) {
		return false;
	}

	if (!map[x][y]) {
		map[x][y] = 1;

		ice_cream_dfs(x - 1, y);
		ice_cream_dfs(x + 1, y);
		ice_cream_dfs(x, y + 1);
		ice_cream_dfs(x, y - 1);

		return true;
	}
	return false;
}

// map 출력용
void print_map(vector<vector<int>> map) {
	for (auto loop : map) {
		for (auto loop2 : loop) {
			cout << loop2 << ' ';
		}
		cout << endl;
	}
}

int main() {
	int answer = 0;
	// 입력 받기 ( 세로 N 가로 M )
	cin >> N >> M;

	// map 받기
	for (int i = 0; i < N; i++) {
		string s;
		vector<int> temp;

		cin >> s;

		for (int j = 0; j < s.size(); j++) {
			temp.push_back(s[j] - '0');
		}
		map.push_back(temp);
	}

	// dfs 실행
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (ice_cream_dfs(i, j)) {
				
				answer += 1;
			}
		}
	}

	cout << answer << endl;
	return 0;
}
