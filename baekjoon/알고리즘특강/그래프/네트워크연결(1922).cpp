
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
풀이

일반적인 그래프의 문제이다.
모든 컴퓨터를 연결하는데 필요한 최소비용을 구해야 한다.
= > 모든 노드 연결 => 그래프의 문제다.


1) 컴퓨터 1000 개로 만들 수 있는 간선은 999개 * 10000 = 999만이므로 int 범위로도 충분하다.

2) 시간복잡도 : 10만 로그 10만 = 10만 * 17 = 170만번

=> 정렬 + 크루스칼

*코드
disjoint_set 으로 cycle 점검 : find 와 _union 함수 필요
weight를 비교할 수 있는 cmp 함수 필요
정렬 후 weight 작은 값 부터 하나씩 전진하면서 작은 값 찾기 (이때 find(a) 와 find(b) 가 달라야한다. == cycle 아님)
최소 비용 더하고, 진행한 정점 union 진행
*/

int n, m, a, b, c;
vector< pair<int, pair<int, int>>> map;
int parent[1001];
int find(int a) {
	if (parent[a] == a) return a;
	else return parent[a] = find(parent[a]);
}
void _union(int a, int b) {
	int x = find(a);
	int y = find(b);
	if (x > y) {
		parent[y] = x;
	}
	else {
		parent[x] = y;
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int total = 0;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		map.push_back({ c,{a,b} });
	}
	sort(map.begin(), map.end());
	// for (auto x : map) cout << x.first << endl;
	for (int i = 0; i < map.size(); i++) {
		int val = map[i].first;
		int x = map[i].second.first;
		int y = map[i].second.second;
		if (find(x) != find(y)) {
			_union(x, y);
			total += val;
		}
		
	}
	cout << total;

}
