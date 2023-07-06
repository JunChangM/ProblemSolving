// 왕실의 나이트

#include <iostream>

using namespace std;

int main() {
	// 8 * 8 : a = 97
	string position;
	cin >> position;
	char x = position[0];
	char y = position[1];

	int a = x - 96;
	int b = y - '0';


	int px[8] = {-2, -2, 2, 2, -1, 1, -1 ,1};
	int py[8] = {-1, 1, -1, 1, -2, -2 ,2 ,2};

	int answer = 0;
	for (int i = 0; i < 8; i++) {
		if (a + px[i] > 0 && a + px[i] < 9 && b + py[i] > 0 && b + py[i] < 9) {
			// cout << a + px[i] << endl << b + py[i] << endl;
			answer += 1;
		}
	}

	cout << answer << endl;
	return 0;
}
