#include <iostream>
#include <vector>
using namespace std;
bool map[10000000] = { 1,1 };
int main() {
	int n;
	vector<int> prime;
	cin >> n;
	for (int i = 2; i * i <= n; i++) {
		if (map[i] == 1) continue;
		for (int j = 2; i * j < n; j++) {
			map[i * j] = 1;
		}
	}
	for (int i = 0; i <= n; i++) {
		if (map[i] == 0) prime.push_back(i);
	}
	for (int x : prime) {
		while (n%x == 0) {
			cout << x << "\n";
			n /= x;
		}
	}
	return 0;
}
// 시간이 조금 오래 걸려서 확인해본 결과
// => 굳이 체를 만들 필요 없이 작은 수부터 나눌 수 있는 만큼 나눠주는 것도 가능하다....
