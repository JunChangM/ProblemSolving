#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b;
	cin >> a >> b;
	if (a > 0) {
		if (b > 0) cout << 1;
		else cout << 4;
	}
	else {
		if (b > 0) cout << 2;
		else cout << 3;
	}
	return 0;
}
