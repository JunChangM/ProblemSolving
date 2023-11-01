#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100001
using namespace std;

int t, n, ans;
int visited[MAX];
int done[MAX];
int map[MAX];

void dfs(int start) {
	visited[start] = 1;
	int next = map[start];
	
	if (visited[next] == 0) {
		dfs(next);
	}
	else if (done[next] == 0) {
		for (int i = next; i != start; i = map[i]) {
			ans++;
		}
		ans++;
	}
	done[start] = 1;
}
/*
e.g. Cycle 확인하기
4 -> 7 -> 6 -> 4 인 경우
4를 방문했기 때문에 두번째 if문에 들어간다. 4 -> 7 을 카운트 하고, 6을 다시 카운트한다.
되돌아가면서 방문한 점들을 done으로 설정한다.
*/
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <=n; i++) {
			cin >> map[i];
		}

		for (int i = 1; i <= n; i++) {
			dfs(i);
		}

		cout << n - ans << "\n";

		memset(visited, 0, sizeof(visited));
		memset(done, 0, sizeof(done));
		ans = 0;
	}

	return 0;
}
