// [게임 개발](1516)
/*
건물의 우선순위가 있다는 것은 선행 관계를 확인해야 하므로 위상정렬을 의심해보아야한다.
이떄 DAG 인지 확인을 해야한다.
위상 정렬 후 앞에서부터 시간을 계산한다. 이때 값이 존재한다면 큰 값을 넣는다.
before 로 -1까지 받는 값 처리하는거 참신하다.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, s, e, before;
vector<int> graph[502];
int inDegree[502];
typedef struct build {
	int max;
	int time;
}build;

build b[502];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> b[i].time >> before;
		while (before > -1) {
			graph[before].push_back(i);
			inDegree[i]++;
			cin >> before;
		}
		b[i].max = b[i].time;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}
	for (int i = 0; i < n; i++) {
		if (q.empty()) {
			cout << "error";
			return 0;
		}
		int x = q.front();
		q.pop();
		for (int y : graph[x]) {
			b[y].max = max(b[y].max, b[x].max + b[y].time);
			inDegree[y]--;
			if (inDegree[y] == 0) q.push(y);
		}

	}
	for (int i = 1; i <= n; i++) {
		cout << b[i].max << "\n";
	}


	return 0;
}
