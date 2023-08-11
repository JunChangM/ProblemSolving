
/*
BY lastknight
* segment tree 의심
1. N이 10만 정도 나옴
2. 행위에 대하여 값이 update 되는 경우
3. 구간의 합 혹은 조회해라

N 개의 수, M 번 변경, K번 조회 => segment tree
a 가 1 이면 변경, 2이면 수까지의 합 출력

solved.ac 에서 segment tree 에서 레벨별로 쉬운 것부터 계속 segment tree 코딩하면서 암기하기.
*/

#include<iostream>
typedef long long ll;
using namespace std;
ll input[1000001], tree[4000002], c; // tree 번호를 백만으로 두는 이유는 넉넉하게 하기 위함.
int n, m, k, a, b;
// position * 2 = 왼쪽 자식 , position * 2 + 1 = 오른쪽 자식
ll init(int position, int left, int right) {
	if (left == right) { // leaf node 도달 시 값 넣기
		return tree[position] = input[left];
	}

	return tree[position] = init(position * 2, left, (left + right) / 2)
		+ init(position * 2 + 1, (left + right) / 2 + 1, right); // 해당 node 의 값은 아래 두 자식 노드의 합.
}
// position = node 번호, target = 바꾸려는 index , left  ~ right : 노드가 커버하는 범위
// target을 포함하는 index 범위의 값들을 update
void update(int position, int target, int left, int right, ll value) {
	if (target<left || target>right)return; // index가 범위 안에 포함되지 않는 경우 => 종료
	tree[position] += value; // 범위 안에 있으면 diff 만큼 더하기
	if (left != right) { // leaf 노드가 아니면 자식 노드 값 update 
		// 결론적으로 아래 update 중 target을 포함하고 있는 하나만 update가 된다.
		update(position * 2, target, left, (left + right) / 2, value);
		update(position * 2 + 1, target, (left + right) / 2 + 1, right, value);
	}
}
// left ~ right : 내가 구하길 원하는 범위
ll sum(int position, int start, int end, int left, ll right) {
	if (end<left || start>right)return 0; // 범위가 아예 벗어나는 경우는 0 반환
	if (left <= start && right >= end)return tree[position]; // 내가 원하는 left ~ right 범위가 start ~ end를 포함하는 경우 그 값을 반환
	return sum(position * 2, start, (start + end) / 2, left, right)
		+ sum(position * 2 + 1, (start + end) / 2 + 1, end, left, right); // 왼쪽 오른쪽 sum의 합 받아오기
}

int main() {
	// 입력이 많아 빠른 속도를 위해 필요함.
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	m += k;
	for (a = 1; a <= n; a++)cin >> input[a];
	init(1, 1, n);
	while (m--) {
		cin >> a >> b >> c;
		if (a & 1)update(1, b, 1, n, c - input[b]), input[b] = c;
		else cout << sum(1, 1, n, b, c) << "\n";
	}
}
