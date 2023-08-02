#include <iostream>
#include <vector>
#include <cstring>
#define INF 100000000
using namespace std;
int w, h, g, x, y, e, a, b,c,d, t;
int stone[31][31]; // 묘비 여부 (1) , 귀신 구멍 (-1)
int dist[31][31]; // 최단 거리
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
struct edge {
	int x1;
	int y1;
	int x2;
	int y2;
	int cost;
	edge(int x1, int y1, int x2, int y2, int cost) : x1(x1), y1(y1), x2(x2), y2(y2), cost(cost) {}
};
vector<edge> map;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		cin >> g;
		// 초기화
		memset(stone, 0, sizeof(stone));
		map.clear();
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				dist[i][j] = INF;
			}
		}

		for (int i = 0; i < g; i++) {
			cin >> x >> y;
			stone[x][y] = 1; // 묘지
		}
		cin >> e;
		for (int i = 0; i < e; i++) {
			cin >> a >> b >> c >> d >> t;
			stone[a][b] = -1;
			map.push_back(edge(a, b, c, d, t));
		}
		// 길이가 1인 간선 배치
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				if ((i == w - 1 && j == h - 1) || stone[i][j] == 1
			|| stone[i][j] == -1) continue;
				for (int way = 0; way < 4; way++) {
					int nx = i + dx[way];
					int ny = j + dy[way];
					if (nx < 0 || nx >= w || ny < 0 || ny >= h || stone[nx][ny] == 1) continue;
					map.push_back(edge(i, j, nx, ny, 1));
				}
			}
		}

		dist[0][0] = 0;
		// bellman
		int flag = 1;
		for (int i = 1; i <= h * w; i++) {
			for (int k = 0; k < map.size(); k++) {
				if (dist[map[k].x1][map[k].y1] == INF) continue;
				if (dist[map[k].x2][map[k].y2] > dist[map[k].x1][map[k].y1] + map[k].cost) {
					dist[map[k].x2][map[k].y2] = dist[map[k].x1][map[k].y1] + map[k].cost;
					if (i == h * w) {
						flag = 0;
						break;
					}
				}
			}
		}

		

		if (flag == 0) cout << "Never\n";
		else if (dist[w - 1][h - 1] == INF) cout << "Impossible\n";
		else cout << dist[w - 1][h - 1] << "\n";
	}
	return 0;
}



