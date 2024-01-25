#include <iostream>
#include <string>
using namespace std;
int n, s;
string str;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	cin >> str;

	int ans = 0;
	for (int i = 0; i < s; i++) {
		int k = 0;
		if (str[i] == 'O') continue;

		while (str[i + 1] == 'O' && str[i + 2] == 'I'){
			k++;
			if (k == n) {
				k--; 
				ans++; // find
			}
			i += 2; // skip O
		}
		k = 0;
		
	}
	cout << ans;
	return 0;
}

