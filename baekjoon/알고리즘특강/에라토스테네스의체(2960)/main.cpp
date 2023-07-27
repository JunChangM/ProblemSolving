#include <iostream>
using namespace std;
int map[1001];
int main() {
	int n, k;
	cin >> n >> k;
	int t = 0;
	for (int i = 2; i <= n; i++) {
		if (map[i] == 0) {
			map[i] = 1;
			t++;
			if (t == k) {
				cout << i;
				return 0;
			}

			for (int j = 2; j * i <= n; j++) {
				if (map[j * i] == 0) {
					map[j * i] = 1;
					t++;
					if (t == k ) {
						cout << j * i;
						return 0;
					}
				}
				
			}
		}
	}
}
