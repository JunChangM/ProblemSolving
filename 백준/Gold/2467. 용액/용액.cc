#include <iostream>
#include <vector>
using namespace std;
int n, a;
vector<int> positive;
vector<int> negative;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a < 0) negative.push_back(a);
		else positive.push_back(a);
	}

	if (positive.size() == 0) {
		cout << negative[negative.size() - 2] << ' ' << negative[negative.size() - 1];
	}

	else if (negative.size() == 0) {
		cout << positive[0] << ' ' << positive[1];
	}

	else {
		
		int x = 0, y = 0, ans = 2000000000;
		if (negative.size() >= 2 && negative[negative.size() - 1] + negative[negative.size() - 2] < ans) {
			x = negative[negative.size() - 1];
			y = negative[negative.size() - 2];
			ans = abs(x + y);
		}
		
		if (positive.size() >= 2 && positive[0] + positive[1] < ans) {
			x = positive[1];
			y = positive[0];
			ans = x + y;
		}

		int temp = negative.size() - 1;

		for (int i = 0; i < positive.size(); i++) {
			int pos = positive[i];

			for (int j = temp; j >= 0; j--) {
				int neg = negative[j];
				if (abs(pos + neg) < ans) {
					x = pos;
					y = neg;
					ans = abs(pos + neg);
				}

				if (pos + neg < 0) {
					temp = j + 1;
					if (temp == negative.size()) temp--;
					break;
				}
			}
		}
		cout << y << ' ' << x;
	}



	return 0;
}