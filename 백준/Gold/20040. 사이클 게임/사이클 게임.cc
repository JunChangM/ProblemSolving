#include <iostream>
#include <vector>
using namespace std;
int n, m, order;
int visit[1000000];
int a[1000000][2];
int parent[1000001];
int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);
}
void uni(int x, int y) {
	x = find(x);
	y = find(y);
	if (x < y) parent[x] = y;
	else parent[y] = x;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> a[i][0] >> a[i][1];
	for (int i = 1; i <= m; i++) parent[i] = i;
	int temp = 1;
	for (int i = 0; i < m; i++) {
		if (visit[a[i][0]] == 0 && visit[a[i][1]] == 0) {
			visit[a[i][0]] = temp;
			visit[a[i][1]] = temp;
			temp++;
		}
		else if (visit[a[i][0]] == 0) {
			visit[a[i][0]] = visit[a[i][1]];
		}
		else if (visit[a[i][1]] == 0) visit[a[i][1]] = visit[a[i][0]];
		else {
			if (find(visit[a[i][0]]) == find(visit[a[i][1]])) {
				order = i + 1;
				break;
			}
			uni(visit[a[i][0]], visit[a[i][1]]);
		}
	}
	cout << order;
    return 0;
}
