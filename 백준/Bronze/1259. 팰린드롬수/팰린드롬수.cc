#include <iostream>
#include <string>
using namespace std;
string input;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (true) {
		cin >> input;
		if (input == "0") break;
		bool flag = 1;
		int left = 0;
		int right = input.length() - 1;
		while (left < right) {
			if (input[left] == input[right]) {
				left++;
				right--;
			}
			else {
				flag = 0;
				break;
			}
		}
		if (flag) cout << "yes\n";
		else cout << "no\n";

	}

	return 0;
}
