#include <iostream>
using namespace std;
int n, a, b, c;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		a += (c / 30) * 10 + 10;
		b += (c / 60) * 15 + 15;
	}
	if (a < b) cout << 'Y' << ' ' << a;
	else if (a == b) cout << "Y M " << a;
	else cout << 'M' << ' ' << b;
	return 0;
}
