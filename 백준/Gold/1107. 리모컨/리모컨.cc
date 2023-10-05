#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
int n, m, mv,nv, ans;
int remote[10]; // remote == 0 이면 사용 가능
void dfs(int value, int depth) {
	if (depth > ans + 1) return;
	if (value > n) {
		mv = min(mv, value);
		return;
	}
	else {
		nv = max(nv, value);
		for (int i = 9; i >= 0; i--) {
			if (remote[i] == 0) {
				dfs(value + (i  * pow(10, depth)), depth + 1);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> nv;
		remote[nv] = 1;
	}
	nv = n;
	while (nv > 9) {
		ans++;
		nv /= 10;
	}
	ans++;
	nv = 100;
	for (int i = 0; i < 10; i++) {
		if (remote[i] == 0) {
			nv = i;
			break;
		}
	}
	mv = 1000001;
	dfs(0,0);
	// cout << nv << ' ' << mv << endl;
	int first = abs(n - 100);
	int second = min(abs(n - nv) + to_string(nv).size(), mv - n + to_string(mv).size());
		
	cout << min(first, second);
	return 0;
}

