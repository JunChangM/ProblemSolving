#include <iostream>
#include <map>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	map<int, int> m;
	int N, M, n;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		m[n]++;
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> n;
		auto ans = m.find(n);
		if (ans != m.end()) {
			cout << ans->second << ' ';
		}
		else cout << "0 ";
	}

	
	return 0;
}
