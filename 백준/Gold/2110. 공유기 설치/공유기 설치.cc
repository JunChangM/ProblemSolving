#include <iostream>
#include <algorithm>
using namespace std;
int n, c;
int input[200000];
int find() {
	int left_dist = 0;
	int right_dist = input[n - 1] - input[0];;
	int result = 0;

	while (left_dist <= right_dist) {
		int dist = (left_dist + right_dist) / 2;
		int start = input[0];
		int router = 1;

		for (int i = 1; i < n; i++) {
			int end = input[i];
			if (end - start >= dist) {
				router++;
				start = end;
			}
		}

		if (router >= c) {
			result = dist;
			left_dist = dist + 1;
		}
		else {
			right_dist = dist - 1;
		}
	}

	return result;

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++) cin >> input[i];
	sort(input, input + n);
	cout << find();
	return 0;
}
