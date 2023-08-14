#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int i,idx, n, k, bag[300001];
long long answer;
pair<int, int> input[300001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k; // input
	for (i = 0; i < n; i++) cin >> input[i].first >> input[i].second;
	for (i = 0; i < k; i++) cin >> bag[i];
	sort(bag, bag + k);
	sort(input, input + n);
	priority_queue <int> pq;
	for (i = 0; i < k; i++) {
		int bagweight = bag[i];
		while (idx < n && input[idx].first <= bagweight) {
			pq.push(input[idx++].second);
		}
		if (!pq.empty()) {
			answer += pq.top();
			pq.pop();
		}
	}
	cout << answer;
	return 0;
}
/*
매번 찾으려고 할 경우 이중 for문으로 시간초과의 가능성이 있다.
priority queue를 통해 가방의 무게보다 작은 보석을 추가로 넣어가면서 상위 값만을 빼오면된다
*/