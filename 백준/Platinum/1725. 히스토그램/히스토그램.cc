#include <iostream>
#include <algorithm>
#define N 1000001
using namespace std;
int n;
long long input[N];
int tree[N * 4];
int init(int node, int start, int end) {
	if (start == end) return tree[node] = start;
	int mid = (start + end) / 2;
	int a = init(node * 2, start, mid);
	int b = init(node * 2 + 1, mid + 1, end);
	if (input[a] <= input[b]) return tree[node] = a;
	else return tree[node] = b;
}
 int find(int node, int start, int end, int left, int right) {
	if (right < start || end < left) return -1;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	int a = find(node * 2, start, mid, left, right);
	int b = find(node * 2 + 1, mid + 1, end, left, right);
	if (a == -1) return b;
	if (b == -1) return a;
	if (input[a] <= input[b]) return a;
	else return b;
}
long long solve(int left, int right){
	if (left > right) return -1;
	int leng = right - left + 1;
	int idx = find(1, 0, n - 1, left, right);
	long long temp = leng * input[idx];
	if (idx != left) temp = max(temp, solve(left, idx - 1));
	if (idx != right) temp = max(temp, solve(idx + 1, right));
	return temp;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> input[i];
	int l = 0, r = n - 1;
	init(1, 0, n-1);
	long long answer = solve(l, r);
	cout << answer;
	return 0;
}

/*
생성 N Log N
가능한 최대 높이 탐색 log N
경우의 수 => 분할 탐색, 높이가 제일 작은 값들로 쪼개가면서 탐색한다.
*/
