#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int t, n;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		string p;
		string input;
		cin >> p >> n >> input;
		// input을 list로 변환하고 들어가야함.
		// reverse 출력시 문제가 생김
		int cur = 0, left = 1, right = input.size() - 2;
		for (int i = 0; i < p.size(); i++) {
			char c = p[i];
			if (c == 'R') {
				if (cur == 0) cur = 1;
				else cur = 0;
			}
			else if (c == 'D') {
				if (n == 0) {
					n = -1;
					cout << "error\n";
					break;
				}
				else {
					n--;
					if (n != 0) {
						if (cur == 0) {
							while (input[left] != ',') left++;
							left++;
						}
						else {
							while (input[right] != ',') right--;
							right--;
						}
					}
				}
			}
		}
		if (n == 0) {
			cout << "[]\n";
		}
		else if (n != -1) {
			cout << '[';
			if (cur == 0) for (int i = left; i <= right; i++) cout << input[i];
			else {
				string temp;
				for (int i = left; i <= right; i++) temp += input[i];
				istringstream iss(temp);
				vector<string> result;
				while (getline(iss, temp, ',')) result.push_back(temp);
				for (int i = result.size() - 1; i >= 0; i--) {
					if (i == 0) {
						for (int j = 0; j < result[i].size(); j++) cout << result[i][j];
					}
					else {
						for (int j = 0; j < result[i].size(); j++) cout << result[i][j];
						cout << ',';
					}
				}
			}
			cout << "]\n";
		}
		
	}
	return 0;
}