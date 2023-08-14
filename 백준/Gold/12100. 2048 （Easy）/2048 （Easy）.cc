#include <iostream>
#include <algorithm>
using namespace std;
int input[20][20];
int n, i, j, m;
void operate(int map[20][20], int depth) {
	
	if (0) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	
	

	if (depth == 5) {
		for (int k = 0; k < n; k++) {
			for (int l = 0; l < n; l++) {
				m = m > map[k][l] ? m : map[k][l];
			}
		}
		return;
	}
	int temp[20][20];
	for (int k = 0; k < 4; k++) {
		copy(&map[0][0], &map[0][0] + 20 * 20, &temp[0][0]);
		if (k == 0) { // east
			// 1. 오른쪽 밀착,
			for (i = 0; i < n; i++) {
				for (j = n - 1; j > 0; j--) {
					if (temp[i][j] == 0) { // 값이 0이면 그 뒤의 숫자 찾아서 땡겨주기
						for (int q = j; q >= 0; q--) {
							if (temp[i][q] != 0) {
								int idx = j;
								while (q >= 0) {
									temp[i][idx] = temp[i][q];
									idx--;
									q--;
								}
								while (idx >= 0) {
									temp[i][idx--] = 0;
								}
								break;
							}
						}
						
					}

				}
			}
			for (i = 0; i < n; i++) {
				for (j = n - 1; j > 0; j--) {
					if (temp[i][j] != 0 && temp[i][j] == temp[i][j - 1]) {
						temp[i][j] *= 2;
						for (int l = j - 1; l > 0; l--) {
							temp[i][l] = temp[i][l - 1];
						}
						temp[i][0] = 0;
					}
				}
			}
			operate(temp, depth + 1);
		}
		else if (k == 1) { //west
			for (i = 0; i < n; i++) {
				for (j = 0; j < n - 1; j++) {
					if (temp[i][j] == 0) { // 값이 0이면 그 뒤의 숫자 찾아서 땡겨주기
						for (int q = j; q < n; q++) {
							if (temp[i][q] != 0) {
								int idx = j;
								while (q < n) {
									temp[i][idx] = temp[i][q];
									idx++;
									q++;
								}
								while (idx < n) {
									temp[i][idx++] = 0;
								}
								break;
							}
						}

					}

				}
			}
			for (i = 0; i < n; i++) {
				for (j = 0; j < n - 1; j++) {
					if (temp[i][j] != 0 && temp[i][j] == temp[i][j + 1]) {
						temp[i][j] *= 2;
						for (int l = j + 1; l < n-1; l++) temp[i][l] = temp[i][l + 1];
						temp[i][n-1] = 0;
					}
				}
			}
			operate(temp, depth + 1);
		}
		else if (k == 2) { // north
			for (i = 0; i < n - 1; i++) {
				for (j = 0; j < n; j++) {
					if (temp[i][j] == 0) { // 값이 0이면 그 뒤의 숫자 찾아서 땡겨주기
						for (int q = i; q < n; q++) {
							if (temp[q][j] != 0) {
								int idx = i;
								while (q < n) {
									temp[idx][j] = temp[q][j];
									idx++;
									q++;
								}
								temp[n - 1][j] = 0;
								while (idx < n) {
									temp[idx++][j] = 0;
								}
								break;
							}
						}

					}

				}
			}
			for (i = 0; i < n - 1; i++) {
				for (j = 0; j < n; j++) {
					if (temp[i][j] != 0 && temp[i][j] == temp[i + 1][j]) {
						temp[i][j] *= 2;
						for (int l = i + 1; l < n - 1; l++) temp[l][j] = temp[l + 1][j];
						temp[n - 1][j] = 0;
					}
				}
			}
			operate(temp, depth + 1);
		}
		else { // south
			for (i = n - 1; i > 0; i--) {
				for (j = 0; j < n; j++) {
					if (temp[i][j] == 0) { // 값이 0이면 그 뒤의 숫자 찾아서 땡겨주기
						for (int q = i; q >= 0; q--) {
							if (temp[q][j] != 0) {
								int idx = i;
								while (q >= 0) {
									temp[idx][j] = temp[q][j];
									idx--;
									q--;
								}
								while (idx >= 0) {
									temp[idx--][j] = 0;
								}
								break;
							}
						}

					}

				}
			}


			for (i = n - 1; i > 0; i--) {
				for (j = 0; j < n; j++) {
					if (temp[i][j] != 0 && temp[i][j] == temp[i - 1][j]) {
						temp[i][j] *= 2;
						for (int l = i - 1; l > 0; l--) temp[l][j] = temp[l - 1][j];
						temp[0][j] = 0;
					}
				}
			}
			operate(temp, depth + 1);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(i = 0; i<n; i++) for (j = 0; j < n; j++) cin >> input[i][j];
	m = 0;
	operate(input,0);
	cout << m;
	return 0;
}
/*
1) 완전탐색 => 4^5 * 20^2
*/