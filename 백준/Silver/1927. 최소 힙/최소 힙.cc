#include <iostream>
#include <queue>
using namespace std;
int n,a;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	priority_queue <int> pq;
	while (n--) {
		cin >> a;
		if (a != 0) pq.push(-a);
		else {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << -pq.top() << "\n";
				pq.pop();
			}

		}
	}
	return 0;
}	
