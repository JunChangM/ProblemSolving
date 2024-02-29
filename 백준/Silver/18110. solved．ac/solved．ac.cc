#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, map[300001];
float s = 0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	int a = round(n * 0.15);

	for (int i = 0; i < n; i++) 
		cin >> map[i];
	
	sort(map, map + n);

	for (int i = a; i < n - a; i++) 
		s += map[i];
	if (n == 0) cout << 0;
	else
		cout << round(s / (n - a - a));
}

