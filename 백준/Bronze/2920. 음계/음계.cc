#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> n(8, 0);
	for (int i = 0; i < 8; i++) cin >> n[i];
	int i = 1;
	while(n[i - 1] < n[i]) {
		i++;
		if (i == 8) break;
	}
	if (i == 8) cout << "ascending";
	else {
		i = 1;
		while (n[i - 1] > n[i]) {
			i++;
			if (i == 8) break;
		}
		if (i == 8) cout << "descending";
		else cout << "mixed";
	}

	return 0;
}
