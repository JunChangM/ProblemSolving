#include <iostream>
#include <vector>
using namespace std;
int a, b, v;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b >> v;
	int x = a - b;
	int t = (v - a) / x;
	for (int i = t; i < 1000000000; i++) {
		if (x * i + a >= v) {
			cout << i + 1;
			break;
		}
	}
	return 0;
}
