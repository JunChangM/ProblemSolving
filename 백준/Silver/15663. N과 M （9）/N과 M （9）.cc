#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int input[9];
bool visited[9];
vector<int> sub;
int n, m;
void dfs(vector<int> x) {
	if (x.size() == m) {
		for (int i : x) {
			cout << i << " ";
		}
			cout << "\n";
	}
	else {
		for (int i = 0; i < n; i++) {
			if (visited[i] == 0) {
				if (i != 0 && (visited[i - 1] == 0 && input[i - 1] == input[i])) continue;
				visited[i] = 1;
				x.push_back(input[i]);
				dfs(x);
				x.pop_back();
				visited[i] = 0;
			}
			
		}
	}


}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	sort(input, input + n);
	// input 배열에서 m개 고르기
	vector<int> k;
	dfs(k);

	return 0;
}