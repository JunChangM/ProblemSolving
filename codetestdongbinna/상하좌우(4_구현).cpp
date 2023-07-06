#include <iostream>
#include <string>

using namespace std;



int main() {
	int a = 1, b = 1;
	int n;
	string plan;
	cin >> n;
	cin.ignore(); // buffer 지우기

	getline(cin, plan); // <string> 내의 함수로 string의 형태로 한 줄을 입력 받는다. (띄어쓰기 포함)

	for (int i = 0; i < plan.size(); i++) { // 띄어쓰기에 대한 예외처리를 하지 않았지만, 걸러짐.

		char c = plan[i];

		if (c == 'L') {
			if (b > 1) b -= 1;
		}
		else if (c == 'R') {
			if (b < n) b += 1;
		}
		else if (c == 'U') {
			if (a > 1) a -= 1;
		}
		else if (c == 'D') {
			if (a < n) a += 1;
		}

	}

	cout << a << ' ' << b << endl;

	return 0; // 파이썬의 소중함을 깨달음.
}
