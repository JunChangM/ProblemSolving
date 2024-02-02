#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, x, y;
vector<int> line[101];
int map[101];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 2; i <= 100; i++) map[i] = 1000;

	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		cin >> x >> y;
		line[x].push_back(y);
	}

	queue<pair<int,int>> q;
	q.push({1,0});

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int next = x + i;
			if (next > 100) break;
			int cost = y + 1;

			if (!line[next].empty()) {
				int nnext = line[next][0];
				if (map[nnext] > cost) {
					map[nnext] = cost;
					q.push({ nnext,cost });
				}
			}
			else if (map[next] > cost) {
				map[next] = cost;
				q.push({ next,cost });
			}

		}
	}
	cout << map[100];

	return 0;
}

