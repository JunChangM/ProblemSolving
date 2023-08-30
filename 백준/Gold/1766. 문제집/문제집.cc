#include <iostream>
#include <vector>
#include <queue>
#define N 32001
using namespace std;

int n, m, a, b;
int indegree[N];
vector<int> map[N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a].push_back(b);
		indegree[b]++;
	}

	priority_queue <int> pq;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) pq.push(-i);
	}
	for (int k = 0; k < n; k++) {
		if (pq.empty()) {
			cout << "순환"; return -1;
		}
		int x = -pq.top();
		pq.pop();
		cout << x << " ";
		for (int i = 0; i < map[x].size(); i++) {
			int nx = map[x][i];
				indegree[nx]--;
			if (indegree[nx] == 0) pq.push(-nx);
		}
	}

	return 0;
}

/*
N = 32,000, M = 100,000
1. 순서가 보장 되면서 작은 값부터 출력해야한다. 
2. 먼저 푸는 것이 좋은 문제 처리 => 위상 정렬, 난이도가 쉬운 문제 처리 => 우선순위 큐 (힙)
3. 위상정렬을 사용하기 위한 비 순환 구조라는 전제가 없지만,  문제 푸는 순서가 비 순환을 보장해줄 것이라 예상
*/