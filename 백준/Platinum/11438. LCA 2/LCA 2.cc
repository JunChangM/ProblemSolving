#include <iostream>
#include <vector>
using namespace std;
int n, m, a, b;
vector<int> tree[100001]; // root == 1
int parent[21][100001];
int depth[100001];
void dfs(int cur, int par, int dep) { // 현재, 부모, 깊이를 받아서 입력
	parent[0][cur] = par;
	depth[cur] = dep;
	for (int x : tree[cur]) { // 부모를 제외하고 갈 수 있는 곳에 대해 DFS 진행
		if (x == par) continue;
		dfs(x, cur, dep + 1);
	}
}
// a와 b 의 deptth 비교 후 찾기
int find(int a, int b) {
	// depth가 다르면 depth 맞춰주기
	if (depth[a] != depth[b]) {
		if (depth[a] < depth[b]) { // case의 일반화를 위해 항상 a가 큰 depth를 같도록 설정
			swap(a, b);
		}
		int diff = depth[a] - depth[b];
		for (int j = 0; diff; j++) {
			if (diff % 2 == 1) { // 2로 나누었을 때 나머지가 있으면 그때마다 위로 점프 : 2^j 가 존재하면 점프
				a = parent[j][a];
			}
			diff /= 2;
		}
	}
	if (a != b) { // 위에서 부터 내려오면서 처음으로 달라지는 지점 찾고, 그 위로 하나 올리면 최소 공통 조상
		for (int i =20 ; i >= 0; i--) {
			// 0이면 초기값, 1 위의 값을 의미하므로 가면 안되고, 상위 노드가 처음으로 달라지는 지점에서 점프,
			// 그 후 상위 노드에 대해서 또 달라지는 지점이 있다면 점프
			if (parent[i][a] != 0 && parent[i][a] != parent[i][b]) {
				a = parent[i][a];
				b = parent[i][b];
			}
		}
		// 최종적으로 최소 공통 조상 바로 아래 단계에서 멈춤. 한 칸 상위 노드로 이동
		a = parent[0][a];
	}
		return a;
	
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	// tree 양 방향으로 입력 받기, 추 후에 parent는 진행하지 않도록 구성
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1, 0, 0); // depth 와 parent의 초기값 설정
	
	// parent 값 채우기
	for (int k = 1; k <= 20; k++) {
		for (int t = 1; t <= n; t++) {
			parent[k][t] = parent[k - 1][parent[k - 1][t]];
		}
	}
	//출력
	/*
	for (int i = 1; i <= n; i++) {
		cout << i << ": ";
		for (int x : tree[i]) {
			cout <<  x << " ";
		}
		cout << "\n";
	}
	cout << "tree \n";
	for (int k = 0; k <= 20; k++) {
		for (int t = 1; t <= n; t++) {
			cout << parent[k][t] << " ";
		}
		cout << endl;
	}
	*/
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << find(a, b) << "\n";
	}
}