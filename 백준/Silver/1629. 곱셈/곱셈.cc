#include <iostream>
#include <algorithm>
using namespace std;
long long a, b, c, ans = 1;
string bi = "";
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b >> c;
	int i = 0;
	while (b / 2 != 0) {
		bi += b % 2 + '0';
		b /= 2;
	}
	if (b == 1) bi += '1';

	for (i = 0; i < bi.size(); i++) {
		if (bi[i] == '1') {
			ans = ans * a;
			ans %= c;
		}
		a = a * a % c;
	}
	
	cout << ans;
	return 0;
}
