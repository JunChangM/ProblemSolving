#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
char a, b, c;
vector<pair<char,char>> tree[27];
void firstans(char x) {
	cout << x;
	char t = tree[x - 'A'][0].first;
	if (t != '.') {
		firstans(t);
	}
	t = tree[x - 'A'][0].second;
	if (t != '.') {
		firstans(t);
	}
}
void secondans(char x) {
	char t = tree[x - 'A'][0].first;
	if (t != '.') {
		secondans(t);
	}
	cout << x;
	t = tree[x - 'A'][0].second;
	if (t != '.') {
		secondans(t);
	}
}
void thridans(char x) {
	char t = tree[x - 'A'][0].first;
	if (t != '.') {
		thridans(t);
	}
	t = tree[x - 'A'][0].second;
	if (t != '.') {
		thridans(t);
	}
	cout << x;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	cin >> a >> b >> c;
	tree[a - 'A'].push_back({ b,c });
	char start = a;
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		tree[a - 'A'].push_back({ b,c });
	}
	firstans(start);
	cout << '\n';
	secondans(start);
	cout << '\n';
	thridans(start);
	cout << '\n';
	return 0;
}
