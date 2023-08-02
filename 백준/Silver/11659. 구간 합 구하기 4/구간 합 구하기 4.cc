#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a, b;
int input[100001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> input[1];
	for (int i = 2; i <= n; i++) {
		cin >> input[i];
		input[i] += input[i - 1];
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << input[b] - input[a-1] << "\n";
	}
}