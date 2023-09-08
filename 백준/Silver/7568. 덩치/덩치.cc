#include <iostream>
#include <algorithm>
using namespace std;
int n, x, y;
int num[50];
pair<int, int> input[50];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		input[i] = {  x,y  };
	}

	int c;
	pair<int, int> a;

	for (int i = 0; i < n; i++) {
		c = 1;
		a = input[i];
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (a.first < input[j].first && a.second < input[j].second) {
				c++;
			}
		}
		num[i] = c;
	}


	for (int i = 0; i < n; i++) cout << num[i] << ' ';
	return 0;
}