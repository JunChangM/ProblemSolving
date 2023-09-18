#include <iostream>
using namespace std;
char c;
int n;
int input[1000][1000];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			if (c == '*') input[i][j] = 1;
		}
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (input[i][j] == 1 && input[i - 1][j] == 1 && input[i + 1][j] == 1 && input[i][j - 1] == 1 && input[i][j + 1] == 1) {
				cout << i + 1<< ' ' << j + 1<< "\n";
				int val = 0;
				for (int k = j - 1; k >= 0; k--) {
					if (input[i][k] == 0) break;
					val++;
				}
				cout << val << ' ';
				val = 0;
				for (int k = j + 1; k < n; k++) {
					if (input[i][k] == 0) break;
					val++;
				}
				cout << val << ' ';
				val = 0;
				for (int k = i + 1; k < n; k++) {
					if (input[k][j] == 0) break;
					val++;
				}
				cout << val << ' ';
				val++;
				int val2 = 0;
				for (int k = 0; i + val + k < n; k++) {
					if (input[i + val + k][j-1] == 0) break;
					val2++;
				}
				cout << val2 << ' ';
				val2 = 0;
				for (int k = 0; i + val + k < n; k++) {
					if (input[i + val + k][j + 1] == 0) break;
					val2++;
				}
				cout << val2 ;
			}
		}
	}

	return 0;
}	
