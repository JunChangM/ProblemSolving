#include <iostream>
#include <vector>

using namespace std;

int main() {
	// 몇 개의 물병을 살 것인가
	int n, k, answer = 0;
	vector<int> bottle;

	cin >> n >> k;
	// n 개의 물병이 주어지고, k 개의 물병을 남겨야 한다.
	// 5 3 을 생각해보면 2L 2L 1L 로 만들 수 있어서 추가적인 물병이 필요하지 않는다.
	// 13 3 을 생각해보면 4L 4L 4L 1L -> 8L 4L 1L
	int water = 1;

  // a L 로 bottle 쪼개기
	while (n > 0) {
		if (n % 2 == 0) {
			n /= 2;
			water *= 2;
		}
		else {
			n -= 1;
			bottle.push_back(water);
			n /= 2;
			water *= 2;
		}
	}
	
	// 출력(확인용)
	for (int i = 0; i < bottle.size(); i++) {
		cout << bottle[i] << "  ";
	}
	cout << endl;

  // bottle의 vector를 앞에서부터 합쳐 나간다. k개 이하가 되면 stop
	while (bottle.size() > k) {
		int first = bottle[0];
		int second = bottle[1];
		
		while (first != second) {
			answer += first;
			first += first;
		}
		bottle.erase(bottle.begin());
		bottle[0] = 2 * second;
	}

	cout << answer << endl;
	return 0;
}
