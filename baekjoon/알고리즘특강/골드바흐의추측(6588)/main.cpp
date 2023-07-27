#include <iostream>
#include <vector>
using namespace std;
#define m 1000000
int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);

	int a, b;
	bool map[m] = { 0, };
	vector<int> prime;

	for (int i = 3; i < m; i+=2) {
		if (map[i] == false) {
			prime.push_back(i);
			for (int j = 2; i * j < m; j++) {
				map[i*j] = true;
			}
		}
	}

	int n;
	int flag;

	for(int x = 0; x<100000; x++) {
		cin >> n;
		if (n == 0) break;
		else if (n % 2 == 0) {
			flag = 0;
			/*
			에라토스테네스의 체를 만들고 활용을 제대로 하지 못했다. 직접 접근하여 O(1)로 비교할 수 있는데
			while 투 포인터를 이용하여 탐색 시간을 증가시켰다... 
			int left = 0, right = prime.size() - 1;

			while (left <= right) {
				a = prime[left];
				b = prime[right];
				if (a + b == n) {
					
					flag = 1;
					break;
				}
				else if (a + b < n) left++;
				else right--;
			}
			*/
			for (int i = 0; i < prime.size(); i++) {
				if (map[n - prime[i]] == 0) {
					flag = 1;
					a = prime[i];
					b = n - prime[i];
					break;
				}
			}


			if (flag) cout << n << " = " << a << " + " << b << "\n";
			else cout << "Goldbach's conjecture is wrong.\n";
		}
		else {
			cout << "Goldbach's conjecture is wrong.\n";
		}


	}

	return 0;
}
