#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int n, num;
double ans;
int parent[100];
double t[100][2];
vector<pair<double,pair<int, int>>> map;
int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}
bool uni(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return false;
	if (x < y) parent[x] = y;
	else parent[y] = x;
	return true;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> t[i][0] >> t[i][1];
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double leng = sqrt(pow(t[i][0] - t[j][0], 2) + pow(t[i][1] - t[j][1], 2));
			map.push_back({ leng,{i,j} });
		}
	}
	sort(map.begin(), map.end());
	for (int i = 0; i < n; i++) parent[i] = i;

	for (int i = 0; i < map.size(); i++) {
		if (uni(map[i].second.first, map[i].second.second)) {
			ans += map[i].first;
			num++;
			if (num == n - 1) break;
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << ans;
	return 0;
}
/*
cout 기본 출력은 정수 부분이 6자리가 넘어가면 소수점 부분은 출력이 안된다.
cout<<fixed;
cout.precision(7);
를 이용해 소수점 자리가 7자리가 출력되도록 할 수 있다(반올림)
*/