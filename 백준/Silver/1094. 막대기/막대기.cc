#include <iostream>
using namespace std;
int stick[65];
int stick_index[7] = { 1,2,4,8,16,32,64 };
int totalstick = 64;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int input, count = 0; stick[64] = 1;
	cin >> input;
	while (totalstick != input) {
		for (int i = 0; i < 7; i++) {
			if (stick[stick_index[i]] != 0) {
				int divide = stick_index[i] / 2;
				stick[stick_index[i]]--;
				totalstick = 0;
				for (int i = 0; i < 7; i++) totalstick += stick_index[i] * stick[stick_index[i]];
				if (totalstick + divide > input) {
					stick[divide]++;
				}
				else {
					stick[divide] += 2;
				}
				break;
			}
		}
		totalstick = 0;
		for (int i = 0; i < 7; i++) totalstick += stick_index[i] * stick[stick_index[i]];
	}
	for (int i = 0; i < 7; i++) count += stick[stick_index[i]];
	cout << count;
}