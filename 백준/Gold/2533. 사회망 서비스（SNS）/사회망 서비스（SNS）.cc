#include <iostream>
#include <vector>
#include <algorithm>
#define N 1000001
using namespace std;
int n, u, v;
vector<int> map[N];
bool visited[N];
int dp[N][2]; // 0 : 해당 노드가 어답터 일때, 1: 아닐때 의 어답터의 수
void find(int x) {
	visited[x] = true;
	dp[x][0] = 1; // 해당 노드가 어답터 일때, 어답터의 수
	for (int i = 0; i < map[x].size(); i++) {
		int child = map[x][i]; // 연결된 노드
		if (visited[child]) continue;
		find(child); // dp로 바닥부터 접근
		dp[x][1] += dp[child][0]; // 내가 어답터가 아닐 경우 자식이 어답터일 때의 경우의 수를 더한다.
		dp[x][0] += min(dp[child][1], dp[child][0]); // 내가 어답터 일 경우, 자식이 어답터 일 때, 아닐 때 중 최소값을 더한다.
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		map[u].push_back(v);
		map[v].push_back(u);
	}
	find(1);
	cout << min(dp[1][0],dp[1][1]);

	return 0;
}