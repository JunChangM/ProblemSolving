#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first; // compare 함수 반환시 true false를 바로 반환할 수 있다.
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	vector<pair<int, string>> v(n, { 0,"" }); // v(크기, 초기값)
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	stable_sort(v.begin(), v.end(), compare); // 안정 정렬을 통해 중복되는 값들의 순서를 보장해주어야 한다.

	for (int i = 0; i < n; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}

	return 0;
}
