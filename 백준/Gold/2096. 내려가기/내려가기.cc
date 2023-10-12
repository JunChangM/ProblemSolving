#include <iostream>
#include <algorithm>
using namespace std;
int n, map[3],minmap[3], minstore[3], store[3], temp[3];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		store[0] = map[0]; store[1] = map[1]; store[2] = map[2];
		minstore[0] = minmap[0]; minstore[1] = minmap[1]; minstore[2] = minmap[2];
		cin >> temp[0] >> temp[1] >> temp[2];
		map[0] = max(store[0], store[1]) + temp[0];
		map[1] = max({ store[0],store[1],store[2] }) + temp[1];
		map[2] = max(store[1], store[2]) + temp[2];
		minmap[0] = min(minstore[0], minstore[1]) + temp[0];
		minmap[1] = min({ minstore[0],minstore[1],minstore[2] }) + temp[1];
		minmap[2] = min(minstore[1], minstore[2]) + temp[2];
	}
	cout << max({ map[0],map[1],map[2] }) << ' ' << min({ minmap[0],minmap[1],minmap[2] });
	return 0;
}
