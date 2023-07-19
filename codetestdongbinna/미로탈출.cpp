#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void print_vector(vector<vector<int>> miro) {
	for (int i = 0; i < miro.size(); i++) {
		for (int j = 0; j < miro[i].size(); j++) {
			cout << miro[i][j];
		}
		cout << endl;
	}
}


vector <vector<int>> miro;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int N, M;

int bfs(int x, int y) {
	queue<pair<int,int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			if (miro[nx][ny] == 1) {
				miro[nx][ny] = miro[x][y] + 1;
				q.push({ nx,ny });
			}

		}

	}


	// print_vector(miro);

	return miro[N-1][M-1];

}


int main() {
	cin >> N >> M;
	cin.ignore();



	for (int i = 0; i < N; i++) {
		string temp;
		vector<int> tempv;
		getline(cin, temp);
		for (int j = 0; j < M; j++) {
			tempv.push_back(temp[j] - '0');
		}
		miro.push_back(tempv);
	}


	int answer = bfs(0, 0);
	cout << answer << endl;
}
