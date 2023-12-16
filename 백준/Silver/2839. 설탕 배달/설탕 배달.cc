#include <iostream>
#include <vector>
using namespace std;
int n, a;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	while (n > 0 && n % 5 != 0) {
		n -= 3;
		a++;
	}
	if (n < 0) a = -1;
	else a += n / 5;

	cout << a;
	return 0;
}
