#include <iostream>
#include <algorithm>
using namespace std;
int n, a;
pair<int,int> input[1000000];
int x[1000000];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		input[i] = { a,i };
	}
	sort(input, input + n);
	a = 0;
	for (int i = 0; i < n; i++) {
		if (i != 0 && input[i].first == input[i - 1].first) a--;
		x[input[i].second] = a++;
	}
	for (int i = 0; i < n; i++) cout << x[i] << ' ';
	return 0;
}