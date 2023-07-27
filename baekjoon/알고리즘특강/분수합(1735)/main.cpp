#include <iostream>
using namespace std;

// <numeric> 헤더에 gcd 와 lcm 존재
typedef long long ll;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	else if (a % b == 1) return 1;
	else return gcd(b, a%b); // 재귀 => 반환값 return 주의하자
}

ll lcm(int a, int b) {
	int value = gcd(a, b);
	return a / value * b;
}

int main() {
	int x1, x2, y1, y2, t1, t2;
	cin >> x1 >> y1 >> x2 >> y2;
	
	t1 = gcd(x1, y1);
	x1 /= t1;
	y1 /= t1;

	t2 = gcd(x2, y2);
	x2 /= t2;
	y2 /= t2;


	ll y = lcm(y1, y2);

	ll x = x1 * (y / y1) + x2 * (y / y2);

	ll t3 = gcd(x, y);
	x /= t3;
	y /= t3;

	cout << x << ' ' <<  y << endl;
}
/*
1. 각 문자마다 약분 (최대 공약수)
2. 분모의 최소 공배수
3. 계산 및 출력
*/
