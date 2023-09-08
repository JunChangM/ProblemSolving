#include <iostream>
using namespace std;
long long n;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	long long level = 1;
	long long num = 1;
	while (n > num) {
		num += level * 6;
		level++;
	}
	cout << level;
    return 0;
}
/*
벌집의 모양 1 + 6 + 12 + 18 + 
*/